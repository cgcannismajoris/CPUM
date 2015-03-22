/*
 * ==========================================================================
 *
 * Nome do Arquivo:  registerBank.c
 *
 *       Descricao:  Implementação do TAD REGISTERBANK.
 *
 *          Versao:  1.0
 *       Criado em:  20/03/2015 17:36:45
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim 
 *     Organizacao:  VY Cannis Majoris
 *
 * =========================================================================
 */

#include "registerBank.h"


REGISTERBANK *registerBank_new(uint64_t length)
{
    REGISTERBANK *regsBank;

    if ((regsBank = (REGISTERBANK *)malloc(sizeof(REGISTERBANK))) == NULL)
    {
        cpuError_setDesc(REGISTERBANK_EALLOC_MSG);
        return REGISTERBANK_EALLOC;
    }

    if ((regsBank->registers = (uint32_t *)malloc(sizeof(uint32_t) * length))
            == NULL)
    {
        free(regsBank);

        cpuError_setDesc(REGISTERBANK_EALLOC_MSG);
        return REGISTERBANK_EALLOC;
    }

	memset(regsBank->registers, 0, sizeof(uint32_t) * length);

    regsBank->length = length;
	
	*((uint32_t*)&regsBank->zero) = 0;
	*((uint32_t*)&regsBank->um) = 1;

	regsBank->pc = 0;

    return regsBank;
}

void registerBank_free(REGISTERBANK *regsBank)
{
    free(regsBank->registers);
    free(regsBank);
}

uint32_t registerBank_getRegister(REGISTERBANK *regsBank, uint64_t address)
{
    if (address < regsBank->length)
        return regsBank->registers[address];

    return 0;
}

void registerBank_setRegister(REGISTERBANK *regsBank, uint64_t address,
                              uint32_t value)
{
    if (address < regsBank->length)
        regsBank->registers[address] = value;
}

void registerBank_pcAdd(REGISTERBANK *regsBank, short int value)
{
	regsBank->pc += value;
}

uint64_t registerBank_getPc(REGISTERBANK *regsBank)
{
	return regsBank->pc;
}

uint64_t registerBank_getLength(REGISTERBANK *regsBank)
{
	return (regsBank->length);
}
