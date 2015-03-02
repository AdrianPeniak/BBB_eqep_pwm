git clone https://github.com/RobertCNelson/dtb-rebuilder
cd dtb-rebuilder
git checkout 3.14-ti
cd ..
cp -r device_tree_files/. dtb-rebuilder/src/arm/.
cd dtb-rebuilder
make
make install

echo "ADD dtb=am335x-beaglebone-cape-bone-robot.dtb TO THE uENV.TXT FILE in /boot/"

