/*
 * ==========================================================================
 *
 * Nome do Arquivo:  cpu.c
 *
 *       Descricao:  Implementação do TAD CPU.
 *
 *          Versao:  1.0
 *       Criado em:  20/03/2015 18:07:49
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim 
 *     Organizacao:  VY Cannis Majoris
 *
 * =========================================================================
 */

#include "cpu.h"

CPU *cpu_new(uint64_t regQtd, uint32_t ticks)
{
    CPU *nova;

    if ((nova = (CPU *)malloc(sizeof(CPU))) == NULL)
    {
        cpuError_setDesc(CPU_EALLOC_MSG);
        return CPU_EALLOC;
    }

    /* Criar banco de registradores. */
    if ((nova->regsBank = registerBank_new(regQtd)) == REGISTERBANK_EALLOC)
    {
        free(nova);

        cpuError_setDesc(CPUERROR_EALLOC_MSG);
        return CPU_EALLOC;
    }
	
	nova->ticksPerSecond = ticks;

    return nova;
}

void cpu_free(CPU *cpu)
{
	registerBank_free(cpu->regsBank);
	free(cpu);
}

int cpu_start(CPU *cpu, const char *input, const char *output)
{
	
	int status;	

	if((cpu->input = input_new()) == INPUTSYSTEM_EALLOC)
		return CPU_ERROR;

	if((cpu->output = output_new(output)) == OUTPUTSYSTEM_EALLOC)
		return CPU_ERROR;

	if(input_load(cpu->input, input) != 0)
		return CPU_ERROR;

	while((status = cpu_clock(cpu)) == CPU_FINISH)
	{
		output_writeTrace(cpu->output, cpu->regsBank);
	}

	input_free(cpu->input);
	output_free(cpu->output);

	return (status);
}

int cpu_clock(CPU *cpu)
{
	uint32_t inst;
	
	if((inst = input_getInst(cpu->input, registerBank_getPc(cpu->regsBank))) == 0)
	{
		return (CPU_END);
	}

	if(control_process(cpu->regsBank, inst) == CONTROL_EUKNOWINSTRUCTION)
	{
		return (CPU_ERROR);
	}

	return (CPU_FINISH);
}
