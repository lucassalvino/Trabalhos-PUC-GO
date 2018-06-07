%{
	#include <stdio.h>
	#include <stdlib.h>
	extern FILE*yyin;
	extern int yylex();
	void yyerror (const char *s);
%}

%start batalha
%token HANK ATIRA FLECHA
%token PRESTO DISPARA RAIO ARCANO
%token BOBBY USA TACAPE
%token DIANA JOGA BASTAO MAGICO
%token SHEILA INVISIVEL ATACA TIAMAT
%left FIM

%%
batalha : LOOPPRINCIPAL FIM;
LOOPPRINCIPAL : ACAODOSMENINOS
			  | ACAODODRAGAO
			  ;
ACAODODRAGAO : TIAMAT ATACA;
ACAODOSMENINOS : ACAOHANK | ACAOPRESTO | ACAOBOBBY | ACAODIANA | ACAOSHEILA 
ACAOHANK : HANK ATIRA FLECHA;
ACAOPRESTO : PRESTO DISPARA RAIO ARCANO;
ACAOBOBBY : BOBBY USA TACAPE;
ACAODIANA : DIANA JOGA BASTAO MAGICO;
ACAOSHEILA : SHEILA INVISIVEL ATACA;
%%

void yyerror(const char *s){
	printf("Erro aqui: %s", s);
	exit(666);
}

int main(int argc, char ** argv){
	FILE * arq;
	arq = fopen("entrada.txt", "r");
	if(!arq){
		printf("Arquivo de entrada nao encontrado!");
		return 666;
	}
	yyin = arq;
	do{
		yyparse();	
	}while(!feof(arq));
	fclose(arq);
	return 0;
}