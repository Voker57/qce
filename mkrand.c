#include <stdint.h>
#include <stdio.h>

unsigned seed = 0;

int rand()
{
	if(seed==0)
		seed = time(NULL);
  seed = (1103515245 * seed + 12345) % 4294967296;
  return seed;
}

int main(int argc, char *argv[])
{
	FILE* f = fopen("/meat", "w");
	char chars[] = { '-', '\\', '|','/','-','\\','|','/' };
	int offset = 0;
	int i;
	unsigned *rbytes = malloc(sizeof(unsigned));
	
	for(i=0; i < 9e8 / 4; i++)
	{
		*rbytes = rand();
		fwrite(rbytes, sizeof(unsigned), 1, f);
		if (i % 1000000 == 0) {
			printf("\r%d       ", (int)(i / (9e8/4) * 100));
			fflush(stdout);
		}
	}
	fclose(f);
}
