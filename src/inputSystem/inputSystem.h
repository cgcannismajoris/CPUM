/*
 * Nome do Arquivo:  inputSystem.h
 *       Descricao:  TAD para leitura do arquivo binário a ser processado
 *       			 pela máquina.
 *
 * Exported functions from inputSystem.c.
 * Copyright (C) 2015  Cristian Costa Mello and Gustavo Freitas de Amorim
 *
 * This is part of CPUM
 * CPUM is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CPUM is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../cpuError.h"
#include "instMemory/instMemory.h"      /* incluir o TAD INSTMEMORY. */
#include "../instruction/instruction.h"

#define INPUTSYSTEM_EALLOC        NULL
#define INPUTSYSTEM_EALLOC_MSG    "Falha ao alocar memória para INPUTSYSTEM."

#define INPUTSYSTEM_EFOPEN        -1
#define INPUTSYSTEM_EFOPEN_MSG    "Falha ao abrir o arquivo binário de entrada."

#define INPUTSYSTEM_ELOAD         -1
#define INPUTSYSTEM_ELOAD_MSG     "Falha no carregamento do arquivo binário de entrada."


typedef struct _inputSystem
{
	INSTMEMORY *mem;
} INPUTSYSTEM;


INPUTSYSTEM *   input_new();

void            input_free(INPUTSYSTEM *input);

uint8_t *       input_getInst(INPUTSYSTEM *input, uint64_t address);

uint8_t *		input_load(INPUTSYSTEM *input, const char *filename);

#endif
