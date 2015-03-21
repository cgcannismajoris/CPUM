/* cpuError.h
 * Módulo de tratamento de erro.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define CPUERROR_FAILUREDESCLENGTH      120
#define CPUERROR_EALLOC_MSG             "Falha ao alocar memória para CPUERROR."

 /* -> char *cpuError_new(uint32_t desc)
 * 
 * - DESCRIÇÃO: Instancia uma nova string para armazenamento de erros.
 *
 * - PARÂMETROS: 
 *      -> uint32_t desc: Tamanho da string a ser alocada.
 *
 * - RETORNO: String alocada para armazenar o erro.
 *   	-> Se NULL    - Erro na operação.
 *   	-> Se != NULL - Sucesso na operação.
 */
char *   cpuError_new(uint32_t desc);


/* -> void cpuError_free()
 * 
 * - DESCRIÇÃO: Destrói a string.
 *
 * - PARÂMETROS: void.
 *
 * - RETORNO: void.
 */
void     cpuError_free();


/* -> void cpuError_setDesc(const char *failureDesc)
 * 
 * - DESCRIÇÃO: Seta a mensagem a ser armazenada pela string de erros.
 *
 * - PARÂMETROS: 
 *      -> const char *failureDesc: Mensagem a ser gravada. 
 *
 * - RETORNO: void.
 */
void     cpuError_setDesc(const char *failureDesc);


/* -> char *cpuError_getDesc()
 * 
 * - DESCRIÇÃO: Retorna o ponteiro para a string de erros.
 *
 * - PARÂMETROS: void. 
 *
 * - RETORNO: Ponteiro para a string.
 */
char *   cpuError_getDesc();

