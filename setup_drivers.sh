chmod +x bb-get-rcn-kernel-source.sh
sudo ./bb-get-rcn-kernel-source.sh
cd drivers/eqep_driver
make
insmod tieqep.ko
cd ../pwm_driver
make
insmod pwm_test.ko
cd ../..
cp -r drivers/ /usr/local/.


