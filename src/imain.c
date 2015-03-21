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


int main(int argc, char **argv)
{
    if ((cpuError_new(CPUERROR_FAILUREDESCLENGTH)) == NULL)
    {
        fprintf(stderr, "%s\n", CPUERROR_EALLOC_MSG);
        return EXIT_FAILURE;
    }



    cpuError_free();
    return EXIT_SUCCESS;
}

