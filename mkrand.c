#include <stdint.h>
#include <openssl/rand.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE* f = fopen(argv[1], "w");
	int filesize = atoi(argv[2]);
	void *randz = malloc(filesize);
	char chars[] = { '-', '\\', '|','/','-','\\','|','/' };
	int offset = 0;
	int i;
	RAND_bytes(randz, filesize);
	fwrite(randz, filesize, 1, f);
	fclose(f);
}