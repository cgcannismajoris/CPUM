/*
 * ===========================================================================
 *
 * Nome do Arquivo:  dataMemory.h
 *
 *       Descricao:  TAD para menipulação da memória de instruções da 
 *       			 máquina.
 *
 *          Versao:  1.0
 *       Criado em:  20/03/2015 19:25:23
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim 
 *     Organizacao:  VY Cannis Majoris
 *
 * ===========================================================================
 */

#ifndef DATAMEMORY_H
#define DATAMEMORY_H

#include <stdint.h>

typedef struct _instMemory
{
	uint32_t *mem;
	uint64_t length;
} INSTMEMORY;


INSTMEMORY *instMemory_new(uint32_t *mem, uint64_t length);

void instMemory_free(INSTMEMORY *mem);

uint32_t instMemory_get(uint64_t address);

#endif
