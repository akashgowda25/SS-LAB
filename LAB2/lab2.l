//program to recognoze strings ending with b using the grammmar a^nb

%{
	#include "y.tab.h"
%}

%%
[a] {return A;}
[b] {return B;}
[\n] {return ENTER;}
%%
