/*
 * ===========================================================================
 *
 * Nome do Arquivo:  inputSystem.h
 *
 *       Descricao:  TAD para leitura do arquivo binário a ser processado
 *       			 pela máquina.
 *
 *          Versao:  1.0
 *       Criado em:  20/03/2015 18:25:44
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim 
 *     Organizacao:  VY Cannis Majoris
 *
 * ===========================================================================
 */


#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <stdint.h>

#include "instMemory/instMemory.h"


typedef struct _inputSystem
{
	INSTMEMORY *mem;
} INPUTSYSTEM;


INPUTSYSTEM *input_new();

void input_free(INPUTSYSTEM *input);

uint32_t input_getInst(uint64_t address);

void input_load(const char *filename);

#endif
