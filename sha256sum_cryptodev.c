#include <stdint.h>
#include "cryptodev.h"

struct cryptodev_ctx {
	int cfd;
	struct session_op sess;
	uint16_t alignmask;
};


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>


int sha_ctx_init(struct cryptodev_ctx* ctx, int cfd, const uint8_t *key, unsigned int key_size)
{
#ifdef CIOCGSESSINFO
	struct session_info_op siop;
#endif

	memset(ctx, 0, sizeof(*ctx));
	ctx->cfd = cfd;

	if (key == NULL)
		ctx->sess.mac = CRYPTO_SHA2_256;
	else {
		ctx->sess.mac = CRYPTO_SHA1_HMAC;
		ctx->sess.mackeylen = key_size;
		ctx->sess.mackey = (void*)key;
	}
	if (ioctl(ctx->cfd, CIOCGSESSION, &ctx->sess)) {
		perror("ioctl(CIOCGSESSION)");
		return -1;
	}

#ifdef CIOCGSESSINFO
	siop.ses = ctx->sess.ses;
	if (ioctl(ctx->cfd, CIOCGSESSINFO, &siop)) {
		perror("ioctl(CIOCGSESSINFO)");
		return -1;
	}
	printf("Got %s with driver %s\n",
			siop.hash_info.cra_name, siop.hash_info.cra_driver_name);
	if (!(siop.flags & SIOP_FLAG_KERNEL_DRIVER_ONLY)) {
		printf("Note: This is not an accelerated cipher\n");
	}
	/*printf("Alignmask is %x\n", (unsigned int)siop.alignmask);*/
	ctx->alignmask = siop.alignmask;
#endif
	return 0;
}

void sha_ctx_deinit(struct cryptodev_ctx* ctx) 
{
	printf("deiniting\n");
	if (ioctl(ctx->cfd, CIOCFSESSION, &ctx->sess.ses)) {
		perror("ioctl(CIOCFSESSION)");
		return -1;
	} else
	printf("everything was ok");
}

int
sha_hash(struct cryptodev_ctx* ctx, const void* text, size_t size, void* digest)
{
	struct crypt_op cryp;
	void* p;
	
	/* check text and ciphertext alignment */
	if (ctx->alignmask) {
		p = (void*)(((unsigned long)text + ctx->alignmask) & ~ctx->alignmask);
		if (text != p) {
			fprintf(stderr, "text is not aligned\n");
			return -1;
		}
	}

	memset(&cryp, 0, sizeof(cryp));

	/* Encrypt data.in to data.encrypted */
	cryp.ses = ctx->sess.ses;
	cryp.len = size;
	cryp.src = (void*)text;
	cryp.mac = digest;
	if (ioctl(ctx->cfd, CIOCCRYPT, &cryp)) {
		perror("ioctl(CIOCCRYPT)");
		return -1;
	}

	return 0;
}

int
main()
{
	int cfd = -1, i;
	struct cryptodev_ctx ctx;
	uint8_t *text = malloc(9.6e8);
	uint8_t digest[32];
	FILE *meat = fopen("/mnt/sdcard/hashmeat", "r");
	size_t count = fread(text, 1, 9.6e8, meat);

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
	sha_ctx_init(&ctx, cfd, NULL, 0);
	printf("hashing\n");
	sha_hash(&ctx, text, count, digest);
	printf("hashed.\n");
	sha_ctx_deinit(&ctx);
	printf("Done in %us\n", time(NULL)-timer);
	printf("digest:\n");
	for (i = 0; i < 32; i++) {
		printf("%02x:", digest[i]);
	}
	printf("\n");

	/* Close the original descriptor */
	if (close(cfd)) {
		perror("close(cfd)");
		return 1;
	}

	return 0;
}