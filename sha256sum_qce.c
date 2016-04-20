#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <linux/ioctl.h>	
#include <linux/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>		/* open */
#include <unistd.h>
#include <linux/random.h>
#include <linux/qcedev.h>

int main()
{
	FILE *meat = fopen("/mnt/sdcard/hashmeat", "r");
	int rndev = open("/dev/qce", 0);
	printf("Opened\n");
	struct qcedev_sha_op_req *req = malloc(sizeof(struct qcedev_sha_op_req));
	req->entries = 16;
	req->data_len = 16 * 6e7;
	req->alg = QCEDEV_ALG_SHA256;
	int i;
	for(i = 0; i < 16; i++)
	{
		req->data[i].vaddr=malloc(6e7);
		req->data[i].len=6e7;
	}
	
	int inited = 0;
	
	for(i = 0; i < 16; i++)
	{
		fread(req->data[i].vaddr, 1, 6e7, meat);
	}
	printf("Read, starting timer.\n");
	unsigned int timer = time(NULL);
	ioctl(rndev, QCEDEV_IOCTL_SHA_INIT_REQ, req);
	ioctl(rndev, QCEDEV_IOCTL_SHA_UPDATE_REQ, req);
	ioctl(rndev, QCEDEV_IOCTL_SHA_FINAL_REQ, req);
	printf("Done in %us\n", time(NULL)-timer);
	for(i = 0; i < 32; i++)
		printf("%02X", req->digest[i]);
	printf("\n");
}