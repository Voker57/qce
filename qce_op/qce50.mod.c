#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x5e4cb5ea, "module_layout" },
	{ 0xc981c2c1, "mem_map" },
	{ 0xc3468bc5, "sps_register_event" },
	{ 0x7c1372e8, "panic" },
	{ 0x4dbd2908, "_dev_info" },
	{ 0xa28300a1, "clk_set_rate" },
	{ 0xef6c70a6, "clk_get" },
	{ 0x55007e77, "platform_get_resource" },
	{ 0xa4bb0223, "platform_get_resource_byname" },
	{ 0x7865aa38, "of_property_read_u32_array" },
	{ 0x667b28ee, "of_find_property" },
	{ 0xcb5cf541, "sps_transfer_one" },
	{ 0x521445b, "list_del" },
	{ 0x9604584f, "sps_deregister_bam_device" },
	{ 0x8ac911c8, "sps_free_endpoint" },
	{ 0x58d81098, "sps_get_config" },
	{ 0xe8cff836, "sps_alloc_endpoint" },
	{ 0x760b6614, "kmalloc_caches" },
	{ 0x2c6ba30b, "mutex_unlock" },
	{ 0x343a1a8, "__list_add" },
	{ 0xc2165d85, "__arm_iounmap" },
	{ 0xe76c7542, "sps_register_bam_device" },
	{ 0x37a0cba, "kfree" },
	{ 0xfb961d14, "__arm_ioremap" },
	{ 0x62f5952c, "kmem_cache_alloc_trace" },
	{ 0xf087137d, "__dynamic_pr_debug" },
	{ 0x71f2037c, "mutex_lock" },
	{ 0x2e1ca751, "clk_put" },
	{ 0xcf60d6c0, "sps_disconnect" },
	{ 0xbe62a615, "sps_connect" },
	{ 0xe5183196, "clk_enable" },
	{ 0x935ead89, "clk_prepare" },
	{ 0x21889143, "clk_unprepare" },
	{ 0x8fd10e31, "clk_disable" },
	{ 0x70550ec8, "arm_dma_ops" },
	{ 0xd5152710, "sg_next" },
	{ 0x3e92496d, "page_address" },
	{ 0x10cbd8b9, "uncached_logk" },
	{ 0x15b94dea, "sps_transfer" },
	{ 0x27e1a049, "printk" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x5f754e5a, "memset" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

