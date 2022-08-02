//program to recognize valid identifier ,operators and constants  in given file

%{
	#include "y.tab.h"
%}

%%
"include"|"stdio.h"|"int"|"float"|"printf"|"scanf"|"main"|"void"|"return" { printf("Keyword %s\n",yytext); return KEY; }
[a-zA-Z_]+[a-zA-Z0-9_]* { printf("Identifier %s\n",yytext); return ID; }
[+|*|-|/|=|<|>]|"<="|">="|"!=" { printf("Operator %s\n",yytext); return OP; }
. ;
%%

