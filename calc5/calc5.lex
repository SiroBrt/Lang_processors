/*Jorge Ruesta, Siro Broton
100432547@alumnos.uc3m.es, 100496683@alumnos.uc3m.es
*/
%{                            /* Primera Seccion */
#include "calc52.tab.h"        /* Cabecera con decl. de token etc. */
extern int n_line;
%}
%%                            /* Segunda Seccion */
[ \t]                    { ; } /* ignora espacios y tabuladores */
[0-9]+\.?|[0-9]*\.[0-9]+ { sscanf (yytext, "%lf", &yylval); return (NUMBER); }
[a-zA-z]                 { sscanf (yytext, "%s", &yylval); return (VARIABLE); }
\n                       { n_line++; return ('\n'); }
.                        { return (yytext [0]); }   /* literales */
%%                            /* Tercera Seccion */
int yywrap ()     /* se incluye para evitar un error de compilacion */
{
    return (0) ; /* para el control de fin de fichero */
}
