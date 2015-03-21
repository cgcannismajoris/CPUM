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

uint32_t input_getInst(INPUTSYSTEM *input, uint64_t address)
{
	
    if (address < input->mem->length)
        return input->mem->mem[address];

    return 0;
}

int input_load(INPUTSYSTEM *input, const char *filename)
{
    FILE *fbin;      /* ptr. arquivo binário */
    uint64_t length;

    if ((fbin = fopen(filename, "rb+")) == NULL)
    {
        cpuError_setDesc(INPUTSYSTEM_EFOPEN_MSG);
        return INPUTSYSTEM_EFOPEN;
    }

    fseek(fbin, 0, SEEK_END);
    length = ftell(fbin) / sizeof(uint32_t);

    rewind(fbin); /* retorne ao início do arquivo */

    if ((input->mem = instMemory_new(length)) == INSTMEMORY_EALLOC)
    {
        cpuError_setDesc(INPUTSYSTEM_ELOAD_MSG);
        return INPUTSYSTEM_ELOAD;
    }

    input->mem->length = length;

    /* Carregar o arquivo integralmente para a memória de instruções */
    fread(input->mem->mem, sizeof(uint32_t), length, fbin);

    fclose(fbin);
    return 0;
}
