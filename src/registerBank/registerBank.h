/*
 * ===========================================================================
 *
 * Nome do Arquivo:  registerBank.h
 *
 *       Descricao:  TAD para manipulação dos registradores disponíveis na 
 *       			 máquina.
 *
 *          Versao:  1.0
 *       Criado em:  20/03/2015 17:37:38
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim 
 *     Organizacao:  VY Cannis Majoris
 *
 * ===========================================================================
 */

#ifndef REGISTERBANK_H
#define REGISTERBANK_H

#include <stdint.h>
#include <stdlib.h>

#include "../cpuError.h"


#define REGISTERBANK_MAX            32

#define REGISTERBANK_EALLOC         NULL
#define REGISTERBANK_EALLOC_MSG     "Falha ao alocar memória para o banco de registradores."


typedef struct _registerBank
{
	//Registradores de propósito geral
    uint32_t *  registers;

	//Registradores de propósito específico
	const uint32_t zero;
   	const uint32_t um;
   	uint32_t pc;

    uint64_t    length;
} REGISTERBANK;


REGISTERBANK *  registerBank_new(uint64_t length);

void            registerBank_free(REGISTERBANK *regsBank);

uint32_t        registerBank_getRegister(REGISTERBANK *regsBank, uint64_t address);

void            registerBank_setRegister(REGISTERBANK *regsBank,
                                         uint64_t address,
                                         uint32_t value);

void 			registerBank_pcAdd(REGISTERBANK *regsBank, uint16_t value);

uint64_t		registerBank_getLength(REGISTERBANK *regsBank);
#endif
