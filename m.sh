#!/bin/bash
CR_DIR=$(pwd)
CR_KERNEL=$CR_DIR/arch/arm/boot/zImage
export CROSS_COMPILE=/home/m/kernel/arm-eabi-4.8/bin/arm-eabi-
export ARCH=arm

make mt6737t-grandpplte_defconfig
make -j4
cp $CR_KERNEL /home/m/CustomRom/superr_m/boot.img-zImage
cp $CR_KERNEL /home/m/CustomRom/superr_m/bootimg/split_img/boot.img-zImage
