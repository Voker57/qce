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
#include <linux/qcedev.h>

int main()
{
	FILE *meat = fopen("/mnt/sdcard/hashmeat", "r");
	int rndev = open("/dev/qce", 0);
	printf("Opened\n");
	struct qcedev_cipher_op_req *req = malloc(sizeof(struct qcedev_cipher_op_req));
	memset(req, 0, sizeof(struct qcedev_cipher_op_req));
	memset(req->enckey, 0xda, 32);
	req->encklen = 32;
 	memset(req->iv, 0xda, 16);
	req->ivlen = 16;
	req->alg = QCEDEV_ALG_AES;
	req->mode = QCEDEV_AES_MODE_CBC;
	req->op = QCEDEV_OPER_ENC;
	req->in_place_op = 1;
	req->entries = 8;
	req->data_len = 8 * 6e7;
	req->alg = QCEDEV_ALG_SHA256;
	int i;
	for(i = 0; i < 8; i++)
	{
		req->vbuf.src[i].vaddr=malloc(6e7);
		req->vbuf.src[i].len=6e7;
		req->vbuf.dst[i] = req->vbuf.src[i];
		size_t count = fread(req->vbuf.src[i].vaddr, 1, 6e7, meat);
		printf("%u bytes read\n", count);
	}
	
	for(i = 0; i < 32; i++)
		printf("%02X", req->vbuf.src[0].vaddr[i]);
	
	printf("Read, starting timer.\n");
	unsigned int timer = time(NULL);
	ioctl(rndev, QCEDEV_IOCTL_ENC_REQ, req);
	printf("Done in %us\n", time(NULL)-timer);
	for(i = 0; i < 32; i++)
		printf("%02X", req->vbuf.dst[0].vaddr[i]);
	printf("\n");
}