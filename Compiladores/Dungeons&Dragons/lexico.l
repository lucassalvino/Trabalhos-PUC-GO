%{
	#include <stdio.h>
	#include "sintatico.tab.h"
	extern int yylval;
%}

delim [ \t\n] 

token_hank HANK
token_atira ATIRA
token_flecha FLECHA
token_presto PRESTO
token_dispara DISPARA
token_raio RAIO
token_arcano ARCANO
token_bobby BOBBY
token_usa USA
token_tacape TACAPE
token_diana DIANA
token_joga JOGA
token_bastao BASTAO
token_magico MAGICO
token_sheila SHEILA
token_invisivel INVISIVEL
token_ataca ATACA
token_tiamate TIAMAT
%%
delim {/**/}

{token_hank}	{return HANK;}
{token_atira}	{return ATIRA;}
{token_flecha} 	{return FLECHA;}
{token_presto}  {return PRESTO;}
{token_dispara} {return DISPARA;}
{token_raio}    {return RAIO;}
{token_arcano}  {return ARCANO;}
{token_bobby} {return BOBBY;}
{token_usa} {return USA;}
{token_tacape} {return TACAPE;}
{token_diana} {return DIANA;}
{token_joga} {return JOGA;}
{token_bastao} {return BASTAO;}
{token_magico} {return MAGICO;}
{token_sheila} {return SHEILA;}
{token_invisivel} {return INVISIVEL;}
{token_ataca} {return ATACA;}
{token_tiamate} {return TIAMAT;}
%%