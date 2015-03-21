# Makefile
# Makefile do Projeto AssemblerM.
#
# ENTRADAS:
#	1. make	all ou make:
#	   compilação do projeto;
#
#	3. make clean : limpa o projeto;


# DEFINIÇÕES DE ARQUIVOS #####################
# Arquivos de código-fonte
IMAIN_SRC			= src/imain.c
CPU_SRC				= src/cpu/cpu.c
ALU_SRC				= src/cpu/alu.c
CONTROL_SRC			= src/cpu/control.c
INSTRUCTION_SRC		= src/instruction/instruction.c
OUTPUTSYSTEM_SRC	= src/outputSystem/outputSystem.c
INPUTSYSTEM_SRC		= src/inputSystem/inputSystem.c
INSTMEMORY_SRC		= src/inputSystem/instMemory/instMemory.c
REGISTERBAK_SRC		= src/registerBank/registerBank.c


# Arquivos-cabeçalho
IMAIN_H				= src/imain.h
CPU_H				= src/cpu/cpu.h
ALU_H				= src/cpu/alu.h
CONTROL_H			= src/cpu/control.h
INSTRUCTION_H		= src/instruction/instruction.h
OUTPUTSYSTEM_H		= src/outputSystem/outputSystem.h
INPUTSYSTEM_H		= src/inputSystem/inputSystem.h
INSTMEMORY_H		= src/inputSystem/instMemory/instMemory.h	
REGISTERBAK_H		= src/registerBank/registerBank.h


# Arquivos-objeto
IMAIN_OBJ			= obj/imain.o
CPU_OBJ				= obj/cpu.o
ALU_OBJ				= obj/alu.o
CONTROL_OBJ			= obj/control.o
INSTRUCTION_OBJ		= obj/instruction.o
OUTPUTSYSTEM_OBJ	= obj/outputSystem.o
INPUTSYSTEM_OBJ		= obj/inputSystem.o
INSTMEMORY_OBJ		= obj/instMemory.o
REGISTERBAK_OBJ		= obj/registerBank.o

# Símbolos de arquivos de saída
OUTPUT_NAME_EXEC		= CPUM
OUTPUT_FULLPATH_EXEC	= bin/$(OUTPUT_NAME_EXEC)

LN_SYMBOL				= $(OUTPUT_NAME_EXEC)


# DEFINIÇÕES PARA COMPILAÇÃO #################
COMPILER		= gcc
CFLAG			= -c
LFLAG			= -o
#LIBFLAG 		=
SRC				= $(IMAIN_SRC) $(CPU_SRC) $(ALU_SRC) $(CONTROL_SRC) \
$(INSTRUCTION_SRC) $(OUTPUTSYSTEM_SRC) $(INPUTSYSTEM_SRC) $(INSTMEMORY_SRC) \
$(REGISTERBAK_SRC)


OBJ				= $(IMAIN_OBJ) $(CPU_OBJ) $(ALU_OBJ) $(CONTROL_OBJ) \
$(INSTRUCTION_OBJ) $(OUTPUTSYSTEM_OBJ) $(INPUTSYSTEM_OBJ) $(INSTMEMORY_OBJ) \
$(REGISTERBAK_OBJ)


BIN				= $(OUTPUT_FULLPATH_EXEC)


all: mk_dir $(BIN)

$(IMAIN_OBJ): $(IMAIN_SRC)
	$(COMPILER) $(CFLAG) $(IMAIN_SRC) $(LFLAG) $(IMAIN_OBJ)

$(CPU_OBJ): $(CPU_H) $(CPU_SRC)
	$(COMPILER) $(CFLAG) $(CPU_SRC) $(LFLAG) $(CPU_OBJ)

$(ALU_OBJ): $(ALU_H) $(ALU_SRC)
	$(COMPILER) $(CFLAG) $(ALU_SRC) $(LFLAG) $(ALU_OBJ)

$(CONTROL_OBJ): $(CONTROL_H) $(CONTROL_SRC)
	$(COMPILER) $(CFLAG) $(CONTROL_SRC) $(LFLAG) $(CONTROL_OBJ)

$(INSTRUCTION_OBJ): $(INSTRUCTION_H) $(INSTRUCTION_SRC)
	$(COMPILER) $(CFLAG) $(INSTRUCTION_SRC) $(LFLAG) $(INSTRUCTION_OBJ)

$(OUTPUTSYSTEM_OBJ): $(OUTPUTSYSTEM_H) $(OUTPUTSYSTEM_SRC)
	$(COMPILER) $(CFLAG) $(OUTPUTSYSTEM_SRC) $(LFLAG) $(OUTPUTSYSTEM_OBJ)

$(INPUTSYSTEM_OBJ): $(INPUTSYSTEM_H) $(INPUTSYSTEM_SRC)
	$(COMPILER) $(CFLAG) $(INPUTSYSTEM_SRC) $(LFLAG) $(INPUTSYSTEM_OBJ)

$(INSTMEMORY_OBJ): $(INSTMEMORY_H) $(INSTMEMORY_SRC)
	$(COMPILER) $(CFLAG) $(INSTMEMORY_SRC) $(LFLAG) $(INSTMEMORY_OBJ)

$(REGISTERBAK_OBJ): $(REGISTERBAK_H) $(REGISTERBAK_SRC)
	$(COMPILER) $(CFLAG) $(REGISTERBAK_SRC) $(LFLAG) $(REGISTERBAK_OBJ)

$(BIN): $(OBJ)
	$(COMPILER) $(LFLAG) $(BIN) $(OBJ)

# GERAÇÃO DO LINK SIMBÓLICO #################
LN_SYMBOL:
	rm -f $(OUTPUT_NAME_EXEC)
	ln -s $(OUTPUT_FULLPATH_EXEC)

# CRIAÇÃO DE PASTAS #########################
mk_dir:
	mkdir -p bin data obj

clean:
	rm -f $(OUTPUT_FULLPATH_EXEC) $(LN_SYMBOL) *~ *.swp *.swo \
	$(OBJ) $(TOOL_DICWRITER_OBJ)