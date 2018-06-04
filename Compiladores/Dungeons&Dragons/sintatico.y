%
{
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	#include <iostream>

	extern FILE *yyin;
	extern int yylex();
	void yyerror (const char * s);
}
%

%token HANK
%token ATIRA
%token FLECHA
%token PRESTO
%token DISPARA
%token RAIO
%token ARCANO
%token BOBBY
%token USA
%token TACAPE
%token DIANA
%token JOGA
%token BASTAO
%token MAGICO
%token SHEILA
%token INVISIVEL
%token ATACA
%token TIAMAT


%%
S : LOOPPRINCIPAL;
LOOPPRINCIPAL : ACAODOSMENINOS | ACAODODRAGAO | LOOPPRINCIPAL;
ACAODODRAGAO : TIAMAT ATACA;
ACAODOSMENINOS : ACAOHANK | ACAOPRESTO | ACAOBOBBY | ACAODIANA | ACAOSHEILA 
ACAOHANK : HANK ATIRA FLECHA;
ACAOPRESTO : PRESTO DISPARA RAIO ARCANO;
ACAOBOBBY : BOBBY USA TACAPE;
ACAODIANA : DIANA JOGA BASTAO MAGICO;
ACAOSHEILA : SHEILA INVISIVEL ATACA;
%%

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