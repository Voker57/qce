#include <stdint.h>
#include "sha256.h"
#include "sha256.c"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>

int main()
{
	SHA256_CTX ctx;
	sha256_init(&ctx);
	FILE *meat = fopen("/mnt/sdcard/hashmeat", "r");
	uint8_t *buffer=malloc(96e7);
	size_t count = fread(buffer, 1, 96e7, meat);
	printf("Read, starting timer.\n");
	unsigned int timer = time(NULL);
	sha256_update(&ctx, buffer, count);
	sha256_final(&ctx, buffer);
	printf("Done in %us\n", time(NULL)-timer);
	int i;
	for(i = 0; i < 32; i++)
		printf("%02X", buffer[i]);
	printf("\n");
}