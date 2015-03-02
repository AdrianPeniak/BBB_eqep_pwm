#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
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
	{ 0x52eae5ec, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xc3e22d46, __VMLINUX_SYMBOL_STR(platform_driver_unregister) },
	{ 0xb7d82577, __VMLINUX_SYMBOL_STR(__platform_driver_register) },
	{ 0xc4aea01f, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x19e40e9, __VMLINUX_SYMBOL_STR(dev_warn) },
	{ 0xc38d54d1, __VMLINUX_SYMBOL_STR(devm_pinctrl_put) },
	{ 0x62ab4085, __VMLINUX_SYMBOL_STR(dev_set_drvdata) },
	{ 0xc3f49fd5, __VMLINUX_SYMBOL_STR(pm_runtime_enable) },
	{ 0xdac11bae, __VMLINUX_SYMBOL_STR(of_property_read_u32_array) },
	{ 0xadaec9e7, __VMLINUX_SYMBOL_STR(sysfs_create_group) },
	{ 0xd6b8e852, __VMLINUX_SYMBOL_STR(request_threaded_irq) },
	{ 0x7a18653d, __VMLINUX_SYMBOL_STR(devm_request_and_ioremap) },
	{ 0x875076ea, __VMLINUX_SYMBOL_STR(platform_get_resource) },
	{ 0xb3e37e91, __VMLINUX_SYMBOL_STR(clk_get_rate) },
	{ 0x56dadcd3, __VMLINUX_SYMBOL_STR(devm_clk_get) },
	{ 0xeb6dbc53, __VMLINUX_SYMBOL_STR(devm_kmalloc) },
	{ 0xc7d4817f, __VMLINUX_SYMBOL_STR(pinctrl_select_state) },
	{ 0xc66bcab8, __VMLINUX_SYMBOL_STR(pinctrl_lookup_state) },
	{ 0xfbc320a7, __VMLINUX_SYMBOL_STR(devm_pinctrl_get) },
	{ 0xb2d48a2e, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0x2d3385d3, __VMLINUX_SYMBOL_STR(system_wq) },
	{ 0xc69b0a2, __VMLINUX_SYMBOL_STR(__pm_runtime_disable) },
	{ 0x2e99d701, __VMLINUX_SYMBOL_STR(pwmss_submodule_state_change) },
	{ 0xf20dabd8, __VMLINUX_SYMBOL_STR(free_irq) },
	{ 0xb2b7c4e1, __VMLINUX_SYMBOL_STR(sysfs_remove_group) },
	{ 0x4205ad24, __VMLINUX_SYMBOL_STR(cancel_work_sync) },
	{ 0x373db350, __VMLINUX_SYMBOL_STR(kstrtoint) },
	{ 0x59e5070d, __VMLINUX_SYMBOL_STR(__do_div64) },
	{ 0x60ea2d6, __VMLINUX_SYMBOL_STR(kstrtoull) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x5a5a94a6, __VMLINUX_SYMBOL_STR(kstrtou8) },
	{ 0x74cc097c, __VMLINUX_SYMBOL_STR(__pm_runtime_idle) },
	{ 0x4d47a740, __VMLINUX_SYMBOL_STR(__pm_runtime_resume) },
	{ 0xac8f37b2, __VMLINUX_SYMBOL_STR(outer_cache) },
	{ 0x237e133a, __VMLINUX_SYMBOL_STR(dev_get_drvdata) },
	{ 0x9f7dacaf, __VMLINUX_SYMBOL_STR(sysfs_notify) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("of:N*T*Cti,am33xx-eqep*");
