# CPUM
Uma implementação do processador conceitual M, que realiza a simulação de uma Máquina de Registradores.

##O que ela faz?
Realiza a abertura de um arquivo binário compatível com a CPUM. Em seguida, é feita a execução das instruções
e a geração da função computada, disposta num arquivo de texto.

##Requisitos recomendados
* Sistema Operacional Unix-like ou GNU/Linux mais recente;
* GCC 4.9.1 ou superior;
* GNU Make 4.0 ou superior.

**Requisito opcional**
* Qt Creator 5.3.0 ou superior.

##Estrutura do projeto

A seguir, está disposto a organização básica do projeto CPUM.

	/CPUM					: pasta-pai do projeto	
		/data				: arquivos de entrada/saída e relativos ao projeto
		/src				: pasta de códigos-fonte
		.gitignore			: arquivo gitignore
		CPUM.pro    		: árvore do projeto (Qt Creator)
		CPUM.pro.user		: estruturação do projeto (Qt Creator)
		Makefile			: arquivo Makefile
		README.md			: arquivo LEIA-ME

> Obs.: como cortesia da casa, é oferecido um layout simples do projeto para o Qt Creator.

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
