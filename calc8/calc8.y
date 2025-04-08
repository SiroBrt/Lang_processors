/*Jorge Ruesta, Siro Broton
100432547@alumnos.uc3m.es, 100496683@alumnos.uc3m.es
*/
%{ // SECTION 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  extern int yylex();
  extern int yyerror();

  char temp[2048];

#define FF fflush(stdout);

char *my_malloc(int nbytes) {
  char *p;
  static long int nb = 0;
  static int nv = 0;

  p = malloc(nbytes);
  if (p == NULL) {
    fprintf(stderr, "No memory available for %d bytes\n", nbytes);
    fprintf(stderr, "%ld bytes allocated in %d calls\n", nb, nv);
    exit(0);
  }
  nb += (long)nbytes;
  nv++;

  return p;
}

char *gen_code(char *nombre) { // this is roughly equivalent to strdup()
  char *p;
  int l;

  l = strlen(nombre) + 1;
  p = (char *)my_malloc(l);
  strcpy(p, nombre);

  return p;
}

char *to_string(int n) {
  sprintf(temp, "%d", n);

  return gen_code(temp);
}


char *char_to_string (int c) {
  sprintf(temp, "%c", c); // convert character to string
  return gen_code (temp) ;
}

char *int_to_string(int n) {
  sprintf(temp, "%d", n); // convert int to string

  return strdup(temp);    // strdup does the same as gen_code
}

typedef struct ASTnode t_node;

struct ASTnode {
  char *op; // simplified node information in form as a string
  int type; // leaf, unary or binary nodes (0/1/2)
  t_node *left;
  t_node *right;
};


// We change the %union by a struct

typedef struct s_attr {
  int value;
  int index;
  char *code;
  t_node *node;
} t_attr;


// Function to create a new AST node
t_node *createASTNode (char *op, int type, t_node *left, t_node *right) {
  t_node *node;
  node = (t_node*) malloc (sizeof (t_node));
  node->op = strdup (op); // duplicates string in memory
  node->type = type; // binary, unary or leaf node
  node->left = left;
  node->right = right;
  return node;
}


// Function to free AST
void freeAST (t_node *node) {
  if (node != NULL) {
    freeAST (node->left);
    freeAST (node->right);
    free (node->op);
    free (node);
  }
}


// Function to print AST in prefix notation
void printAST2Prefix (t_node *node) {
  if (node == NULL) {
    return ;
  } else if (node->type == 0) {
    printf ("%s ", node->op); // Leaf node
  } else if (node->type == 1) {
    printf ("( %s ", node->op); // Unary node
    printAST2Prefix (node->left);
    printf (") ");
  } else {
    printf ("( %s ", node->op); // Binary node
    printAST2Prefix (node->left);
    printAST2Prefix (node->right);
    printf (") ");
  }
}

#define YYSTYPE t_attr

%}

// Don't use the following system of declaring implicit attributes unless you
// are very confident about dealing with errors due to missing declarations In
// exams, we will always require the use of explicit attributes.

//%union {                //
//      int valor;	//  - numeric attribute
//      int index;	//  - index attribute to identify variables
//      char *cadena;	//  - string attribute to store the output
//}

// SECTION 2

%token NUMBER
%token VARIABLE

// Don't use the following system of declaring implicit attributes unless
// you are very confident about dealing with errors due to missing
// declarations In exams, we will always require the use of explicit
// attributes.

// %token  <valor>  NUMBER
// %token  <index> VARIABLE
// %type   <cadena>  expression term operand

%right '='       //  operator with the least precedence
%left '+' '-'    //
%left '*' '/'    //
%left UNARY_SIGN //  operator with the highest precedence

%%
                         // SECTION 3: Grammar - Semantic Section

axiom:          expression '\n'				{ printAST2Prefix($1.node);
                                        printf("\n"); }
                r_expr
            |   '@' expression '\n'		{ printAST2Prefix($2.node);
                                        printf("\n"); }
                r_expr
            ;


r_expr:         /* lambda */				{; }
            |   axiom					{; }
            ;

expression:     term					{ $$.node = $1.node; }

            |   VARIABLE '=' expression   		  { $$.node = createASTNode("setq", 2, createASTNode (char_to_string ($1.index+'a'), 0, NULL, NULL), $3.node); }
            |   expression '+' expression   		{ $$.node = createASTNode ("+", 2, $1.node, $3.node); }
            |   expression '-' expression   		{ $$.node = createASTNode ("-", 2, $1.node, $3.node); }
            |   expression '*' expression   		{ $$.node = createASTNode ("*", 2, $1.node, $3.node); }
            |   expression '/' expression   		{ $$.node = createASTNode ("/", 2, $1.node, $3.node); }
            ;

term:           operand	    				{ $$.node = $1.node; } 
            |   '+' operand %prec UNARY_SIGN		{ $$.node = $2.node; }
            |   '-' operand %prec UNARY_SIGN		{ $$.node = createASTNode ("-", 1, $2.node, NULL); }
            ;

operand:        VARIABLE				{ $$.node = createASTNode (char_to_string ($1.index+'a'), 0, NULL, NULL); }
            |   NUMBER					{ $$.node = createASTNode (int_to_string ($1.value), 0, NULL, NULL); }
            |   '(' expression ')'			{ $$.node = $2.node; }
            ;

%%

                        /* SECTION 4  C Code */
int n_line = 1;

int yyerror (char *message) {
    fprintf (stderr, "%s in line %d\n", message, n_line);
}


int yylex () {
    unsigned char c;

    do {
         c = getchar ();
    } while (c == ' ');

    if (c == '.' || (c >= '0' && c <= '9')) {
         ungetc (c, stdin);
         scanf ("%d", &yylval.value);
         return NUMBER;
    }

    if (c >= 'A' && c <= 'Z') {
         yylval.index = c - 'A';  
         return VARIABLE;
    }

    if (c >= 'a' && c <= 'z') {
         yylval.index = c - 'a';  
         return VARIABLE;
    }

    if (c == '\n')
          n_line++;
    return c;
}


int main () {
    yyparse ();
}
