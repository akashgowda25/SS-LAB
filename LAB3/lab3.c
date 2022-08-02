%{
	#include<stdio.h>
	#include<stdlib.h>
	int yylex();
	int yyerror();
%}

%token A B ENTER 

%%
start:S ENTER { printf("Valid String\n");exit(0);}
S : A S | B ;
%%

void main()
{

	printf("Enter the String :\n");
		yyparse();
}

int yyerror()
{
	printf("Invalid String");
	return 0;
}
