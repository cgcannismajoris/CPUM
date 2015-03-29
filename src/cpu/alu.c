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

void alu_processTypeR(REGISTERBANK *regsBank, TYPE_R *inst)
{
	
	uint32_t tmpResult;

	switch(inst->opcode)
	{	
		//Soma com imediate
		case 1:
			tmpResult = registerBank_getRegister(regsBank, inst->orig1);
			tmpResult += inst->orig2;
			registerBank_setRegister(regsBank, inst->dest, tmpResult);
			break;
		
		//Subtração com imediate
		case 2:
			tmpResult = registerBank_getRegister(regsBank, inst->orig1);
			tmpResult -= inst->orig2;
			registerBank_setRegister(regsBank, inst->dest, tmpResult);
			break;
	}

	registerBank_pcAdd(regsBank, inst->address);
}

void alu_processBeqz(REGISTERBANK *regsBank, TYPE_ESP_BEQZ *inst)
{
	if(registerBank_getRegister(regsBank, inst->reg) == 0)
	{
		registerBank_pcAdd(regsBank, inst->address_t);
	}
	else
	{
		registerBank_pcAdd(regsBank, inst->address_f);
	}

}
