TOOLCHAIN=/home/voker57/projects/ass/toolchain
KERNEL_DIR=/home/voker57/projects/ass/kernel_obj
CC=$(TOOLCHAIN)/bin/arm-linux-androideabi-gcc
M=$(shell pwd)
KBUILD_CFLAGS += -fno-pic

# CC=gcc

PWD := $(shell pwd)


obj-m += qce50.o

# 		obj-$(CONFIG_CRYPTO_DEV_QCE) += qce40.o

# 		obj-$(CONFIG_CRYPTO_DEV_QCE) += qce.o

# ifeq ($(CONFIG_FIPS_ENABLE), y)
# 	obj-$(CONFIG_CRYPTO_DEV_QCRYPTO) += qcrypto_fips.o
# endif
obj-m += qcrypto.o
# obj-$(CONFIG_CRYPTO_DEV_OTA_CRYPTO) += ota_crypto.o


default:
	$(MAKE) ARCH=arm CROSS_COMPILE=$(TOOLCHAIN)/bin/arm-linux-androideabi- -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules

clean:
	$(MAKE) ARCH=arm CROSS_COMPILE=$(TOOLCHAIN)/bin/arm-linux-androideabi- -C $(KERNEL_DIR) SUBDIRS=$(PWD) clean



