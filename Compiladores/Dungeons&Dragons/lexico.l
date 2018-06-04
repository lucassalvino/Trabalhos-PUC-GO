%{
#include <stdio.h>
#include "sintatico.tab.h"
#include "acoes.h"

}%


delim [\t\n]
token_ACAOHANK ACAOHANK
token_ACAOPRESTO ACAOPRESTO
token_ACAOBOBBY ACAOBOBBY
token_ACAODIANA ACAODIANA
token_ACAOSHEILA ACAOSHEILA
token_ACAODODRAGAO ACAODODRAGAO
erro .

%%
{erro} {printf("Erro Lexico. Caracter %c\n", yytext[0]);}
{token_ACAOHANK} {executaJogadaMeninos(HANJK);}
{token_ACAOPRESTO} {executaJogadaMeninos(PRESTO);}
{token_ACAOBOBBY} {executaJogadaMeninos(BOBBY);}
{token_ACAODIANA} {executaJogadaMeninos(DIANA);}
{token_ACAOSHEILA} {executaJogadaMeninos(SHEILA);}
{token_ACAODODRAGAO} {executaJogadaTiamat();}
%%