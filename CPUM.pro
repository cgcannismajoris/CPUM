TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/imain.c \
	src/cpu/alu.c \
	src/cpu/control.c \
	src/cpu/cpu.c \
	src/inputSystem/inputSystem.c \
	src/inputSystem/instMemory/instMemory.c \
	src/instruction/instruction/instruction.c \
	src/outputSystem/outputSystem.c \
	src/registerBank/registerBank.c

HEADERS += src/cpu/alu.h \
	src/cpu/control.h \
	src/cpu/cpu.h \
	src/inputSystem/inputSystem.h \
	src/inputSystem/instMemory/instMemory.h \
	src/instruction/instruction/instruction.h \
	src/outputSystem/outputSystem.h \
	src/registerBank/registerBank.h

OTHER_FILES += Makefile \
	README.md
