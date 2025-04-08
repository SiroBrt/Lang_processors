%{                                /* Seccion 1 Declaraciones de C-bison */
#include <stdio.h>
#define YYSTYPE double            /* tipo de la pila del parser           */
%}
%token NUMERO                     /* Seccion 2 Declaraciones de bison      */
%token VARIABLE
%left '+' '-'     /* menor orden de precedencia */
%left '*' '/'     /* orden de precedencia intermedio */
%left SIGNO_UNARIO /* define la mayor precedencia, y nuevo token */
%%
                                  /* Seccion 3 Gramatica - Semantico      */
axioma:       expresion '\n' { printf ("Expresion=%lf\n", $1) ; }    r_expr
            | assign '\n'    { printf ("Assigned %lf\n", $1) ; }    r_expr
            ;

r_expr:                    /* lambda */
            | axioma
            ;

assign:       VARIABLE '=' expresion   { $$ = $3 ; }
            ;

expresion:    operando                 { $$  = $1; }
            | VARIABLE                 { $$  = $1; }
            | expresion '+' expresion  { $$  = $1 + $3; }
            | expresion '-' expresion  { $$  = $1 - $3; }
            | expresion '*' expresion  { $$  = $1 * $3; }
            | expresion '/' expresion  { $$  = $1 / $3; }
            ;

operando:     NUMERO                                    { $$ = $1; }
            | '+' NUMERO %prec SIGNO_UNARIO             { $$ = $2; }
            | '-' NUMERO %prec SIGNO_UNARIO             { $$ = -$2; }
            | '(' expresion ')'                         { $$ = $2; }
            ;
%%
                                         /* Seccion 4  Codigo en C    */
int n_linea= 1 ;

int yyerror (char *mensaje)
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_linea) ;
}

/* suprimir la funcion yylex () si se usa flex */
///*
/*int yylex ()
{
    unsigned char c ;

    do {
         c = getchar () ;
    } while (c==' ') ;

    if (c == '.' || (c >= '0' && c <= '9')) {
         ungetc (c, stdin) ;
         scanf ("%lf", &yylval) ;
         return NUMERO ;
    }
    if (c >= 'a' && c <= 'z') {
         ungetc (c, stdin) ;
         scanf ("%s", &yylval) ;
         return VARIABLE ;
    }

    if (c == '\n')
           n_linea++ ;

    return c ;
}
*/

int main ()
{
    yyparse () ;
}
