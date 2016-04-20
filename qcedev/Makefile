TOOLCHAIN=/home/voker57/projects/ass/toolchain
KERNEL_DIR=/home/voker57/projects/ass/kernel_obj
CC=$(TOOLCHAIN)/bin/arm-linux-androideabi-gcc

obj-m := testmodule.o
PWD := $(shell pwd)

default:
	$(MAKE) ARCH=arm CROSS_COMPILE=$(TOOLCHAIN)/bin/arm-linux-androideabi- -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules
