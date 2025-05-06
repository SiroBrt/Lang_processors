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
int is_global(char *) ;

char temp [2048] ;
char func_name [256] ;
int global_it;
char global_var [256][256] ;



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
%token WHILE         // token for keyword while
%token FOR           // token for keyword for
%token IF            // token for keyword if
%token ELSE          // token for keyword else
%token AND           // token for keyword and
%token OR            // token for keyword or
%token GEQ           // token for keyword greater equal
%token LEQ           // token for keyword lower equal
%token EQUAl         // token for keyword boolean equal
%token NEQ           // token for keyword not equal
%token PUTS          // token for keyword puts
%token IMPRIMIR      // token for keyword printf
%token RETURN        // token for keyword return



%right '='                    // last opertation to do 
%left OR
%left AND
%left EQUAl NEQ
%left '<' LEQ '>' GEQ
%left '+' '-'
%left '*' '/' '%'
%left UNARY_SIGN              // highest precedence

%%                            // Section 3 Grammar - Semantic Actions

axiom:        axiom_sentence ';'             { printf ("%s\n", $1.code) ; }
              r_axiom
            | function_rec                   { ; }
            ;

r_axiom:                                     { ; }
            | axiom                          { ; }
            ;

function_rec:                                { printf("(defun main () ");
                                               sprintf(func_name, "main") ; }
              MAIN '(' ')' '{' print_code '}'{ printf(")\n") ; } 
            | IDENTIF                        { printf("(defun %s (", $1.code) ;
                                               sprintf(func_name, "%s", $1.code) ; }
              '(' arg_def ')'                { printf(") ") ; }
              '{' print_code '}'             { printf(")\n\n") ; }
              function_rec      
            ;

arg_def:      arg_def_rec                    { printf("%s", $1.code) ; }
            |                                { ; }
            ;

arg_def_rec:  INTEGER IDENTIF ',' arg_def_rec{ sprintf(temp, "%s_%s %s", func_name, $2.code, $4.code) ;
                                               $$.code = gen_code(temp) ; }
            | INTEGER IDENTIF                { sprintf(temp, "%s_%s", func_name, $2.code) ; 
                                               $$.code = gen_code(temp) ; }
            ;

