/*Jorge Ruesta, Siro Broton
100432547@alumnos.uc3m.es, 100496683@alumnos.uc3m.es
*/
%{                      // SECTION 1 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yylex () ;
extern int yyerror () ;

char temp [2048] ;

#define FF fflush(stdout);

char *my_malloc (int nbytes)
{
    char *p ;
    static long int nb = 0;
    static int nv = 0 ;
    
    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No memory available for %d bytes\n", nbytes) ;
        fprintf (stderr, "%ld bytes allocated in %d calls\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;
    
    return p ;
}


char *gen_code (char *nombre)     // this is roughly equivalent to strdup()
{
    char *p ;
    int l ;
    
    l = strlen (nombre)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, nombre) ;
    
    return p ;
}


char *to_string (int n)
{
    sprintf(temp, "%d", n);
    
    return gen_code (temp);

}

// We change the %union by a struct

typedef struct s_attr {
        int value ;
	int index ;
        char *code ;
} t_attr ;

#define YYSTYPE t_attr


%}

// Don't use the following system of declaring implicit attributes unless you are very confident about dealing with errors due to missing declarations
// In exams, we will always require the use of explicit attributes.

//%union {                //  
//      int valor ;	//  - numeric attribute
//      int index ;	//  - index attribute to identify variables
//      char *cadena ;	//  - string attribute to store the output
//}

                        // SECTION 2 

%token  NUMBER  
%token  VARIABLE

// Don't use the following system of declaring implicit attributes unless you are very confident about dealing with errors due to missing declarations
// In exams, we will always require the use of explicit attributes.

// %token  <valor>  NUMBER    
// %token  <index> VARIABLE
// %type   <cadena>  expression term operand

%right  '='             //  operator with the least precedence
%left   '+' '-'         //  
%left   '*' '/'         //  
%left   UNARY_SIGN	//  operator with the highest precedence 
%%
                        // SECTION 3: Grammar - Semantic Section


axiom:          expression '\n'				{ printf("%s\n",$1.code); }
                r_expr					{ ; }
            |   VARIABLE '=' expression '\n'		{ printf("= %c %s\n",$1.index + 'a',$3.code); }
                r_expr					{ ; }
            ;


r_expr:         /* lambda */				{ ; }
            |   axiom					{ ; }
            ;

expression:     term					{ $$.code = $1.code; }
            |   expression '+' expression   		{ sprintf(temp, "+ %s%s", $1.code, $3.code);
                                                  $$.code = gen_code(temp); }
            |   expression '-' expression   		{ sprintf(temp, "- %s%s", $1.code, $3.code);
                                                  $$.code = gen_code(temp); }
            |   expression '*' expression   		{ sprintf(temp, "* %s%s", $1.code, $3.code);
                                                  $$.code = gen_code(temp); }
            |   expression '/' expression   		{ sprintf(temp, "/ %s%s", $1.code, $3.code);
                                                  $$.code = gen_code(temp); }
            ;

term:           operand	    				{ $$.code = $1.code; } 
            |   '+' operand %prec UNARY_SIGN		{ $$.code = $2.code; }
            |   '-' operand %prec UNARY_SIGN		{ sprintf(temp, "-%s",$2.code);
                                                  $$.code = gen_code(temp);} 
            ;

operand:        VARIABLE				{ sprintf(temp, "%c ", $1.index+'a');
                                  $$.code = gen_code(temp); }
            |   NUMBER					{ sprintf(temp, "%d ", $1.value);
                                  $$.code = gen_code(temp); }
            |   '(' expression ')'			{ $$.code = $2.code; }
            ;

%%

                        /* SECTION 4  C Code */
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
         yylval.index = c - 'A' ;  
         return VARIABLE ;
    }

    if (c >= 'a' && c <= 'z') {
         yylval.index = c - 'a' ;  
         return VARIABLE ;
    }

    if (c == '\n')
          n_line++ ;
    return c ;
}


int main ()
{
    yyparse () ;
}

