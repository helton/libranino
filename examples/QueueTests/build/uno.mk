ifeq ($(OS),Windows_NT)
SHELL = $(ComSpec)
RMDIR = rmdir /s /q
mymkdir = if not exist "$1" mkdir "$1"
else
RMDIR = rm -fr
mymkdir = mkdir -p $1
endif

PROJECT_OBJS = \
	uno/project/QueueTests.cpp.o \

PLATFORM_OBJS = \
	uno/platform/cores/arduino/HardwareSerial2.cpp.o \
	uno/platform/cores/arduino/HardwareSerial0.cpp.o \
	uno/platform/cores/arduino/IPAddress.cpp.o \
	uno/platform/cores/arduino/WMath.cpp.o \
	uno/platform/cores/arduino/PluggableUSB.cpp.o \
	uno/platform/cores/arduino/WString.cpp.o \
	uno/platform/cores/arduino/wiring_shift.c.o \
	uno/platform/cores/arduino/abi.cpp.o \
	uno/platform/cores/arduino/CDC.cpp.o \
	uno/platform/cores/arduino/wiring_pulse.c.o \
	uno/platform/cores/arduino/wiring_pulse.S.o \
	uno/platform/cores/arduino/HardwareSerial1.cpp.o \
	uno/platform/cores/arduino/Stream.cpp.o \
	uno/platform/cores/arduino/wiring.c.o \
	uno/platform/cores/arduino/hooks.c.o \
	uno/platform/cores/arduino/HardwareSerial3.cpp.o \
	uno/platform/cores/arduino/WInterrupts.c.o \
	uno/platform/cores/arduino/Print.cpp.o \
	uno/platform/cores/arduino/HardwareSerial.cpp.o \
	uno/platform/cores/arduino/new.cpp.o \
	uno/platform/cores/arduino/wiring_analog.c.o \
	uno/platform/cores/arduino/USBCore.cpp.o \
	uno/platform/cores/arduino/wiring_digital.c.o \
	uno/platform/cores/arduino/Tone.cpp.o \
	uno/platform/cores/arduino/main.cpp.o \

LIBRARIES_OBJS = \

TARGETS = \
	uno/QueueTests.hex \

all: $(TARGETS)

uno/QueueTests.hex: uno/QueueTests.elf
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-objcopy" -O ihex -R .eeprom  "uno/QueueTests.elf" "uno/QueueTests.hex"

uno/QueueTests.elf: $(PROJECT_OBJS) $(LIBRARIES_OBJS) uno/core.a
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-gcc" -w -Os -Wl,--gc-sections -mmcu=atmega328p  -o "uno/QueueTests.elf" $(PROJECT_OBJS) $(LIBRARIES_OBJS) "uno/core.a" "-Luno" -lm

uno/core.a:	$(PLATFORM_OBJS)

clean:
	$(RMDIR) uno

size:
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-size" -A "uno/QueueTests.elf"

uno/project/QueueTests.cpp.o: ../QueueTests.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"


uno/platform/cores/arduino/HardwareSerial2.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/HardwareSerial2.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/HardwareSerial0.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/HardwareSerial0.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/IPAddress.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/IPAddress.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/WMath.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/WMath.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/PluggableUSB.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/PluggableUSB.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/WString.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/WString.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/wiring_shift.c.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/wiring_shift.c
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/abi.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/abi.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/CDC.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/CDC.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/wiring_pulse.c.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/wiring_pulse.c
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/wiring_pulse.S.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/wiring_pulse.S
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-gcc" -c -g -x assembler-with-cpp -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/HardwareSerial1.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/HardwareSerial1.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/Stream.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/Stream.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/wiring.c.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/wiring.c
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/hooks.c.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/hooks.c
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/HardwareSerial3.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/HardwareSerial3.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/WInterrupts.c.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/WInterrupts.c
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/Print.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/Print.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/HardwareSerial.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/HardwareSerial.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/new.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/new.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/wiring_analog.c.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/wiring_analog.c
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/USBCore.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/USBCore.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/wiring_digital.c.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/wiring_digital.c
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/Tone.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/Tone.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"

uno/platform/cores/arduino/main.cpp.o: /home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino/main.cpp
	@$(call mymkdir,$(dir $@))
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/cores/arduino" -I"/home/helton/.arduinocdt/hardware/arduino/avr/1.6.9/variants/standard" "$<" -o "$@"
	"/home/helton/.arduinocdt/tools/arduino/avr-gcc/4.8.1-arduino5/bin/avr-ar" rcs  "uno/core.a" "$@"


