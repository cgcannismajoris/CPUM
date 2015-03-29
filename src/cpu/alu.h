/*
 * ===========================================================================
 *
 * Nome do Arquivo:  alu.h
 *
 *       Descricao:  TAD para processamento das instruções da máquina.
 *
 *          Versao:  1.0
 *       Criado em:  20/03/2015 17:44:28
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim 
 *     Organizacao:  VY Cannis Majoris
 *
 * ===========================================================================
 */

#ifndef ALU_H
#define ALU_H

#include "../instruction/instruction.h"
#include "../registerBank/registerBank.h"

void 		alu_processTypeR(REGISTERBANK *regsBank, TYPE_R *inst);
void 		alu_processBeqz(REGISTERBANK *regsBank, TYPE_ESP_BEQZ *inst);

#endif
