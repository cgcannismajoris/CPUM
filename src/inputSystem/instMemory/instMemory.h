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

#ifndef INSTMEMORY_H
#define INSTMEMORY_H

#include <stdlib.h>
#include <stdint.h>

#include "../../cpuError.h"
#include "../../instruction/instruction.h"

#define INSTMEMORY_EALLOC        NULL
#define INSTMEMORY_EALLOC_MSG    "Falha ao criar memória de instruções."


typedef struct _instMemory
{
    uint8_t *   mem;
    uint64_t    length;
} INSTMEMORY;


INSTMEMORY *    instMemory_new(uint64_t length);

void            instMemory_free(INSTMEMORY *instMem);

uint32_t        instMemory_get(INSTMEMORY *instMem, uint64_t address);

#endif /* INSTMEMORY_H */
