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

CPU *cpu_new(uint64_t regQtd)
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

    return nova;
}

void cpu_start(CPU *cpu, const char *input, const char *output)
{

}

void cpu_clock(CPU *cpu)
{

}
