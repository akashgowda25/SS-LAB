//program to recognize valid arithmetic expression and count the no of id's & op's

%{
	#include<stdio.h>
	int id=0,op=0,br=0;
%}

%%
[0-9]+ { id++; }
[+*]   { op++;}
[-/%]  { op--; }
"("    { br++;}
")"    { br--; }
. ;
%%

int yywrap() {}

int main()
{
	printf("Enter the expression \n");
	yylex();
	
	if(br==0 && id==op+1){
		printf("Valid Expression\n");
		 printf(" identifier count is %d\n",id);
		 printf(" operator count is %d ",op);
		}
	else 
		printf("Invalid Expression \n");
	return 0;
}
