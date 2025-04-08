/*Jorge Ruesta, Siro Broton
100432547@alumnos.uc3m.es, 100496683@alumnos.uc3m.es
*/
%{                      /* SECTION 1 */ 
#include <stdio.h>
double memory [52] ;    /* A memory area is defined for the variables */ 
%} 

%union {              /* The type of the stack (of PDA) has dual character*/
   double value ;      /* - real numeric value */ 
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
axiom: expression '\n'            { printf ("Expression=%lf\n", $1) ; } 
             r_expr
     | VARIABLE '=' expression '\n' { memory [$1] = $3;
                                      if($1 < 26){
                                        printf ("%c=%lf\n", $1+'a', $3);
                                      } else{
                                        printf ("%c=%lf\n", $1-26+'A', $3);
                                      }
                                      }
             r_expr 
     ; 

r_expr:            /* lambda */ 
      | axiom 
      ; 

expression: term                      { $$ = $1 ; } 
          | expression '+' expression { $$ = $1 + $3 ; } 
          | expression '-' expression { $$ = $1 - $3 ; } 
          | expression '*' expression { $$ = $1 * $3 ; }
          | expression '/' expression { $$ = $1 / $3 ; }
          ;

term:     operand                     { $$ = $1 ; }
       | '+' operand %prec UNARY_SIGN { $$ = $2 ; } 
       | '-' operand %prec UNARY_SIGN { $$ = -$2 ; }
       ;

operand: VARIABLE                    { $$ = memory [$1] ; }
       | NUMBER                      { $$ = $1 ; }
       | '(' expression ')'          { $$ = $2 ; } 
       ; 


%%
			/* SECTION 4 : CODE */

int n_line = 1 ; 

int yyerror (char *message)
{ 
    fprintf (stderr, "%s in line %d\n", message, n_line) ; 
} 

// Delete or comment function yylex in case you want to use flex
int yylex () 
{ 
    unsigned char c ; 

    do { 
        c = getchar () ; 
    } while (c == ' ') ; 

    if (c == '.' || (c >= '0' && c <= '9')) {     
        ungetc (c, stdin) ; 
        scanf ("%lf", &yylval.value) ; 
        return NUMBER ; 
    } 

    if (c >= 'A' && c <= 'Z') { 
        yylval.index = c - 'A' + 26; // substract from c ascii value of A  
        return VARIABLE ; 
    } 

    if (c >= 'a' && c <= 'z') { 
        yylval.index = c - 'a' ; // substract from c ascii value of a  
        return VARIABLE ; 
    } 
    
    if (c == '\n') n_line++ ; 
        
    return c ; 
}

int main ()
{ 
    yyparse () ;
}
