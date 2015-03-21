/*
 * ===========================================================================
 *
 * Nome do Arquivo:  control.h
 *
 *       Descricao:  
 *
 *          Versao:  1.0
 *       Criado em:  20/03/2015 18:01:13
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim 
 *     Organizacao:  VY Cannis Majoris
 *
 * ===========================================================================
 */

#ifndef CONTROL_H
#define CONTROL_H

#include "../instruction/instruction.h"
#include "alu.h"

void control_process(uint32_t inst);

#endif