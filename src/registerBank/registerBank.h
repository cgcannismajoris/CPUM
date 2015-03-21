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


#define REGISTER_MAX 		32

typedef struct _registerBank
{
	int *registers;
	uint64_t length;
} REGISTERBANK;

void registerBank_new(uint64_t length);

int getRegister(uint64_t address);

void setRegister(REGISTERBANK *reg, uint64_t address, int value);

#endif
