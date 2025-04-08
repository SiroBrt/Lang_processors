/*Jorge Ruesta, Siro Broton
100432547@alumnos.uc3m.es, 100496683@alumnos.uc3m.es
*/
%{                      /* SECTION 1 */ 
#include <stdio.h>
%} 

%union {               /* The type of the stack (of PDA) has dual character*/
   int value ;         /* - integer value */ 
   int index ;         /* - index to identify a variable */ 
}
                          /* SECTION 2 */ 
%token <value> NUMBER        /* All tokens have a type for the stack */
%token <index> VARIABLE
%type <value> expression    /* Non-Terminals also have a type */
%type <value> term operand
%right '='                  /* is the last operation to be performed */
%left  '+' '-'              /* lowest order of precedence */
%left  '*' '/'              /*  intermediate order of precedence */
%left  UNARY_SIGN           /*  highest order of precedence */
%% 
                   /* SECTION 3: Grammar - Semantic */
axiom: expression '\n'            { printf("\n") ; } 
             r_expr
     | VARIABLE '=' { printf ("variable %c \n", $1) ; } expression '\n' { printf ("%c !\n", $1) ; }
             r_expr 
     ; 

r_expr:            /* lambda */ 
          | axiom 
          ; 

expression: term                      { ; } 
          | expression '+' expression { printf(" +") ; } 
          | expression '-' expression { printf(" -") ; } 
          | expression '*' expression { printf(" *") ; }
          | expression '/' expression { printf(" /") ; }
          ;

term:     operand                     { ; }
       | '+' operand %prec UNARY_SIGN { ; }
       | '-' operand %prec UNARY_SIGN { printf(" negate") ; }
       ;

operand: VARIABLE                    { printf(" %c",$1 + 'A') ; $$ = $1 ; }
       | NUMBER                      { printf(" %d",$1) ; }
       | '(' expression ')'          { ; } 
       ; 


%%
			/* SECTION 4 : CODE */
int n_line = 1 ; 

int yyerror (char *message)
{ 
    fprintf (stderr, "%s in line %d\n", message, n_line) ; 
} 

int yylex () 
{ 
    unsigned char c ; 

    do { 
        c = getchar () ; 
    } while (c == ' ') ; 

    if (c == '.' || (c >= '0' && c <= '9')) {     
        ungetc (c, stdin) ; 
        scanf ("%d", &yylval.value) ; 
        return NUMBER ; 
    } 

    if (c >= 'A' && c <= 'Z') { 
        yylval.index = c - 'A'; /* substract from c ascii value of A */ 
        return VARIABLE ; 
    } 

    if (c >= 'a' && c <= 'z') { 
        yylval.index = c - 'a'; /* substract from c ascii value of a */ 
        return VARIABLE ; 
    } 
    
    if (c == '\n') n_line++ ; 
        
    return c ; 
}

int main ()
{ 
    yyparse () ;
}