func_call:    IDENTIF '(' arg_passed ')'     { sprintf (temp, "(%s%s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }    
            ;

arg_passed:   arg_pas_rec                    { $$ = $1 ; }
            |                                { temp[0] = '\0' ;
                                               $$.code = gen_code(temp) ; }
            ;

arg_pas_rec:  expression ',' arg_pas_rec     { sprintf(temp, " %s%s", $1.code, $3.code) ;
                                               $$.code = gen_code(temp) ; }
            | expression                     { sprintf(temp, " %s", $1.code) ;
                                               $$.code = gen_code(temp) ; }
            ;

print_code:    body_code                     { printf("%s", $1.code) ;}
            ;

body_code:    control_sentence body_code     { sprintf (temp, "%s %s", $1.code, $2.code) ;
                                               $$.code = gen_code(temp) ; }
            | sentence ';' body_code         { sprintf (temp, "%s %s", $1.code, $3.code) ;
                                               $$.code = gen_code(temp) ; }
            | control_sentence               { $$ = $1 ; }
            | sentence ';'                   { $$ = $1 ; }
            ;

axiom_sentence:
              INTEGER ax_rec_def                { $$ = $2 ; }
            | IDENTIF '=' operand            { sprintf (temp, "(setf %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code(temp) ; }
            ;
            
sentence:     INTEGER rec_def                { $$ = $2 ; }
            | variable '=' expression        { sprintf (temp, "(setf %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code(temp) ; }
            | PUTS '(' STRING ')'            { sprintf (temp, "(print \"%s\")", $4.code) ;  
                                               $$.code = gen_code (temp) ; }
            | IMPRIMIR '(' STRING ',' rec_print ')' { $$ = $5 ; }
            | RETURN expression              { sprintf(temp, "(return-from %s %s)", func_name, $2.code) ; 
                                               $$.code = gen_code(temp) ; }
            | func_call                      { $$ = $1 ; }
            ; 

control_sentence:
              WHILE '(' expression ')' '{' body_code '}'
              { sprintf (temp, "(loop while %s do %s)", $3.code, $6.code) ;  
                $$.code = gen_code (temp) ; }
            | IF '(' expression ')' '{' body_code '}' 
              { sprintf (temp, "(if %s %s)", $3.code, $6.code) ;
                $$.code = gen_code (temp) ; }
            | IF '(' expression ')' '{' body_code '}' ELSE '{' body_code '}' 
              { sprintf (temp, "(if %s %s %s)", $3.code, $6.code, $10.code) ;
                $$.code = gen_code (temp) ; }
            | FOR '(' axiom_sentence ';' expression ';' IDENTIF '=' expression ')' '{' body_code '}' 
              { sprintf (temp, "%s (loop while %s do %s (setf %s %s))", $3.code , $5.code, $12.code, $7.code, $9.code) ;
                $$.code = gen_code (temp) ; }
            ;

rec_print:    expression ',' rec_print       { sprintf (temp, "(princ %s) %s",$1.code, $3.code);
                                               $$.code = gen_code (temp) ; }
            | STRING ',' rec_print           { sprintf (temp, "(princ \"%s\") %s",$1.code, $3.code);
                                               $$.code = gen_code (temp) ; }
            | expression                     { sprintf (temp, "(princ %s)",$1.code);
                                               $$.code = gen_code(temp) ; }
            | STRING                         { sprintf (temp, "(princ \"%s\")",$1.code);
                                               $$.code = gen_code(temp) ; }
            ;

ax_rec_def:   ax_definition ',' ax_rec_def   { sprintf (temp, "%s %s",$1.code, $3.code);
                                               $$.code = gen_code (temp) ; }
            | ax_definition                  { $$ = $1 ; }
            ;

ax_definition: IDENTIF                       { sprintf (temp, "(setq %s 0)", $1.code) ;
                                               sprintf(global_var[global_it], "%s", $1.code) ;
                                               global_it++;
                                               $$.code = gen_code(temp) ; }
            | IDENTIF '=' NUMBER             { sprintf (temp, "(setq %s %d)", $1.code, $3.value) ;
                                               sprintf(global_var[global_it], "%s", $1.code) ;
                                               global_it++;
                                               $$.code = gen_code(temp) ; }
            | IDENTIF '[' NUMBER ']'         { sprintf (temp, "(setq %s (make-array %d))", $1.code, $3.value) ;
                                               sprintf(global_var[global_it], "%s", $1.code) ;
                                               global_it++;
                                               $$.code = gen_code(temp) ; }
            ;
          
rec_def:      definition ',' rec_def         { sprintf (temp, "%s %s",$1.code, $3.code);
                                               $$.code = gen_code (temp) ; }
            | definition                     { $$ = $1 ; }
            ;

definition:   IDENTIF                        { sprintf (temp, "(setq %s_%s 0)", func_name, $1.code) ;
                                               $$.code = gen_code(temp) ; }
            | IDENTIF '=' NUMBER             { sprintf (temp, "(setq %s_%s %d)", func_name, $1.code, $3.value) ;
                                               $$.code = gen_code(temp) ; }
            | IDENTIF '[' NUMBER ']'         { sprintf (temp, "(setq %s_%s (make-array %d))", func_name, $1.code, $3.value) ;
                                               $$.code = gen_code(temp) ; }
            ;
          
expression:   term                           { $$ = $1 ; }
            | expression '+' expression      { sprintf (temp, "(+ %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression '-' expression      { sprintf (temp, "(- %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression '*' expression      { sprintf (temp, "(* %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression '/' expression      { sprintf (temp, "(/ %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression AND expression      { sprintf (temp, "(and %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression OR expression       { sprintf (temp, "(or %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | '!' expression %prec UNARY_SIGN{ sprintf (temp, "(not %s)", $2.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression NEQ expression      { sprintf (temp, "(/= %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression EQUAl expression    { sprintf (temp, "(= %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression '<' expression      { sprintf (temp, "(< %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression LEQ expression      { sprintf (temp, "(<= %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression '>'  expression     { sprintf (temp, "(> %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression GEQ expression      { sprintf (temp, "(>= %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            | expression '%' expression      { sprintf (temp, "(mod %s %s)", $1.code, $3.code) ;
                                               $$.code = gen_code (temp) ; }
            ;

term:         operand                        { $$ = $1 ; }                          
            | '+' operand %prec UNARY_SIGN   { $$ = $1 ; }
            | '-' operand %prec UNARY_SIGN   { sprintf (temp, "(- %s)", $2.code) ;
                                               $$.code = gen_code (temp) ; }    
            | '(' expression ')'             { $$ = $2 ; }
            | func_call                      { $$ = $1 ; }
            ;

operand:      variable                       { $$ = $1 ; }
            | NUMBER                         { sprintf (temp, "%d", $1.value) ;
                                               $$.code = gen_code (temp) ; }
            ;

variable:     IDENTIF                        { if (is_global($1.code)){
                                                 sprintf (temp, "%s", $1.code) ;
                                               } else{
                                                 sprintf (temp, "%s_%s", func_name, $1.code) ;
                                               }
                                               $$.code = gen_code (temp) ; }
            | IDENTIF '[' expression ']'     { if (is_global($1.code)){
                                                 sprintf (temp, "(aref %s %s)", $1.code, $3.code) ;
                                               } else{
                                                 sprintf (temp, "(aref %s_%s %s)", func_name, $1.code, $3.code) ;
                                               }
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
    "&&",          AND,
    "||",          OR,
    "<=",          LEQ,
    ">=",          GEQ,
    "==",          EQUAl,
    "!=",          NEQ,
    "while",       WHILE,
    "for",         FOR,
    "if",          IF,
    "else",        ELSE,
    "puts",        PUTS,
    "printf",      IMPRIMIR,
    "return",      RETURN,
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

int is_global(char *var){
  for (int i = 0; i < global_it; i++){
    if (strcmp(global_var[i], var) == 0){
      return 1;
    }
  }
  return 0;
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
