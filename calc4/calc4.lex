%{                            /* Primera Seccion */
#include "calc4.tab.h"        /* Cabecera con decl. de token etc. */
extern int n_linea;
%}
%%                            /* Segunda Seccion */
[ \t]                    { ; } /* ignora espacios y tabuladores */
[0-9]+\.?|[0-9]*\.[0-9]+ { sscanf (yytext, "%lf", &yylval); return (NUMERO); }
[a-zA-z][a-zA-z0-9]*     { sscanf (yytext, "%s", &yylval); return (VARIABLE); }
\n                       { n_linea++; return ('\n'); }
.                        { return (yytext [0]); }   /* literales */
%%                            /* Tercera Seccion */
int yywrap ()     /* se incluye para evitar un error de compilacion */
{
    return (0) ; /* para el control de fin de fichero */
}
