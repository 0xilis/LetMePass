ARCHS = armv7 arm64 arm64e
TARGET = iphone:clang:14.8.1:10.0
PREFIX = $(THEOS)/toolchain/Xcode.xctoolchain/usr/bin/
# PREFIX = /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/
SYSROOT = $(THEOS)/sdks/iPhoneOS14.5.sdk


include $(THEOS)/makefiles/common.mk

TWEAK_NAME = LetMePass

LetMePass_FILES = dylib.c
LetMePass_CFLAGS = -nostdlib # Not used
LetMePass_LDFLAGS = -lobjc
LetMePass_USE_SUBSTRATE = 0
LetMePass_LOGOS_DEFAULT_GENERATOR = internal

include $(THEOS_MAKE_PATH)/tweak.mk
