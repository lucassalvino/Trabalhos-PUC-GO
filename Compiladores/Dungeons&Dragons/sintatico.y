%{
	#include <stdio.h>
	#include <stdlib.h>

	#include "acoes.h"

	extern int yylex();
	extern int yyparse();

	extern FILE *yyin;

	void yyerror(const char *s);
%}
%token HANK ATIRA FLECHA PRESTO DISPARA RAIO ARCANO BOBBY USA TACAPE DIANA JOGA BASTAO MAGICO SHEILA INVISIVEL ATACA TIAMAT

%%
S	: INICIO COMANDOS FIM;
INICIO : {/**/};
COMANDOS:  ACAOGERAL COMANDOS| FIM;
ACAOGERAL: ACAOMENINOS | ACAODRAGAO
ACAODRAGAO: TIAMAT ATACA {executaJogadaTiamat();};
ACAOMENINOS : ACAOHANK | ACAOPRESTO | ACAOBOBBY | ACAODIANA | ACAOSHEILA;
ACAOHANK : HANK ATIRA FLECHA {executaJogadaMeninos(_HANK);};
ACAOPRESTO : PRESTO DISPARA RAIO ARCANO {executaJogadaMeninos(_PRESTO);};
ACAOBOBBY: BOBBY USA TACAPE {executaJogadaMeninos(_BOBBY);};
ACAODIANA: DIANA JOGA BASTAO MAGICO {executaJogadaMeninos(_DIANA);};
ACAOSHEILA: SHEILA INVISIVEL ATACA {executaJogadaMeninos(_SHEILA);};
FIM	: {/**/};
%%
/* codigo do usuario */

int
main(int argc, char **argv)
{
	FILE *arquivo;
	
	arquivo = fopen("entrada.txt","r");

	if (!arquivo) {
		printf("\nFalha ao abrir arquivo.\n");
		return -1;
	}
	
	// Seta o LEX para ler o arquivo1 atraves da variavel yyin 
	yyin = arquivo;
	
	// Realiza o parse para o arquivo
	do {
		yyparse();
	} while ( !feof(arquivo) );
	
	fclose(arquivo);

	return(0);
}

void yyerror(const char *s) {
	printf ("EEK, parse error!  Message: %s\n", s);
	exit(-1);
}
