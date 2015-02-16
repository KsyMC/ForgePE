LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := substrate
LOCAL_SRC_FILES := libsubstrate.so

include $(PREBUILT_SHARED_LIBRARY)


include $(CLEAR_VARS)

LOCAL_MODULE    := forgepe
LOCAL_SRC_FILES := forgepe.cpp \
    Mod.cpp

LOCAL_LDLIBS    := -L$(LOCAL_PATH) -ldl -llog -lsubstrate

include $(BUILD_SHARED_LIBRARY)
