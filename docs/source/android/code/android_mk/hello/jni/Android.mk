LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE    := foo
LOCAL_SRC_FILES := foo.cc
# include $(BUILD_SHARED_LIBRARY)
include $(BUILD_EXECUTABLE)