/*
 * ===========================================================================
 *
 * Nome do Arquivo:  cpu.h
 *
 *       Descricao:  TAD principal da máquina.
 *
 *          Versao:  1.0
 *       Criado em:  20/03/2015 18:08:48
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim 
 *     Organizacao:  VY Cannis Majoris
 *
 * ===========================================================================
 */

#ifndef CPU_H
#define CPU_H

#include <stdint.h>

#include "../inputSystem/inputSystem.h"     /* incluir o TAD INPUTSYSTEM */
#include "../registerBank/registerBank.h"   /* incluir o TAD REGISTERBANK */
#include "control.h"                        /* incluir o módulo de controle */
#include "alu.h"                            /* incluir o módulo de ALU. */

#define CPU_EALLOC          NULL
#define CPU_EALLOC_MSG      "Falha ao alocar memória para a CPU."


typedef struct _cpu
{
    uint32_t        ticksPerSecond;
    REGISTERBANK *  regsBank;       /* banco de registradores */
} CPU;


CPU *   cpu_new(uint64_t regQtd);

void    cpu_start(CPU *cpu, const char *input, const char *output);

void    cpu_clock(CPU *cpu);

#endif
