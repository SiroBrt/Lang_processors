/*Jorge Ruesta, Siro Broton
100432547@alumnos.uc3m.es, 100496683@alumnos.uc3m.es
*/
%{                          // SECTION 1 Declarations for C-Bison
#include <stdio.h>
#include <ctype.h>            // tolower()
#include <string.h>           // strcmp() 
#include <stdlib.h>           // exit()

#define FF fflush(stdout);    // to force immediate printing 

int yylex () ;
void yyerror () ;
char *my_malloc (int) ;
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;

char temp [2048] ;
char declarations [2048] ;


// Abstract Syntax Tree (AST) Node Structure

typedef struct ASTnode t_node ;

struct ASTnode {
    char *op ;
    int type ;		// leaf, unary or binary nodes
    t_node *left ;
    t_node *right ;
} ;


// Definitions for explicit attributes

typedef struct s_attr {
    int value ;    // - Numeric value of a NUMBER 
    char *code ;   // - to pass IDENTIFIER names, and other translations 
    t_node *node ; // - for possible future use of AST
} t_attr ;

#define YYSTYPE t_attr     // stack of PDA has type t_attr

%}

// Definitions for explicit attributes

%token NUMBER        
%token IDENTIF       // Identifier=variable
%token INTEGER       // token for integer type
%token STRING        // token for string type
%token MAIN          // token for keyword main 
%token IF            // token for keyword if
%token WHILE         // token for keyword while
%token LOOP          // token for part of while
%token DO            // token for part of while
%token PRINT         // token for keyword print
%token PRINC         // token for keyword princ
%token SETQ          // token for keyword setq
%token SETF          // token for keyword setf
%token AND           // token for operator and
%token OR            // token for operator or
%token NOT           // token for operator not
%token GEQ           // token for operator greater equal
%token LEQ           // token for operator lower equal
%token NEQ           // token for operator not equal
%token MOD           // token for operator modulus
%token PROGN         // token for keyword progn
%token DEFUN         // token for keyword function
%token RETURN1       // token for expression return-from
%token RETURN2       // token for expression return-from



%left OR
%left AND
%left '=' NEQ
%left '<' LEQ '>' GEQ
%left '+' '-'
%left '*' '/' MOD
%left UNARY_SIGN              // highest precedence

%%                            // Section 3 Grammar - Semantic Actions

axiom:        '(' ax_sentence ')'            { ; }
              r_axiom                        { ; }
            ;

r_axiom:                                     { ; }
            | axiom                          { ; }
            ;

ax_sentence:  SETF IDENTIF operand           { printf ("%s %s !\n", $3.code, $2.code) ; }
            | SETQ IDENTIF operand           { printf ("variable %s %s %s !\n", $2.code, $3.code, $2.code) ; }
            | DEFUN IDENTIF '(' arg_def ')' body
              { printf ("%s\n: %s recursive\n%s\n%s ;\n", declarations, $2.code, $4.code, $6.code) ;
                sprintf(declarations, "") ; }
            | DEFUN MAIN '(' ')' body        { printf ("%s\n: main\n%s ;\n", declarations, $5.code) ; }
            | IDENTIF arguments              { printf ("%s%s", $2.code, $1.code) ; }
            | MAIN                           { printf ("main") ; }
            ;

body:         '(' sentence ')' body          { sprintf (temp, "%s %s", $2.code, $4.code) ;
                                               $$.code = gen_code(temp) ; }
            | '(' sentence ')'               { $$ = $2 ; }
            ;

