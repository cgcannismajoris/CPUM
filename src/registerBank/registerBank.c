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


REGISTERBANK *registerBank_new(uint8_t *mem, uint64_t length)
{
 	
    REGISTERBANK *regsBank;

    if ((regsBank = (REGISTERBANK *)malloc(sizeof(REGISTERBANK))) == NULL)
    {
        cpuError_setDesc(REGISTERBANK_EALLOC_MSG);
        return REGISTERBANK_EALLOC;
    }
	
    if ((regsBank->registers = (int8_t *)malloc(sizeof(int8_t) * length)) == NULL)
    {
        free(regsBank);
        cpuError_setDesc(REGISTERBANK_EALLOC_MSG);
        return REGISTERBANK_EALLOC;
    }

	memcpy(regsBank->registers, mem, sizeof(uint8_t) * length);

    regsBank->length = length / (sizeof(uint8_t) + sizeof(uint32_t));
	
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

int32_t registerBank_getRegister(REGISTERBANK *regsBank, uint64_t address)
{
    if (address < regsBank->length)
	{
		//Calcula a posição do registrador desejado
		address = (address * (sizeof(uint8_t) + sizeof(uint32_t))) + sizeof(uint8_t);
        
		//Retorna o valor armazenado
		return *((int*)(regsBank->registers + address));
	}
    return 0;
}

void registerBank_setRegister(REGISTERBANK *regsBank, uint64_t address,
                              int32_t value)
{
    if (address < regsBank->length)
	{
		//Calcula a posição do registrador desejado
		address = (address * (sizeof(uint8_t) + sizeof(uint32_t))) + sizeof(uint8_t);
		
		//Seta o valor
        *((int*)(regsBank->registers + address)) = value;
	}
}

void registerBank_pcAdd(REGISTERBANK *regsBank, signed int value)
{
	regsBank->pc += value;
}

uint64_t registerBank_getPc(REGISTERBANK *regsBank)
{
	return regsBank->pc;
}

uint64_t registerBank_getLength(REGISTERBANK *regsBank)
{
	return regsBank->length;
}

