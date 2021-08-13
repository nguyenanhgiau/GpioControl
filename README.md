# Building Android App Control Gpio
## General Notes
This instruction will help you understand how to access hardware layer from application layer.<br>
Prerequisites:<br>
- You have to build AOSP for rpi4 before go to this instruction
- LEDs, a breadboard and some buses
- You also need some ingredient, download it at HERE.

First of all, you need to know about:
- [Platform Architecture](https://developer.android.com/guide/platform)
- [Android Architecture](https://source.android.com/devices/architecture)

## 0-Clone kernel source code
```bash
mkdir kernelS && cd kernelS
repo init -u https://github.com/android-rpi/kernel_manifest -b arpi-5.10
repo sync
```
## 1-Building LED Driver
Thanks a lot to EmbeTronicX for [LED driver](https://embetronicx.com/tutorials/linux/device-drivers/gpio-driver-basic-using-raspberry-pi/)
### Integrate LED driver to kernel
Create $AOSP/common/drivers/leds/leds-rpi4-demo.c file with content as [this file](https://github.com/Embetronicx/Tutorials/blob/master/Linux/Device_Driver/GPIO-in-Linux-Device-Driver/driver.c)

Apply the below patch to $AOSP/common/ to integrate your driver.
```patch
diff --git a/arch/arm64/configs/bcm2711_defconfig b/arch/arm64/configs/bcm2711_defconfig
index 43f7f80a015f..8bc9d1c73865 100644
--- a/arch/arm64/configs/bcm2711_defconfig
+++ b/arch/arm64/configs/bcm2711_defconfig
@@ -1260,6 +1260,7 @@ CONFIG_MMC_SPI=m
 CONFIG_LEDS_CLASS=y
 CONFIG_LEDS_PCA9532=m
 CONFIG_LEDS_GPIO=y
+CONFIG_LEDS_RPI4_DEMO=y
 CONFIG_LEDS_PCA955X=m
 CONFIG_LEDS_PCA963X=m
 CONFIG_LEDS_IS31FL32XX=m
diff --git a/drivers/leds/Kconfig b/drivers/leds/Kconfig
index 1988de1d64c0..f092cde74693 100644
--- a/drivers/leds/Kconfig
+++ b/drivers/leds/Kconfig
@@ -315,6 +315,15 @@ config LEDS_GPIO
          defined as platform devices and/or OpenFirmware platform devices.
          The code to use these bindings can be selected below.
 
+config LEDS_RPI4_DEMO
+       tristate "LED Support for GPIO RPI4 connected LEDs"
+       help
+         This option enables support for the LEDs connected to GPIO
+         outputs. To be useful the particular board must have LEDs
+         and they must be connected to the GPIO lines.  The LEDs must be
+         defined as platform devices and/or OpenFirmware platform devices.
+         The code to use these bindings can be selected below.
+
 config LEDS_LP3944
        tristate "LED Support for N.S. LP3944 (Fun Light) I2C chip"
        depends on LEDS_CLASS
diff --git a/drivers/leds/Makefile b/drivers/leds/Makefile
index 41fb073a39c1..9c67ae07082d 100644
--- a/drivers/leds/Makefile
+++ b/drivers/leds/Makefile
@@ -31,6 +31,7 @@ obj-$(CONFIG_LEDS_SUNFIRE)            += leds-sunfire.o
 obj-$(CONFIG_LEDS_PCA9532)             += leds-pca9532.o
 obj-$(CONFIG_LEDS_GPIO_REGISTER)       += leds-gpio-register.o
 obj-$(CONFIG_LEDS_GPIO)                        += leds-gpio.o
+obj-$(CONFIG_LEDS_RPI4_DEMO)   += leds-rpi4-demo.o
 obj-$(CONFIG_LEDS_LP3944)              += leds-lp3944.o
 obj-$(CONFIG_LEDS_LP3952)              += leds-lp3952.o
 obj-$(CONFIG_LEDS_LP55XX_COMMON)       += leds-lp55xx-common.o
```
As you can see, this driver will be loaded with the system.

### Rebuild kernel
```bash
cd kernelS
build/build.sh
```
After building, you are able to flash or package this image.


**Thank you so much to VAT for this knowledge!!!**<br>
**HAVE FUN!**
