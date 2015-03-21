/*
 * ==========================================================================
 *
 * Nome do Arquivo:  control.c
 *
 *       Descricao:  Implementação do módulo CONTROL.
 *
 *          Versao:  1.0
 *       Criado em:  20/03/2015 18:00:42
 *         Revisao:  none
 *      Compilador:  gcc
 *
 *           Autor:  Cristian Costa Mello, Gustavo Freitas de Amorim 
 *     Organizacao:  VY Cannis Majoris
 *
 * =========================================================================
 */

#include "control.h"

int control_process(REGISTERBANK  *regBank, uint32_t inst)
{
 
	TYPE_R tmp;

	INSTRUCTION_SETINST(tmp, inst);
	
	//Se for uma instrução do tipo R.
	if(tmp.opcode > 1 && tmp.opcode < 22)
	{
		alu_processTypeR(regBank, &tmp);
	}

	//Caso forem acrescentadas novas instruções futuras adicionar trechos de
	//decodificação aqui.

	//Se for uma instrução especial beqz
	else if(tmp.opcode == 56)
	{
		TYPE_ESP_BEQZ beqz;
		
		INSTRUCTION_SETINST(beqz, inst);

		alu_processBeqz(regBank, &beqz);
	}
	
	//Tipo não reconhecido.
	else{
		cpuError_setDesc(CONTROL_EUKNOWINSTRUCTION_MSG);
		return CONTROL_EUKNOWINSTRUCTION;
	}
}
