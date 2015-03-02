cd /usr/local/drivers/eqep_driver
insmod tieqep.ko
cd /usr/local/drivers/pwm_driver
insmod pwm.ko
config-pin P8.19 pwm

