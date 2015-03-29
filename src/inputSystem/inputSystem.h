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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../cpuError.h"
#include "instMemory/instMemory.h"      /* incluir o TAD INSTMEMORY. */


#define INPUTSYSTEM_EALLOC        NULL
#define INPUTSYSTEM_EALLOC_MSG    "Falha ao alocar memória para INPUTSYSTEM."

#define INPUTSYSTEM_EFOPEN        -1
#define INPUTSYSTEM_EFOPEN_MSG    "Falha ao abrir o arquivo binário de entrada."

#define INPUTSYSTEM_ELOAD         -1
#define INPUTSYSTEM_ELOAD_MSG     "Falha no carregamento do arquivo binário de entrada."


typedef struct _inputSystem
{
	INSTMEMORY *mem;
} INPUTSYSTEM;


INPUTSYSTEM *   input_new();

void            input_free(INPUTSYSTEM *input);

uint32_t        input_getInst(INPUTSYSTEM *input, uint64_t address);

int             input_load(INPUTSYSTEM *input, const char *filename);

#endif
