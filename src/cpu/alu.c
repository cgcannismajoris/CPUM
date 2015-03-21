/*
 * ==========================================================================
 *
 * Nome do Arquivo:  alu.c
 *
 *       Descricao:  Implementação do módulo ALU.
 *
 *          Versao:  1.0
 *       Criado em:  20/03/2015 17:44:03
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim 
 *     Organizacao:  VY Cannis Majoris
 *
 * =========================================================================
 */

#include "alu.h"

void alu_processTypeR(REGISTERBANK *regBank, TYPE_R *inst)
{
	
	uint32_t tmpResult;

	switch(inst->opcode)
	{	
		//Soma com imediate
		case 1:
			tmpResult = registerBank_getRegister(regBank, inst->orig1);
			tmpResult += inst->orig2;
			registerBank_setRegister(regBank, inst->dest, tmpResult);
			break;
		
		//Subtração com imediate
		case 2:
			tmpResult = registerBank_getRegister(regBank, inst->orig1);
			tmpResult -= inst->orig2;
			registerBank_setRegister(regBank, inst->dest, tmpResult);
			break;
	}
}

void alu_processBeqz(REGISTERBANK *regBank, TYPE_ESP_BEQZ *inst)
{
	if(registerBank_getRegister(regBank, inst->reg) == 0)
	{
		registerBank_pcAdd(regBank, inst->address_t);
	}
	else
	{
		registerBank_pcAdd(regBank, inst->address_f);
	}
}
