/*
 * ==========================================================================
 *
 * Nome do Arquivo:  outputSystem.c
 *
 *       Descricao:  Implementação do TAD OUTPUTSYSTEM.
 *
 *          Versao:  1.0
 *       Criado em:  20/03/2015 19:37:21
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim 
 *     Organizacao:  VY Cannis Majoris
 *
 * =========================================================================
 */

#include "outputSystem.h"

OUTPUTSYSTEM *output_new(const char *filename)
{
	OUTPUTSYSTEM *novo;

	if((novo = (OUTPUTSYSTEM*)malloc(sizeof(OUTPUTSYSTEM))) == NULL)
	{
		cpuError_setDesc(OUTPUTSYSTEM_EALLOC_MSG);
		return OUTPUTSYSTEM_EALLOC;
	}

	if((novo->file = fopen(filename, "w+")) == NULL)
	{
		cpuError_setDesc(OUTPUTSYSTEM_EFOPEN_MSG);
		return OUTPUTSYSTEM_EFOPEN;
	}

	return (novo);
}

void output_free(OUTPUTSYSTEM *output)
{
	fclose(output->file);
	free(output);
}

void output_writeTrace(OUTPUTSYSTEM *output, REGISTERBANK *regMem)
{
	uint64_t i;
	
	fprintf(output->file, "(%li, (", registerBank_getPc(regMem) + 1);

	for(i = 0; i < registerBank_getLength(regMem) - 1; i++)
		fprintf(output->file, "%i, ", registerBank_getRegister(regMem, i));
	
	fprintf(output->file, "%i", registerBank_getRegister(regMem, i));

	fprintf(output->file, "))\n");
}
