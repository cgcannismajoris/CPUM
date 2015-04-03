/*
 * ==========================================================================
 *
 * Nome do Arquivo:  dataMemory.c
 *
 *       Descricao:  Implementação do TAD DATAMEMORY.
 *
 *          Versao:  1.0
 *       Criado em:  20/03/2015 19:24:45
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim 
 *     Organizacao:  VY Cannis Majoris
 *
 * =========================================================================
 */

#include "instMemory.h"


INSTMEMORY *instMemory_new(uint64_t length)
{
    INSTMEMORY *novo;

    if ((novo = (INSTMEMORY *)malloc(sizeof(INSTMEMORY))) == NULL)
    {
        cpuError_setDesc(INSTMEMORY_EALLOC_MSG);
        return INSTMEMORY_EALLOC;
    }

    if ((novo->mem = (uint8_t *)malloc(length * INSTRUCTION_INSTLENGTH_BYTES)) == NULL)
    {
        free(novo);
        cpuError_setDesc(INSTMEMORY_EALLOC_MSG);
        return INSTMEMORY_EALLOC;
    }

    novo->length = length;

    return novo;
}

void instMemory_free(INSTMEMORY *instMem)
{
    free(instMem->mem);
    free(instMem);
}

uint32_t instMemory_get(INSTMEMORY *instMem, uint64_t address)
{
    if (address < instMem->length)
        return instMem->mem[address * INSTRUCTION_INSTLENGTH_BYTES];

    return 0;
}
