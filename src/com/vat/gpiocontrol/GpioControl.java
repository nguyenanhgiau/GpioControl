package com.vat.gpiocontrol;

public class GpioControl {
	static  {
		System.loadLibrary("gpio-control-jni");
    }
		public static native int SetLeftLed(boolean enable);
		public static native int SetRightLed(boolean enable);
		
}
