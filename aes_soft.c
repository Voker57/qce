#include "aes.h"
#include "aes.c"

int main()
{
	FILE *meat = fopen("/mnt/sdcard/hashmeat", "r");
	uint8_t *buffer=malloc(48e7);
	uint8_t *out=malloc(48e7);
	size_t count = fread(buffer, 1, 48e7, meat);
	printf("%u bytes read\n", count);
	int i;
	for(i = 0; i < 32; i++)
		printf("%02X", buffer[i]);
	printf("Read, starting timer.\n");
	unsigned int timer = time(NULL);
	uint8_t *key = malloc(32);
	memset(key, 0xda, 32);
	uint8_t *iv = malloc(16);
	memset(iv, 0xda, 16);
	aes_encrypt_cbc(buffer, 48e7, out, key, 64, iv);
	printf("Done in %us\n", time(NULL)-timer);
	
	for(i = 0; i < 32; i++)
		printf("%02X", out[i]);
	printf("\n");
}