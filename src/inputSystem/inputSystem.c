/*
 * ==========================================================================
 *
 * Nome do Arquivo:  inputSystem.c
 *
 *       Descricao:  Implementação do TAD IMPUTSYSTEM.
 *
 *          Versao:  1.0
 *       Criado em:  20/03/2015 18:25:16
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim 
 *     Organizacao:  VY Cannis Majoris
 *
 * =========================================================================
 */

#include "inputSystem.h"

INPUTSYSTEM *input_new()
{
    INPUTSYSTEM *novo;

    if ((novo = (INPUTSYSTEM *)malloc(sizeof(INPUTSYSTEM))) == NULL)
    {
        cpuError_setDesc(INPUTSYSTEM_EALLOC_MSG);
        return INPUTSYSTEM_EALLOC;
    }

    novo->mem = NULL;

    return novo;
}

void input_free(INPUTSYSTEM *input)
{
    if (input->mem != NULL)
        instMemory_free(input->mem);

    free(input);
}

uint8_t *input_getInst(INPUTSYSTEM *input, uint64_t address)
{
    if (address < input->mem->length)
        return (input->mem->mem + (address * INSTRUCTION_INSTLENGTH_BYTES));

    return NULL;
}

long int input_load(INPUTSYSTEM *input, const char *filename)
{
    FILE *fbin;      /* ptr. arquivo binário */
    uint64_t length;
	uint32_t qtdReg;

    if ((fbin = fopen(filename, "rb+")) == NULL)
    {
        cpuError_setDesc(INPUTSYSTEM_EFOPEN_MSG);
        return INPUTSYSTEM_EFOPEN;
    }

    fseek(fbin, 0, SEEK_END);
    length = (ftell(fbin) - sizeof(uint32_t)) / INSTRUCTION_INSTLENGTH_BYTES;
    
	rewind(fbin); /* retorne ao início do arquivo */
 
    if ((input->mem = instMemory_new(length)) == INSTMEMORY_EALLOC)
    {
		fclose(fbin);
		return INPUTSYSTEM_ELOAD;
    }

	/* Carrega a quantidade de registradores */	
	fread(&qtdReg, sizeof(uint32_t), 1, fbin);	
    
	/* Carregar o arquivo integralmente para a memória de instruções */
    fread(input->mem->mem, INSTRUCTION_INSTLENGTH_BYTES, length, fbin);

    fclose(fbin);
    return qtdReg;
}
