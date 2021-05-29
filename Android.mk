LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional
LOCAL_MODULE    := libgpio-control-jni
LOCAL_SRC_FILES := jni/gpio-control-jni.c
LOCAL_SHARED_LIBRARIES := libgpio-control-hal

LOCAL_CFLAGS += -Wall -Wextra -Werror -Wno-unused-parameter

include $(BUILD_SHARED_LIBRARY)


include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(call all-java-files-under, src)
LOCAL_SHARED_LIBRARIES := libgpio-control-jni
#Includes library inside APK
LOCAL_JNI_SHARED_LIBRARIES := libgpio-control-jni
LOCAL_PACKAGE_NAME := GpioControl
LOCAL_SDK_VERSION := current
LOCAL_CERTIFICATE := platform
LOCAL_PRIVILEGED_MODULE := true

include $(BUILD_PACKAGE)

include $(call all-makefiles-under, $(LOCAL_PATH))
