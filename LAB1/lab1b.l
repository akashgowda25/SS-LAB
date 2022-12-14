//Program to evaluate valid arithmetic expression

%{
	#include "y.tab.h"
	extern int yylval;
%}

%%
[0-9]+ 	{ yylval=atoi(yytext); return num;}
[+|-|*|/] 	{ return yytext[0];}
"(" 		{ return yytext[0];}
")" 		{ return yytext[0];}
[\n] 		{ return ENTER;}
.  		{ return yytext[0];}
%%

