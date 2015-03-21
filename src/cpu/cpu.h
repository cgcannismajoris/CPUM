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

#include "control.h"
#include "alu.h"


typedef struct _cpu
{
	uint32_t ticksPerSecond;
} CPU;


CPU *cpu_new(uint64_t regQtd);

void cpu_start(CPU *cpu, const char *input, const char *output);

void cpu_clock(CPU *cpu);

#endif
