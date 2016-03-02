#include <linux/ioctl.h>	
// #include <sys/ioctl.h>
#include <linux/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>		/* open */
#include <unistd.h>
#include <linux/random.h>
#include <linux/qcedev.h>

int main()
{
	
	uint8_t *dat = malloc(8);
	dat[0] = 5;
	struct buf_info dats = {.vaddr = dat, .len = 8};
	struct qcedev_sha_op_req *req = malloc(sizeof(struct qcedev_sha_op_req));
	memcpy(req->data, &dats, sizeof(struct buf_info));
	req->entries = 1;
	req->data_len = 8;
	req->alg = QCEDEV_ALG_SHA256;
	printf("Ok...\n");
	int rndev = open("/dev/qce", 0);
	printf("Opened\n");
	ioctl(rndev, QCEDEV_IOCTL_SHA_INIT_REQ, req);
	ioctl(rndev, QCEDEV_IOCTL_SHA_UPDATE_REQ, req);
	ioctl(rndev, QCEDEV_IOCTL_SHA_FINAL_REQ, req);
	printf("%d\n", req->digest[0]);
	free(req);
}