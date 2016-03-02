TOOLCHAIN=/home/voker57/projects/ass/toolchain
KERNEL_DIR=/home/voker57/projects/ass/kernel

obj-m := hello.o
PWD := $(shell pwd)
iotest: iotest.c
	$(TOOLCHAIN)/bin/arm-linux-androideabi-gcc -std=c99 -Wall -Wextra -Wfatal-errors -I kernel_obj/usr/include -I kernel_obj/include -I kernel_obj/ iotest.c -o iotest
default:
	$(MAKE) ARCH=arm CROSS_COMPILE=$(TOOLCHAIN)/bin/arm-linux-androideabi- -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD) clean
