/*
 * Nome do Arquivo:  cpu.h
 *       Descricao:  TAD principal da máquina.
 *
 * Exported functions from cpu.c.
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

#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <unistd.h>

#include "../inputSystem/inputSystem.h"     /* incluir o TAD INPUTSYSTEM */
#include "../outputSystem/outputSystem.h"	/* incluir o TAD OUTPUTSYSTEM  */
#include "../registerBank/registerBank.h"   /* incluir o TAD REGISTERBANK */
#include "control.h"                        /* incluir o módulo de controle */
#include "alu.h"                            /* incluir o módulo de ALU. */

#define CPU_EALLOC          NULL
#define CPU_EALLOC_MSG      "Falha ao alocar memória para a CPU."

#define CPU_FINISH			0
#define CPU_END				1
#define CPU_ERROR			-1

typedef struct _cpu
{
    uint32_t        ticksPerSecond;
    REGISTERBANK *  regsBank;       /* banco de registradores */
	INPUTSYSTEM *	input;
	OUTPUTSYSTEM *	output;
} CPU;


CPU *   	cpu_new(uint32_t ticks);

void 		cpu_free(CPU *cpu);

int     	cpu_start(CPU *cpu, const char *input, const char *output);

int     	cpu_clock(CPU *cpu);

#endif