sentence:     '-' term %prec UNARY_SIGN      { sprintf (temp, "%s negate", $2.code) ;
                                               $$.code = gen_code (temp) ; }
            | NOT term %prec UNARY_SIGN      { sprintf (temp, "%s 0=", $2.code) ;
                                               $$.code = gen_code (temp) ; }
            | '*' term term                  { sprintf (temp, "%s %s *", $2.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | '/' term term                  { sprintf (temp, "%s %s /", $2.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | MOD term term                  { sprintf (temp, "%s %s mod", $2.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | '+' term term                  { sprintf (temp, "%s %s +", $2.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | '-' term term                  { sprintf (temp, "%s %s -", $2.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | '<' term term                  { sprintf (temp, "%s %s <", $2.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | LEQ term term                  { sprintf (temp, "%s %s <=", $2.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | '>' term term                  { sprintf (temp, "%s %s >", $2.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | GEQ term term                  { sprintf (temp, "%s %s >=", $2.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | '=' term term                  { sprintf (temp, "%s %s =", $2.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | NEQ term term                  { sprintf (temp, "%s %s = 0=", $2.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | AND term term                  { sprintf (temp, "%s %s and", $2.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | OR term term                   { sprintf (temp, "%s %s or", $2.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | SETF IDENTIF term              { sprintf (temp, "%s %s !", $3.code, $2.code) ;
                                               $$.code = gen_code (temp) ; }
            | SETQ IDENTIF term              { sprintf (temp, "%s %s !", $3.code, $2.code) ;
                                               sprintf(declarations, "%s\nvariable %s", declarations, $2.code) ;
                                               $$.code = gen_code (temp) ; }
            | PROGN body                     { $$ = $2 ; }
            | PRINT STRING                   { sprintf (temp, ".\" %s\"", $2.code) ;
                                               $$.code = gen_code (temp) ; }
            | PRINC term                      { sprintf (temp, "%s .", $2.code) ;
                                               $$.code = gen_code (temp) ; }
            | PRINC STRING                   { sprintf (temp, ".\" %s\"", $2.code) ;
                                               $$.code = gen_code (temp) ; }
            | IF '(' sentence ')' '(' branch ')' '(' branch')' { sprintf (temp, "%s IF %s ELSE %s THEN", $3.code, $6.code, $9.code) ;
                                               $$.code = gen_code (temp) ; }
            | IF '(' sentence ')' '(' branch ')' { sprintf (temp, "%s IF %s THEN", $3.code, $6.code) ;
                                               $$.code = gen_code (temp) ; }
            | LOOP WHILE '(' sentence ')' DO  body { sprintf (temp, "BEGIN %s WHILE %s REPEAT", $4.code, $7.code) ;
                                               $$.code = gen_code (temp) ; }
            | IDENTIF arguments              { sprintf (temp, "%s%s", $2.code, $1.code) ;
                                               $$.code = gen_code (temp) ; }
            | MAIN                           { sprintf (temp, "main") ;
                                               $$.code = gen_code (temp) ; }
            | RETURN1 '-' RETURN2 IDENTIF term { sprintf (temp, "%s EXIT", $5.code) ;
                                               $$.code = gen_code (temp) ; }
            ;

arg_def:      IDENTIF  arg_def               { sprintf (temp, "%s %s ! ", $2.code, $1.code) ;
                                               sprintf(declarations, "%s\nvariable %s", declarations, $1.code) ;
                                               $$.code = gen_code (temp) ; }
            |                                { temp[0] = '\0' ;
                                               $$.code = gen_code(temp) ; }
            ;

arguments:    term  arguments             { sprintf (temp, "%s %s", $1.code, $2.code) ;
                                               $$.code = gen_code (temp) ; }
            |                                { temp[0] = '\0' ;
                                               $$.code = gen_code(temp) ; }
            ;

branch:       body                           { $$ = $1 ; }
            | sentence                       { $$ = $1 ; }
            ;

term:         operand                        { $$ = $1 ; }
            | '(' sentence ')'               { $$ = $2 ; }
            ;

operand:      IDENTIF                        { sprintf (temp, "%s @", $1.code) ;
                                               $$.code = gen_code (temp) ; }
            | NUMBER                         { sprintf (temp, "%d", $1.value) ;
                                               $$.code = gen_code (temp) ; }
            ;


%%                            // SECTION 4    Code in C

int n_line = 1 ;

void yyerror (char *message)
{
    fprintf (stderr, "%s in line %d\n", message, n_line) ;
    printf ( "\n") ;
}

char *int_to_string (int n)
{
    sprintf (temp, "%d", n) ;
    return gen_code (temp) ;
}

char *char_to_string (char c)
{
    sprintf (temp, "%c", c) ;
    return gen_code (temp) ;
}

char *my_malloc (int nbytes)     // reserve n bytes of dynamic memory 
{
    char *p ;
    static long int nb = 0 ;     // used to count the memory  
    static int nv = 0 ;          // required in total 

    p = malloc (nbytes) ;
    if (p == NULL) {
      fprintf (stderr, "No memory left for additional %d bytes\n", nbytes) ;
      fprintf (stderr, "%ld bytes reserved in %d calls \n", nb, nv) ;  
      exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}



/***************************************************************************/
/***************************** Keyword Section *****************************/
/***************************************************************************/

typedef struct s_keyword { // for the reserved words of C  
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = {     // define the keywords 
    "main",        MAIN,      // and their associated token  
    "int",         INTEGER,
    "print",       PRINT,
    "princ",       PRINC,
    "setq",        SETQ,
    "setf",        SETF,
    "if",          IF,
    "while",       WHILE,
    "loop",        LOOP,
    "do",          DO,
    "defun",       DEFUN,
    "and",         AND,
    "or",          OR,
    "not",         NOT,
    "/=",          NEQ,
    "<=",          LEQ,
    ">=",          GEQ,
    "mod",         MOD,
    "progn",       PROGN,
    "return",      RETURN1,
    "from",        RETURN2,
    NULL,          0          // 0 to mark the end of the table
} ;

t_keyword *search_keyword (char *symbol_name)
{                       // Search symbol names in the keyword table
                        // and return a pointer to token register
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
                                   // strcmp(a, b) returns == 0 if a==b  
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************** Section for the Lexical Analyzer  ********************/
/***************************************************************************/

char *gen_code (char *name)   // copy the argument to an  
{                             // string in dynamic memory  
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}


int yylex ()
{
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char expandable_ops [] =  "!<=>|%&/+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do { 
        c = getchar () ; 
        if (c == '#') { // Ignore the lines starting with # (#define, #include) 
            do { // WARNING that it may malfunction if a line contains # 
                c = getchar () ; 
            } while (c != '\n') ; 
        } 
        if (c == '/') { // character / can be the beginning of a comment. 
            cc = getchar () ; 
            if (cc != '/') { // If the following char is / is a comment, but.... 
                ungetc (cc, stdin) ; 
            } else { 
                c = getchar () ; // ... 
                if (c == '@') { // Lines starting with //@ are transcribed
                    do { // This is inline code (embedded code in C).
                        c = getchar () ; 
                        putchar (c) ; 
                    } while (c != '\n') ; 
                } else { // ==> comment, ignore the line 
                    while (c != '\n') { 
                        c = getchar () ; 
                    } 
                } 
            } 
        } 
        if (c == '\n') 
            n_line++ ; 
    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("WARNING: string with more than 255 characters in line %d\n", n_line) ; 
        } // we should read until the next “, but, what if it is  missing? 
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
//         printf ("\nDEV: NUMBER %d\n", yylval.value) ;       
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
        temp_str [i++] = tolower (c) ; // ALL TO SMALL LETTERS
        c = getchar () ; 
    } 
    temp_str [i] = '\0' ; // End of string  
    ungetc (c, stdin) ; // return excess char  

    yylval.code = gen_code (temp_str) ; 
    symbol = search_keyword (yylval.code) ;
    if (symbol == NULL) { // is not reserved word -> iderntifrier  
//               printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
//               printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return (symbol->token) ;
        }
    }

    if (strchr (expandable_ops, c) != NULL) { // // look for c in expandable_ops
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // although it is not used   
            return (symbol->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}


int main ()
{
    yyparse () ;
}
