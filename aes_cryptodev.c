#include "aes-gcm.c"

int
main()
{
	int cfd = -1, i;
	struct cryptodev_ctx ctx;
	uint8_t *text = malloc(4.8e8);
	uint8_t *out = malloc(4.8e8);
	FILE *meat = fopen("/mnt/sdcard/hashmeat", "r");
	size_t count = fread(text, 1, 4.8e8, meat);

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
	printf("Read, starting timer.\n");
	unsigned int timer = time(NULL);
	uint8_t *key = malloc(32);
	memset(key, 0xda, 32);
	uint8_t *iv = malloc(16);
	memset(iv, 0xda, 16);
	aes_gcm_ctx_init(&ctx, cfd, key, 32);
	printf("inited");
	aes_gcm_encrypt(&ctx, iv, key, 32, text, out, 4.8e8);
	for (i = 0; i < 32; i++) {
		printf("%02x:",out[i]);
	}
	printf("\n");

	/* Close the original descriptor */
	if (close(cfd)) {
		perror("close(cfd)");
		return 1;
	}

	return 0;
}