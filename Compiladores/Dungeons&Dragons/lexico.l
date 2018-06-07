%{
#include <stdio.h>
#include "sintatico.tab.h"
#include "acoes.h"
%}


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
{token_ACAOHANK} {executaJogadaMeninos(_HANK);}
{token_ACAOPRESTO} {executaJogadaMeninos(_PRESTO);}
{token_ACAOBOBBY} {executaJogadaMeninos(_BOBBY);}
{token_ACAODIANA} {executaJogadaMeninos(_DIANA);}
{token_ACAOSHEILA} {executaJogadaMeninos(_SHEILA);}
{token_ACAODODRAGAO} {executaJogadaTiamat();}
%%