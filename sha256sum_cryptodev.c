
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "cryptodev.h"
#include "sha256.h"
#include "sha256.c"
#include "cryptodev_sha.h"

int
main(int argc, char *argv[])
{
	int cfd = -1, i;
	struct cryptodev_ctx ctx;
	uint8_t digest[32];
	int f = 0;
	int size;
	uint8_t *dat;
	uint8_t *dat_cursor;
	int file_size = 9e8;
	int left_size, argi;
	int batch;
	unsigned int timer;
	
	dat = malloc(file_size);
	f = open("/meat", O_RDONLY, 0);
	if (f < 0) {
		perror("open(/test)");
		return 1;
	}
	
	/* Open the crypto device */
	cfd = open("/dev/crypto", O_RDWR, 0);
	if (cfd < 0) {
		perror("open(/dev/crypto)");
		return 1;
	}

	/* Set close-on-exec (not really neede here) */
	if (fcntl(cfd, F_SETFD, 1) == -1) {
		perror("fcntl(F_SETFD)");
		return 1;
	}
	
sha_ctx_init(&ctx, cfd, NULL, 0);

	size = read(f, dat, file_size);
	if(!size)
		return -1;
	srand(time(NULL));
	left_size = size;
	dat_cursor = dat;
	printf("Read, starting timer.\n");
	timer = time(NULL);
	for(argi = 1; argi < argc; argi++) {
		batch = atoi(argv[argi]);
		if(left_size < batch)
			batch = left_size;
		printf("batch = %d;\n", batch);
		sha_update(&ctx, dat_cursor, batch, digest);
		dat_cursor += batch;
		left_size -= batch;
 	}
	sha_final(&ctx, digest);
	printf("Done in %us\n", time(NULL)-timer);
	
	sha_ctx_deinit(&ctx);

	
	for (i = 0; i < 32; i++) {
		printf("%02x", digest[i]);
	}

	
	/* Close the original descriptor */
	if (close(cfd)) {
		perror("close(cfd)");
		return 1;
	}
	
	printf("\nPure CPU hashing.\n");

	SHA256_CTX ctxx;
	sha256_init(&ctxx);
	timer = time(NULL);
	
	sha256_update(&ctxx, dat, dat_cursor-dat);
	sha256_final(&ctxx, digest);

	printf("Done in %us\n", time(NULL)-timer);
	
	for (i = 0; i < 32; i++) {
		printf("%02x", digest[i]);
	}
	printf("\n");
	free(dat);
	
	return 0;
}
