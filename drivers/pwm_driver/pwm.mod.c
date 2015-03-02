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
	{ 0x19e40e9, __VMLINUX_SYMBOL_STR(dev_warn) },
	{ 0xc38d54d1, __VMLINUX_SYMBOL_STR(devm_pinctrl_put) },
	{ 0xadaec9e7, __VMLINUX_SYMBOL_STR(sysfs_create_group) },
	{ 0xdac11bae, __VMLINUX_SYMBOL_STR(of_property_read_u32_array) },
	{ 0xc665d6d7, __VMLINUX_SYMBOL_STR(of_parse_phandle_with_args) },
	{ 0x263e2ab9, __VMLINUX_SYMBOL_STR(devm_pwm_get) },
	{ 0x62ab4085, __VMLINUX_SYMBOL_STR(dev_set_drvdata) },
	{ 0xeb6dbc53, __VMLINUX_SYMBOL_STR(devm_kmalloc) },
	{ 0xc7d4817f, __VMLINUX_SYMBOL_STR(pinctrl_select_state) },
	{ 0xc66bcab8, __VMLINUX_SYMBOL_STR(pinctrl_lookup_state) },
	{ 0xfbc320a7, __VMLINUX_SYMBOL_STR(devm_pinctrl_get) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x8106f615, __VMLINUX_SYMBOL_STR(pwm_enable) },
	{ 0x6ed8cdb1, __VMLINUX_SYMBOL_STR(pwm_set_polarity) },
	{ 0xc4aea01f, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x373db350, __VMLINUX_SYMBOL_STR(kstrtoint) },
	{ 0x6c852bbb, __VMLINUX_SYMBOL_STR(devm_pwm_put) },
	{ 0x3bf7911c, __VMLINUX_SYMBOL_STR(pwm_disable) },
	{ 0xe336e31f, __VMLINUX_SYMBOL_STR(pwm_config) },
	{ 0xb2b7c4e1, __VMLINUX_SYMBOL_STR(sysfs_remove_group) },
	{ 0x237e133a, __VMLINUX_SYMBOL_STR(dev_get_drvdata) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("of:N*T*Cpwm_test*");
