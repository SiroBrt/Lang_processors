// Jorge Ruesta, Siro Broton
// 100432547@alumnos.uc3m.es, 100496683@alumnos.uc3m.es
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define T_NUMBER 1001
#define T_OPERATOR 1002
#define T_VARIABLE 1003

void ParseYourGrammar(); /// Dummy Parser
void ParseAxiom();       /// Prototype for forward reference

struct s_tokens {
  int token;             // Here we store the current token/literal
  int old_token;         // Sometimes we need to check the previous token
  int number;            // The value of the number
  int old_number;        // old number value
  char variable_name[8]; /// variable name
  char old_var_name[8];  /// old variable name
  int token_val;         // the arithmetic operator
  int old_token_val;     // old arithmetic operator
};

struct s_tokens tokens = {0,  0,  0, -1,
                          "", "", 0, -1}; // contains initial values

int line_counter = 1;

void update_old_token() { /// Sometimes we need to check the previous token
  tokens.old_token = tokens.token;
  tokens.old_number = tokens.number;
  strcpy(tokens.old_var_name, tokens.variable_name); /// Copy variable names
  tokens.old_token_val = tokens.token_val;
}

void init_tokens() { ///  Not really neccesary
  tokens.token = 0;
  tokens.old_token = 0;
  tokens.number = 0;
  tokens.old_number = -1;
  strcpy(tokens.old_var_name, "");  /// erase old variable name
  strcpy(tokens.variable_name, ""); /// Erase variable name
  tokens.token_val = 0;
  tokens.old_token_val = -1;
}

int rd_lex() {
  int c;
  int cc;

  do {
    c = getchar();
    if (c == '\n')
      line_counter++; // info for rd_syntax_error()
  } while (c == ' ' || c == '\t' ||
           c == '\r'); /// \r is part of a newline in some Operating Systems

  if (isdigit(c)) { /// Token Number is [Digit]+
    ungetc(c,
           stdin); /// This returns one character to the standard input stream
    update_old_token();
    scanf("%d", &tokens.number);
    tokens.token = T_NUMBER;
    return (tokens.token); // returns the Token for Variable
  }

  if (isalpha(c)) { /// Token Variable of type Letter[Digit]?
    update_old_token();
    cc = getchar();
    if (isdigit(cc)) {
      sprintf(tokens.variable_name, "%c%c", c,
              cc); /// This copies the LetterDigit name in the variable name
    } else {
      ungetc(cc, stdin);
      sprintf(tokens.variable_name, "%c",
              c); /// This copies the single Letter name in the variable name
    }
    tokens.token = T_VARIABLE;
    return (tokens.token); // returns the Token for Number
  }

  if (c == '+' || c == '-' || c == '*' ||
      c == '/') { /// Remember that = is returned as a literal
    update_old_token();
    tokens.token_val = c;
    tokens.token = T_OPERATOR;
    return (tokens.token); // returns the Token for Arithmetic Operators
  }

  if (c == EOF) { /// End Of Archive detection for enhanced Batch Processing
    exit(0);
  }

  update_old_token();
  tokens.token = c;
  return (tokens.token); // returns a literal
}

void rd_syntax_error(int expected, int token, char *output) {
  fprintf(stderr, "ERROR in line %d ", line_counter);
  fprintf(stderr, output, expected, token);

  exit(0);
}

void MatchSymbol(int expected_token) {
  if (tokens.token != expected_token) {
    rd_syntax_error(expected_token, tokens.token,
                    "token %d expected, but %d was read");
    exit(0);
  } else {
    rd_lex(); /// read next Token
  }
}

// #define ParseLParen() 	MatchSymbol ('(') ; // More concise and
// efficient definitions #define ParseRParen() 	MatchSymbol (')') ; ///   rather
// than using functions
/// The actual recomendation is to use MatchSymbol in the code rather than
/// theese macros
void ParseExpression();

// First = {operator, =}
void ParseFactorization() {
  if (tokens.token == T_OPERATOR) { // F->opSS)
    char op = tokens.token_val;
    MatchSymbol(T_OPERATOR);
    ParseExpression();
    printf("%c", op);
    ParseExpression();
    printf(")");
    MatchSymbol(')');
  } else { // F->=varS)
    MatchSymbol('=');
    printf("%s", tokens.variable_name);
    MatchSymbol(T_VARIABLE);
    printf("=");
    ParseExpression();
    printf(")");
    MatchSymbol(')');
  }
}

// First = {operator, (, var, num, =}
void ParseExpression() {
  if (tokens.token == T_OPERATOR) { // S->opSS
    printf("(");
    char op = tokens.token_val;
    MatchSymbol(T_OPERATOR);
    ParseExpression();
    printf("%c", op);
    ParseExpression();
    printf(")");
  } else if (tokens.token == '(') { // S->(F
    printf("(");
    MatchSymbol('(');
    ParseFactorization();
  } else if (tokens.token == T_VARIABLE) { // S->var
    printf("%s", tokens.variable_name);
    MatchSymbol(T_VARIABLE);
  } else if (tokens.token == T_NUMBER) { // S->num
    printf("%d", tokens.number);
    MatchSymbol(T_NUMBER);
  } else { // S->=varS
    MatchSymbol('=');
    printf("(%s", tokens.variable_name);
    MatchSymbol(T_VARIABLE);
    printf("=");
    ParseExpression();
    printf(")");
  }
}
void ParseYourGrammar() { ParseExpression(); }

void ParseAxiom() {   /// Axiom ::= \n
  ParseYourGrammar(); /// Dummy Parser. Complete this with your design
  if (tokens.token == '\n') {
    printf("\n");
    MatchSymbol('\n');
  } else {
    rd_syntax_error(
        -1, tokens.token,
        "-- Unexpected Token (Expected:%d=None, Read:%d) at end of Parsing\n");
  }
}

int main(int argc, char **argv) {
  // Usage :  drLL -s  ==> evaluate a single Input Line
  //          drLL     ==> evalute multiple Input Lines until some error appears
  /// DO NOT MODIFY THE CODE INSIDE THE MAIN FUNCTION WITHOUT PERMISSION

  int flagMultiple = 1;

  if (argc >= 2) {
    if (strcmp("-s", argv[1]) == 0) {
      flagMultiple = 0;
    }
  }

  rd_lex(); /// Read first Token only once
  do {
    ParseAxiom();
    //		printf ("\n") ;
  } while (flagMultiple);

  exit(0);
}
