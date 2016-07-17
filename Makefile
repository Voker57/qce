TOOLCHAIN=/home/voker57/cross
PREFIX=$(TOOLCHAIN)/bin/arm-linux-gnueabihf-
CC=$(PREFIX)gcc
KERNEL_DIR=/home/voker57/Sources/linux
M=$(shell pwd)
CFLAGS += -fno-pic -static -O3 -std=c99 -Wall -Wextra -Wfatal-errors 
#-I $(KERNEL_DIR)/include

obj-m := mymodule.o
PWD := $(shell pwd)
iotest: iotest.c
	$(CC) -std=c99 -Wall -Wextra -Wfatal-errors -I kernel_obj/usr/include -I kernel_obj/include -I kernel_obj/ iotest.c -o iotest

sha256sum_qce: sha256sum_qce.c
	$(CC) -std=c99 -Wall -Wextra -Wfatal-errors -I kernel_obj/usr/include -I kernel_obj/include -I kernel_obj/ sha256sum_qce.c -o sha256sum_qce

sha: sha.c sha.h
	$(CC) -std=c99 -Wall -Wextra -Wfatal-errors -I kernel_obj/usr/include -I kernel_obj/include -I kernel_obj/ sha.c -o sha
	
aes_qce: aes_qce.c
	$(CC) -std=c99 -Wall -Wextra -Wfatal-errors -I kernel_obj/usr/include -I kernel_obj/include -I kernel_obj/ aes_qce.c -o aes_qce
	
sha256sum_cryptodev: sha256sum_cryptodev.c
	$(CC) $(CFLAGS) sha256sum_cryptodev.c -o sha256sum_cryptodev
	
sha1sum_cryptodev: sha1sum_cryptodev.c
	$(CC) $(CFLAGS) sha1sum_cryptodev.c -o sha1sum_cryptodev

aes_cryptodev: aes_cryptodev.c
	$(CC) -std=c99 -Wall -Wextra -Wfatal-errors -I kernel_obj/usr/include -I kernel_obj/include -I kernel_obj/ aes_cryptodev.c -o aes_cryptodev

cryptodev_aes: cryptodev_aes.c
	$(CC) -std=c99 -Wall -Wextra -Wfatal-errors -I kernel_obj/usr/include -I kernel_obj/include -I kernel_obj/ cryptodev_aes.c -o cryptodev_aes
	
clean:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD) clean

sha256sum: sha256sum.c
	$(CC) $(CFLAGS) sha256sum.c -o sha256sum
	
aes_soft: aes_soft.c aes.h aes.c
	$(CC) -O3 -std=c99 -Wall -Wextra -Wfatal-errors aes_soft.c -o aes_soft

mkrand: mkrand.c
	$(CC) $(CFLAGS) mkrand.c -o mkrand

b64: b64.c
	$(CC) $(CFLAGS) b64.c -o b64

	
