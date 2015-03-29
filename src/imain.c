/*
 * ==========================================================================
 *
 * Nome do Arquivo:  imain.c
 *
 *       Descricao:  
 *
 *          Versao:  1.0
 *       Criado em:  20/03/2015 19:34:52
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim 
 *     Organizacao:  VY Cannis Majoris
 *
 * =========================================================================
 */

#include "cpuError.h"
#include "cpu/cpu.h"
#include "inputSystem/inputSystem.h"
#include "instruction/instruction.h"

#define QTD_REG 	32

int main(int argc, char **argv)
{
	
	CPU *cpu;
	
	if(argc < 3)
	{
		fprintf(stderr, "Linha de comando inválida!\n");
		return EXIT_FAILURE;
	}

    if ((cpuError_new(CPUERROR_FAILUREDESCLENGTH)) == NULL)
    {
        fprintf(stderr, "CPU: %s\n", CPUERROR_EALLOC_MSG);
        return EXIT_FAILURE;
    }

	if((cpu = cpu_new(QTD_REG, 1)) == CPU_EALLOC)
	{
		fprintf(stderr, "CPU: %s\n", cpuError_getDesc());
		return EXIT_FAILURE;
	}

	if(cpu_start(cpu, argv[1], argv[2]) == CPU_ERROR)
	{
		fprintf(stderr, "CPU: %s\n", cpuError_getDesc());
		return EXIT_FAILURE;
	}
	else
	{
		printf("Programa executado com sucesso! =D\n");
	}

	cpu_free(cpu);
    cpuError_free();

	return EXIT_SUCCESS;
}
