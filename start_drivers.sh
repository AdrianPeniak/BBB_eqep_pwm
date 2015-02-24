cd drivers/eqep_driver
insmod tieqep.ko
cd ../pwm_driver
insmod pwm.ko
config-pin P8.19 pwm
