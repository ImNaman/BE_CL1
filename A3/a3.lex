%{
#include <stdlib.h>
#include <string.h>
int lno = 1;
char name[20][20];
%}

%%
[0-9]+ {printf("%d \t\t %s \t\t NUMBER\n",lno,yytext);}
[-+*/] {printf("%d \t\t %s \t\t OPERATOR\n",lno,yytext);}
= {printf("%d \t\t %s \t\t ASSIGNMENT\n",lno,yytext);}
include |main| return {printf("%d \t\t %s \t\t KEYWORD \n",lno,yytext);}

int|float|char|double {printf("%d \t\t %s \t\t DATATYPE\n",lno,yytext);}
\n {lno++;}
# {printf("%d \t\t %s \t\t PREPROCESSOR\n",lno,yytext);}
; {printf("%d \t\t %s \t\t TERMINATOR \n",lno,yytext);}

\< {printf("%d \t\t %s \t\t LESS THAN",lno,yytext);}
\> {printf("%d \t\t %s \t\t GREATER THAN",lno,yytext);}
\{ {printf("%d \t\t %s \t\t START OF BLOCK",lno,yytext);}
\} {printf("%d \t\t %s \t\t END OF BLOCK",lno,yytext);}

\( {printf("%d \t\t %s \t\t OPEN",lno,yytext);}
\) {printf("%d \t\t %s \t\t CLOSE",lno,yytext);}
\[ {printf("%d \t\t %s \t\t OPEN",lno,yytext);}
\]  {printf("%d \t\t %s \t\t CLOSE",lno,yytext);}


, {printf("%d \t\t %s \t\t SEPERATOR\n",lno,yytext);}
printf|scanf {printf("%d \t\t %s \t\t LIBRARY FUNCTION\n",lno,yytext);}
(\"[^\"]*\") {printf("%d \t\t %s \t\t STRING\n",lno,yytext);}
([a-zA-Z0-9]+\.h) {printf("%d \t\t %s \t\t HEADER\n",lno,yytext);}
[a-zA-Z][a-zA-Z0-9]* {printf("%d \t\t %s \t\t IDENTIFIER\n",lno,yytext);}

%%

int main()
{
 char ifile[100];
 printf("\n enter input file name: ");
 scanf("%s",ifile);
 yyin = fopen(ifile,"r");

 yylex();
 return 0;
 }

 int yywrap()
 {
  return 1;
 }
