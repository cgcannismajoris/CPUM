# CPUM
Uma implementação do processador conceitual M, que realiza a simulação de uma Máquina de Registradores.

##O que ela faz?
Realiza a abertura de um arquivo binário compatível com a CPUM. Em seguida, é feita a execução das instruções
e a geração da função computada, disposta num arquivo de texto.

##Procedimento de compilação da CPUM
Estando-se na pasta pai do projeto ("/CPUM"), realize o comando abaixo:

	$ make

##Procedimentos de utilização via Terminal
Através de um terminal de comando do Linux, observa-se o formato de entrada abaixo:

	$ ./bin/CPUM <NOME_DO_ARQUIVO_DE_ENTRADA> <NOME_DO_ARQUIVO_DE_SAIDA>
	
	ENTRADAS:
	  <NOME_DO_ARQUIVO_DE_ENTRADA> : é o arquivo binário compatível com a CPUM;
	  <NOME_DO_ARQUIVO_DE_SAIDA>   : é o arquivo de texto de saída.

Se a execução for bem-sucedida, então será gerado um arquivo de texto contendo a função computada.
