/*
 * ==========================================================================
 *
 * Nome do Arquivo:  cpuError.c
 *
 *       Descricao:  Implementação do módulo cpuError.
 *
 *          Versao:  1.0
 *       Criado em:  21/03/2015 08:46:18
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim
 *     Organizacao:  VY Cannis Majoris
 *
 * =========================================================================
 */

#include "cpuError.h"

//Armazena a string do erro gerado.
static char *__failureDescription;


char *cpuError_new(uint32_t desc)
{
    if ((__failureDescription = (char *)malloc(sizeof(char) * desc)) == NULL)
        return NULL;

    return __failureDescription;
}

void cpuError_free()
{
    free(__failureDescription);
}

char *cpuError_getDesc()
{
    return __failureDescription;
}

void cpuError_setDesc(const char *failureDesc)
{
    sprintf(__failureDescription, "%s", failureDesc);
}
