/*
 * ===========================================================================
 *
 * Nome do Arquivo:  outputSystem.h
 *
 *       Descricao:  TAD para escrita de todas as saídas da máquina.
 *
 *          Versao:  1.0
 *       Criado em:  20/03/2015 19:37:53
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim
 *     Organizacao:  VY Cannis Majoris
 *
 * ===========================================================================
 */


#ifndef OUTPUTSYSTEM_H
#define OUTPUTSYSTEM_H

#include <stdio.h>
#include <stdint.h>


typedef struct _outputSystem
{
	FILE *file;
} OUTPUTSYSTEM;


OUTPUTSYSTEM *		output_new();

void 				output_free(OUTPUTSYSTEM *output);

void 				output_writeTrace(OUTPUTSYSTEM *output, uint32_t *regMem, uint64_t pc);

#endif
