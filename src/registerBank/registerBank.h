/*
 * Nome do Arquivo:  registerBank.h
 *       Descricao:  TAD para manipulação dos registradores disponíveis na
 *       			 máquina.
 *
 * Exported functions from registerBank.c.
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

#ifndef REGISTERBANK_H
#define REGISTERBANK_H

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "../cpuError.h"

#define REGISTERBANK_EALLOC         NULL
#define REGISTERBANK_EALLOC_MSG     "Falha ao alocar memória para o banco de registradores."


typedef struct _registerBank
{
	//Registradores de propósito geral
    int8_t *  		registers;

	//Registradores de propósito específico
	const uint32_t 	zero;
   	const uint32_t 	um;
   	uint64_t 		pc;

    uint64_t    	length;
} REGISTERBANK;


REGISTERBANK *	registerBank_new(uint8_t *mem, uint64_t length);

void            registerBank_free(REGISTERBANK *regsBank);

int32_t         registerBank_getRegister(REGISTERBANK *regsBank, uint64_t address);

void            registerBank_setRegister(REGISTERBANK *regsBank, uint64_t address,
	                                         int32_t value);

void 			registerBank_pcAdd(REGISTERBANK *regsBank, signed int value);

uint64_t		registerBank_getPc(REGISTERBANK *regsBank);

uint64_t		registerBank_getLength(REGISTERBANK *regsBank);

#endif
