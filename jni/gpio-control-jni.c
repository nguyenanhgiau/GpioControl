#include <jni.h>
#include "../hal/gpio-control-hal.h"

jint JNICALL Java_com_vat_gpiocontrol_GpioControl_SetLeftLed(JNIEnv * a, jclass b	, jboolean enable) {
	set_gpio(LED_LEFT, enable ? 1:0);
	return 0;
}

jint JNICALL Java_com_vat_gpiocontrol_GpioControl_SetRightLed(JNIEnv * a, jclass b, jboolean enable) {
	set_gpio(LED_RIGHT, enable ? 1:0);
	return 0;
}



