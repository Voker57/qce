#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x5e4cb5ea, "module_layout" },
	{ 0xd037fb29, "crypto_nivaead_type" },
	{ 0xbc95d7b6, "crypto_aead_type" },
	{ 0xd0638676, "crypto_ahash_type" },
	{ 0x1d29f568, "crypto_ablkcipher_type" },
	{ 0x86e0edeb, "platform_driver_unregister" },
	{ 0xf087137d, "__dynamic_pr_debug" },
	{ 0x795d6ef0, "platform_driver_register" },
	{ 0x75b2242a, "__mutex_init" },
	{ 0x5083fed, "__raw_spin_lock_init" },
	{ 0xa6f79779, "debugfs_remove_recursive" },
	{ 0xa95e20a3, "debugfs_create_file" },
	{ 0x989f5072, "debugfs_create_dir" },
	{ 0x306ff007, "dev_warn" },
	{ 0x7d11c268, "jiffies" },
	{ 0x8834396c, "mod_timer" },
	{ 0x3bd1b1f6, "msecs_to_jiffies" },
	{ 0xb344e274, "wait_for_completion_interruptible" },
	{ 0x34beed5c, "crypto_enqueue_request" },
	{ 0x75b45b18, "qce_process_sha_req" },
	{ 0xd30ea922, "crypto_dequeue_request" },
	{ 0x1437bc5e, "qce_aead_req" },
	{ 0xc981c2c1, "mem_map" },
	{ 0x103c9c3e, "qce_ablk_cipher_req" },
	{ 0x1424f59, "sg_copy_to_buffer" },
	{ 0x71c90087, "memcmp" },
	{ 0x91dda801, "scatterwalk_map_and_copy" },
	{ 0x8371daff, "sg_copy_from_buffer" },
	{ 0x4a9bd9dd, "crypto_register_ahash" },
	{ 0x4dbd2908, "_dev_info" },
	{ 0xf27b6a21, "dev_err" },
	{ 0xde32b74e, "crypto_register_alg" },
	{ 0x97255bdf, "strlen" },
	{ 0x7ded90b3, "msm_bus_scale_register_client" },
	{ 0xda89b2d5, "msm_bus_cl_get_pdata" },
	{ 0x343a1a8, "__list_add" },
	{ 0x499043d3, "crypto_init_queue" },
	{ 0x9545af6d, "tasklet_init" },
	{ 0xfb0e29f, "init_timer_key" },
	{ 0x7dd3946, "dev_set_drvdata" },
	{ 0x741881f, "qce_open" },
	{ 0x760b6614, "kmalloc_caches" },
	{ 0x62f5952c, "kmem_cache_alloc_trace" },
	{ 0xcfd9a2c0, "des_ekey" },
	{ 0xdfabe0ff, "scm_call" },
	{ 0xf9318674, "__init_waitqueue_head" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0x528c709d, "simple_read_from_buffer" },
	{ 0xb81960ca, "snprintf" },
	{ 0xf9e73082, "scnprintf" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x73e20c1c, "strlcpy" },
	{ 0xdd0a2ba2, "strlcat" },
	{ 0x5f754e5a, "memset" },
	{ 0x6ed0e230, "complete" },
	{ 0xfaef0ed, "__tasklet_schedule" },
	{ 0xca54fee, "_test_and_set_bit" },
	{ 0x37a0cba, "kfree" },
	{ 0x9d669763, "memcpy" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x79aa04a2, "get_random_bytes" },
	{ 0x575c81e1, "qce_close" },
	{ 0x2c6ba30b, "mutex_unlock" },
	{ 0x71f2037c, "mutex_lock" },
	{ 0x76fc1bb6, "crypto_unregister_ahash" },
	{ 0xcfe81f08, "crypto_unregister_alg" },
	{ 0xcf8cc5ee, "msm_bus_scale_unregister_client" },
	{ 0x71144b18, "device_init_wakeup" },
	{ 0x4205ad24, "cancel_work_sync" },
	{ 0x82072614, "tasklet_kill" },
	{ 0x521445b, "list_del" },
	{ 0x7a4497db, "kzfree" },
	{ 0xd5f2172f, "del_timer_sync" },
	{ 0x8585252c, "pm_relax" },
	{ 0x81a61e31, "qce_disable_clk" },
	{ 0x78f062cb, "msm_bus_scale_client_update_request" },
	{ 0xd26f8cb, "qce_enable_clk" },
	{ 0x1856717e, "pm_stay_awake" },
	{ 0x8949858b, "schedule_work" },
	{ 0xb6f33b5e, "dev_get_drvdata" },
	{ 0x9cd9dce, "_raw_spin_unlock_irqrestore" },
	{ 0x56f31e92, "_raw_spin_lock_irqsave" },
	{ 0x27e1a049, "printk" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

