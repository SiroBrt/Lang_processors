/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "trad3.y"
                          // SECTION 1 Declarations for C-Bison
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
char func_prefix [256];


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


#line 114 "trad3.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    IDENTIF = 259,                 /* IDENTIF  */
    INTEGER = 260,                 /* INTEGER  */
    STRING = 261,                  /* STRING  */
    MAIN = 262,                    /* MAIN  */
    WHILE = 263,                   /* WHILE  */
    FOR = 264,                     /* FOR  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    AND = 267,                     /* AND  */
    OR = 268,                      /* OR  */
    GEQ = 269,                     /* GEQ  */
    LEQ = 270,                     /* LEQ  */
    EQUAl = 271,                   /* EQUAl  */
    NEQ = 272,                     /* NEQ  */
    PUTS = 273,                    /* PUTS  */
    IMPRIMIR = 274,                /* IMPRIMIR  */
    RETURN = 275,                  /* RETURN  */
    UNARY_SIGN = 276               /* UNARY_SIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIF = 4,                    /* IDENTIF  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_MAIN = 7,                       /* MAIN  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_AND = 12,                       /* AND  */
  YYSYMBOL_OR = 13,                        /* OR  */
  YYSYMBOL_GEQ = 14,                       /* GEQ  */
  YYSYMBOL_LEQ = 15,                       /* LEQ  */
  YYSYMBOL_EQUAl = 16,                     /* EQUAl  */
  YYSYMBOL_NEQ = 17,                       /* NEQ  */
  YYSYMBOL_PUTS = 18,                      /* PUTS  */
  YYSYMBOL_IMPRIMIR = 19,                  /* IMPRIMIR  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_21_ = 21,                       /* '='  */
  YYSYMBOL_22_ = 22,                       /* '<'  */
  YYSYMBOL_23_ = 23,                       /* '>'  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '-'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_28_ = 28,                       /* '%'  */
  YYSYMBOL_UNARY_SIGN = 29,                /* UNARY_SIGN  */
  YYSYMBOL_30_ = 30,                       /* ';'  */
  YYSYMBOL_31_ = 31,                       /* '('  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* '{'  */
  YYSYMBOL_34_ = 34,                       /* '}'  */
  YYSYMBOL_35_ = 35,                       /* ','  */
  YYSYMBOL_36_ = 36,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_axiom = 38,                     /* axiom  */
  YYSYMBOL_39_1 = 39,                      /* $@1  */
  YYSYMBOL_r_axiom = 40,                   /* r_axiom  */
  YYSYMBOL_function_rec = 41,              /* function_rec  */
  YYSYMBOL_42_2 = 42,                      /* $@2  */
  YYSYMBOL_arg_def = 43,                   /* arg_def  */
  YYSYMBOL_arg_def_rec = 44,               /* arg_def_rec  */
  YYSYMBOL_func_call = 45,                 /* func_call  */
  YYSYMBOL_arg_passed = 46,                /* arg_passed  */
  YYSYMBOL_arg_pas_rec = 47,               /* arg_pas_rec  */
  YYSYMBOL_code = 48,                      /* code  */
  YYSYMBOL_axiom_sentence = 49,            /* axiom_sentence  */
  YYSYMBOL_sentence = 50,                  /* sentence  */
  YYSYMBOL_control_sentence = 51,          /* control_sentence  */
  YYSYMBOL_rec_print = 52,                 /* rec_print  */
  YYSYMBOL_rec_def = 53,                   /* rec_def  */
  YYSYMBOL_definition = 54,                /* definition  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_term = 56,                      /* term  */
  YYSYMBOL_operand = 57                    /* operand  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   316

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,     2,     2,    28,     2,     2,
      31,    32,    26,    24,    35,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
      22,    21,    23,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    81,    81,    81,    83,    86,    87,    90,    94,    94,
     100,   101,   104,   106,   109,   112,   113,   116,   118,   121,
     123,   125,   126,   130,   131,   135,   136,   138,   140,   141,
     145,   148,   151,   154,   159,   161,   163,   165,   169,   171,
     174,   176,   179,   180,   182,   184,   186,   188,   190,   192,
     194,   196,   198,   200,   202,   204,   206,   210,   211,   212,
     214,   215,   218,   220
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIF",
  "INTEGER", "STRING", "MAIN", "WHILE", "FOR", "IF", "ELSE", "AND", "OR",
  "GEQ", "LEQ", "EQUAl", "NEQ", "PUTS", "IMPRIMIR", "RETURN", "'='", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "UNARY_SIGN", "';'", "'('",
  "')'", "'{'", "'}'", "','", "'!'", "$accept", "axiom", "$@1", "r_axiom",
  "function_rec", "$@2", "arg_def", "arg_def_rec", "func_call",
  "arg_passed", "arg_pas_rec", "code", "axiom_sentence", "sentence",
  "control_sentence", "rec_print", "rec_def", "definition", "expression",
  "term", "operand", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,   -10,    14,    -5,    37,   -75,    29,    63,    33,    49,
     -75,    36,    40,   -75,   -75,   -75,   -75,   -75,    68,    71,
      14,    42,    31,    72,    45,   -75,   -75,   -75,    15,   -75,
     -75,    44,    52,   -17,    14,    55,    56,    57,    58,    60,
     -75,    65,    67,    15,    68,    15,    78,    78,   -75,    78,
      64,    78,    87,    94,   -75,    15,   -75,   -75,    70,    74,
      63,    63,    78,    78,   -75,   241,   -75,   -75,    75,   -75,
     104,   138,   -10,    76,   159,    79,    73,   -75,     5,   -75,
     -75,   180,   -75,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,   -75,    78,    77,    78,
      80,   -75,    59,   -75,   -75,   -75,   273,   258,     4,     4,
     288,   288,     4,     4,    13,    13,   -75,   -75,   -75,   -75,
      15,   222,    15,    88,    90,   121,    91,   120,   106,    59,
     -75,    59,   -75,   136,   130,   -75,   -75,    78,   109,   201,
      15,   125,   133,    15,   -75,   134,   -75
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     8,     0,     0,     0,     4,     0,     0,     0,    40,
      23,    39,     0,     1,     2,    63,    62,    24,    11,     0,
       0,     0,     5,     0,     0,    10,    41,    38,     0,     6,
       3,    13,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,    21,     0,     0,     0,    16,    25,     0,
       0,     0,     0,     0,     7,    22,    19,    12,     0,    62,
       0,     0,     0,     0,    61,    26,    42,    57,     0,    15,
      18,     0,     0,     0,     0,     0,     0,    20,     0,    58,
      59,     0,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    27,     0,     8,     9,    60,    47,    48,    55,    53,
      51,    50,    52,    54,    43,    44,    45,    46,    56,    17,
       0,     0,     0,    37,     0,    36,     0,     0,     0,     0,
      28,     0,    30,     0,    31,    35,    34,     0,     0,     0,
       0,     0,     0,     0,    32,     0,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   137,   -75,   -75,    99,   -75,   -75,   135,   -28,   -75,
      81,   -42,   119,   -75,   -75,   -74,   -18,   -75,   -41,   -75,
       0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,    22,    30,     5,     8,    24,    25,    64,    68,
      69,    41,     6,    42,    43,   124,    10,    11,   125,    66,
      67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    56,    27,    58,    46,    65,    70,    17,    71,   103,
      74,     7,     3,    77,    47,    40,    48,    40,     9,    33,
      34,    81,    82,    35,    36,    37,    12,    40,    91,    92,
      93,    94,    95,    38,    39,     1,     2,    13,     3,    93,
      94,    95,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   135,    70,   136,   121,    14,
      79,    80,    15,    59,    18,   123,    15,    16,    72,     2,
      19,    20,    21,    23,    26,    28,    31,    32,   126,    44,
     128,    15,    59,    60,    61,    45,    49,    50,    51,    52,
      62,    53,    40,    75,    40,    63,   139,    55,   142,    54,
      76,   145,    60,    61,    78,    47,    99,    96,   102,    62,
     120,   101,    40,   122,    63,    40,    83,    84,    85,    86,
      87,    88,   130,   129,   133,   132,    89,    90,    91,    92,
      93,    94,    95,    83,    84,    85,    86,    87,    88,    97,
     134,   138,   140,    89,    90,    91,    92,    93,    94,    95,
      83,    84,    85,    86,    87,    88,   131,   137,   143,    29,
      89,    90,    91,    92,    93,    94,    95,   144,   146,    73,
      98,    83,    84,    85,    86,    87,    88,   104,   119,    57,
       0,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,   100,    83,    84,    85,    86,    87,    88,     0,     0,
       0,     0,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,   105,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,   141,    83,    84,    85,    86,    87,    88,
       0,     0,     0,     0,    89,    90,    91,    92,    93,    94,
      95,     0,   127,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,    89,    90,    91,    92,    93,    94,    95,
      83,     0,    85,    86,    87,    88,     0,     0,     0,     0,
      89,    90,    91,    92,    93,    94,    95,    85,    86,    87,
      88,     0,     0,     0,     0,    89,    90,    91,    92,    93,
      94,    95,    85,    86,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,    93,    94,    95
};

static const yytype_int16 yycheck[] =
{
      28,    43,    20,    45,    21,    46,    47,     7,    49,     4,
      51,    21,     7,    55,    31,    43,    34,    45,     4,     4,
       5,    62,    63,     8,     9,    10,    31,    55,    24,    25,
      26,    27,    28,    18,    19,     4,     5,     0,     7,    26,
      27,    28,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   129,    97,   131,    99,    30,
      60,    61,     3,     4,    31,     6,     3,     4,     4,     5,
      21,    35,    32,     5,     3,    33,     4,    32,   120,    35,
     122,     3,     4,    24,    25,    33,    31,    31,    31,    31,
      31,    31,   120,     6,   122,    36,   137,    30,   140,    34,
       6,   143,    24,    25,    34,    31,    30,    32,    35,    31,
      33,    32,   140,    33,    36,   143,    12,    13,    14,    15,
      16,    17,    32,    35,     4,    34,    22,    23,    24,    25,
      26,    27,    28,    12,    13,    14,    15,    16,    17,    35,
      34,    11,    33,    22,    23,    24,    25,    26,    27,    28,
      12,    13,    14,    15,    16,    17,    35,    21,    33,    22,
      22,    23,    24,    25,    26,    27,    28,    34,    34,    50,
      32,    12,    13,    14,    15,    16,    17,    78,    97,    44,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    32,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    32,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    32,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      12,    -1,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     7,    38,    41,    49,    21,    42,     4,
      53,    54,    31,     0,    30,     3,     4,    57,    31,    21,
      35,    32,    39,     5,    43,    44,     3,    53,    33,    38,
      40,     4,    32,     4,     5,     8,     9,    10,    18,    19,
      45,    48,    50,    51,    35,    33,    21,    31,    53,    31,
      31,    31,    31,    31,    34,    30,    48,    44,    48,     4,
      24,    25,    31,    36,    45,    55,    56,    57,    46,    47,
      55,    55,     4,    49,    55,     6,     6,    48,    34,    57,
      57,    55,    55,    12,    13,    14,    15,    16,    17,    22,
      23,    24,    25,    26,    27,    28,    32,    35,    32,    30,
      32,    32,    35,     4,    41,    32,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    47,
      33,    55,    33,     6,    52,    55,    48,    30,    48,    35,
      32,    35,    34,     4,    34,    52,    52,    21,    11,    55,
      33,    32,    48,    33,    34,    48,    34
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    39,    38,    38,    40,    40,    41,    42,    41,
      43,    43,    44,    44,    45,    46,    46,    47,    47,    48,
      48,    48,    48,    49,    49,    50,    50,    50,    50,    50,
      51,    51,    51,    51,    52,    52,    52,    52,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    56,
      56,    56,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     1,     0,     1,     6,     0,     9,
       1,     0,     4,     2,     4,     1,     0,     3,     1,     2,
       3,     1,     2,     2,     3,     2,     3,     4,     6,     1,
       7,     7,    11,    13,     3,     3,     1,     1,     3,     1,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     1,     2,     2,
       3,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 81 "trad3.y"
                                             { printf ("%s\n", yyvsp[-1].code) ; }
#line 1334 "trad3.tab.c"
    break;

  case 4: /* axiom: function_rec  */
#line 83 "trad3.y"
                                             { printf ("%s", yyvsp[0].code) ; }
#line 1340 "trad3.tab.c"
    break;

  case 5: /* r_axiom: %empty  */
#line 86 "trad3.y"
                                             { ; }
#line 1346 "trad3.tab.c"
    break;

  case 6: /* r_axiom: axiom  */
#line 87 "trad3.y"
                                             { ; }
#line 1352 "trad3.tab.c"
    break;

  case 7: /* function_rec: MAIN '(' ')' '{' code '}'  */
#line 91 "trad3.y"
              { sprintf(func_prefix, "aaaaa_") ;
                sprintf(temp, "(defun main () %s)\n", yyvsp[-1].code) ;
                yyval.code = gen_code(temp) ; }
#line 1360 "trad3.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 94 "trad3.y"
                       { sprintf(func_prefix, "%s", yyvsp[0].code) ;
                printf("%s", func_prefix) ; }
#line 1367 "trad3.tab.c"
    break;

  case 9: /* function_rec: IDENTIF $@2 '(' arg_def ')' '{' code '}' function_rec  */
#line 97 "trad3.y"
              {sprintf(temp, "(defun %s (%s) %s)\n%s", yyvsp[-8].code, yyvsp[-6].code, yyvsp[-3].code, yyvsp[-1].code) ; 
                yyval.code = gen_code(temp) ; }
#line 1374 "trad3.tab.c"
    break;

  case 10: /* arg_def: arg_def_rec  */
#line 100 "trad3.y"
                                             { yyval = yyvsp[0] ; }
#line 1380 "trad3.tab.c"
    break;

  case 11: /* arg_def: %empty  */
#line 101 "trad3.y"
                                             { temp[0] = '\0' ;
                                               yyval.code = gen_code(temp) ; }
#line 1387 "trad3.tab.c"
    break;

  case 12: /* arg_def_rec: INTEGER IDENTIF ',' arg_def_rec  */
#line 104 "trad3.y"
                                             { sprintf(temp, "%s%s, %s", func_prefix, yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code(temp) ; }
#line 1394 "trad3.tab.c"
    break;

  case 13: /* arg_def_rec: INTEGER IDENTIF  */
#line 106 "trad3.y"
                                             { sprintf(temp, "%s%s", func_prefix, yyvsp[0].code) ; 
                                               yyval.code = gen_code(temp) ; }
#line 1401 "trad3.tab.c"
    break;

  case 14: /* func_call: IDENTIF '(' arg_passed ')'  */
#line 109 "trad3.y"
                                               { sprintf (temp, "(%s%s)", yyvsp[-3].code, yyvsp[-1].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1408 "trad3.tab.c"
    break;

  case 15: /* arg_passed: arg_pas_rec  */
#line 112 "trad3.y"
                                             { yyval = yyvsp[0] ; }
#line 1414 "trad3.tab.c"
    break;

  case 16: /* arg_passed: %empty  */
#line 113 "trad3.y"
                                             { temp[0] = '\0' ;
                                               yyval.code = gen_code(temp) ; }
#line 1421 "trad3.tab.c"
    break;

  case 17: /* arg_pas_rec: expression ',' arg_pas_rec  */
#line 116 "trad3.y"
                                             { sprintf(temp, " %s,%s", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code(temp) ; }
#line 1428 "trad3.tab.c"
    break;

  case 18: /* arg_pas_rec: expression  */
#line 118 "trad3.y"
                                             { sprintf(temp, " %s", yyvsp[0].code) ;
                                               yyval.code = gen_code(temp) ; }
#line 1435 "trad3.tab.c"
    break;

  case 19: /* code: control_sentence code  */
#line 121 "trad3.y"
                                             { sprintf (temp, "%s %s", yyvsp[-1].code, yyvsp[0].code) ;
                                               yyval.code = gen_code(temp) ; }
#line 1442 "trad3.tab.c"
    break;

  case 20: /* code: sentence ';' code  */
#line 123 "trad3.y"
                                             { sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code(temp) ; }
#line 1449 "trad3.tab.c"
    break;

  case 21: /* code: control_sentence  */
#line 125 "trad3.y"
                                             { yyval = yyvsp[0] ; }
#line 1455 "trad3.tab.c"
    break;

  case 22: /* code: sentence ';'  */
#line 126 "trad3.y"
                                             { yyval = yyvsp[-1] ; }
#line 1461 "trad3.tab.c"
    break;

  case 23: /* axiom_sentence: INTEGER rec_def  */
#line 130 "trad3.y"
                                             { yyval = yyvsp[0] ; }
#line 1467 "trad3.tab.c"
    break;

  case 24: /* axiom_sentence: IDENTIF '=' operand  */
#line 131 "trad3.y"
                                             { sprintf (temp, "(setq %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code(temp) ; }
#line 1474 "trad3.tab.c"
    break;

  case 25: /* sentence: INTEGER rec_def  */
#line 135 "trad3.y"
                                             { yyval = yyvsp[0] ; }
#line 1480 "trad3.tab.c"
    break;

  case 26: /* sentence: IDENTIF '=' expression  */
#line 136 "trad3.y"
                                             { sprintf (temp, "(setq %s%s %s)", func_prefix, yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code(temp) ; }
#line 1487 "trad3.tab.c"
    break;

  case 27: /* sentence: PUTS '(' STRING ')'  */
#line 138 "trad3.y"
                                             { sprintf (temp, "(print \"%s\")", yyvsp[0].code) ;  
                                               yyval.code = gen_code (temp) ; }
#line 1494 "trad3.tab.c"
    break;

  case 28: /* sentence: IMPRIMIR '(' STRING ',' rec_print ')'  */
#line 140 "trad3.y"
                                                    { yyval = yyvsp[-1] ; }
#line 1500 "trad3.tab.c"
    break;

  case 29: /* sentence: func_call  */
#line 141 "trad3.y"
                                             { yyval = yyvsp[0] ; }
#line 1506 "trad3.tab.c"
    break;

  case 30: /* control_sentence: WHILE '(' expression ')' '{' code '}'  */
#line 146 "trad3.y"
              { sprintf (temp, "(loop while %s do %s)", yyvsp[-4].code, yyvsp[-1].code) ;  
                yyval.code = gen_code (temp) ; }
#line 1513 "trad3.tab.c"
    break;

  case 31: /* control_sentence: IF '(' expression ')' '{' code '}'  */
#line 149 "trad3.y"
              { sprintf (temp, "(if %s %s)", yyvsp[-4].code, yyvsp[-1].code) ;
                yyval.code = gen_code (temp) ; }
#line 1520 "trad3.tab.c"
    break;

  case 32: /* control_sentence: IF '(' expression ')' '{' code '}' ELSE '{' code '}'  */
#line 152 "trad3.y"
              { sprintf (temp, "(if %s %s %s)", yyvsp[-8].code, yyvsp[-5].code, yyvsp[-1].code) ;
                yyval.code = gen_code (temp) ; }
#line 1527 "trad3.tab.c"
    break;

  case 33: /* control_sentence: FOR '(' axiom_sentence ';' expression ';' IDENTIF '=' expression ')' '{' code '}'  */
#line 155 "trad3.y"
              { sprintf (temp, "%s (loop while %s do %s (setq %s %s))", yyvsp[-10].code , yyvsp[-8].code, yyvsp[-1].code, yyvsp[-6].code, yyvsp[-4].code) ;
                yyval.code = gen_code (temp) ; }
#line 1534 "trad3.tab.c"
    break;

  case 34: /* rec_print: expression ',' rec_print  */
#line 159 "trad3.y"
                                             { sprintf (temp, "(princ %s) %s",yyvsp[-2].code, yyvsp[0].code);
                                               yyval.code = gen_code (temp) ; }
#line 1541 "trad3.tab.c"
    break;

  case 35: /* rec_print: STRING ',' rec_print  */
#line 161 "trad3.y"
                                             { sprintf (temp, "(princ \"%s\") %s",yyvsp[-2].code, yyvsp[0].code);
                                               yyval.code = gen_code (temp) ; }
#line 1548 "trad3.tab.c"
    break;

  case 36: /* rec_print: expression  */
#line 163 "trad3.y"
                                             { sprintf (temp, "(princ %s)",yyvsp[0].code);
                                               yyval.code = gen_code(temp) ; }
#line 1555 "trad3.tab.c"
    break;

  case 37: /* rec_print: STRING  */
#line 165 "trad3.y"
                                             { sprintf (temp, "(princ \"%s\")",yyvsp[0].code);
                                               yyval.code = gen_code(temp) ; }
#line 1562 "trad3.tab.c"
    break;

  case 38: /* rec_def: definition ',' rec_def  */
#line 169 "trad3.y"
                                             { sprintf (temp, "%s %s",yyvsp[-2].code, yyvsp[0].code);
                                               yyval.code = gen_code (temp) ; }
#line 1569 "trad3.tab.c"
    break;

  case 39: /* rec_def: definition  */
#line 171 "trad3.y"
                                             { yyval = yyvsp[0] ; }
#line 1575 "trad3.tab.c"
    break;

  case 40: /* definition: IDENTIF  */
#line 174 "trad3.y"
                                             { sprintf (temp, "(setq %s%s 0)", func_prefix, yyvsp[0].code) ;
                                               yyval.code = gen_code(temp) ; }
#line 1582 "trad3.tab.c"
    break;

  case 41: /* definition: IDENTIF '=' NUMBER  */
#line 176 "trad3.y"
                                             { sprintf (temp, "(setq %s%s %d)", func_prefix, yyvsp[-2].code, yyvsp[0].value) ;
                                               yyval.code = gen_code(temp) ; }
#line 1589 "trad3.tab.c"
    break;

  case 42: /* expression: term  */
#line 179 "trad3.y"
                                             { yyval = yyvsp[0] ; }
#line 1595 "trad3.tab.c"
    break;

  case 43: /* expression: expression '+' expression  */
#line 180 "trad3.y"
                                             { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1602 "trad3.tab.c"
    break;

  case 44: /* expression: expression '-' expression  */
#line 182 "trad3.y"
                                             { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1609 "trad3.tab.c"
    break;

  case 45: /* expression: expression '*' expression  */
#line 184 "trad3.y"
                                             { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1616 "trad3.tab.c"
    break;

  case 46: /* expression: expression '/' expression  */
#line 186 "trad3.y"
                                             { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1623 "trad3.tab.c"
    break;

  case 47: /* expression: expression AND expression  */
#line 188 "trad3.y"
                                             { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1630 "trad3.tab.c"
    break;

  case 48: /* expression: expression OR expression  */
#line 190 "trad3.y"
                                             { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1637 "trad3.tab.c"
    break;

  case 49: /* expression: '!' expression  */
#line 192 "trad3.y"
                                             { sprintf (temp, "(not %s)", yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1644 "trad3.tab.c"
    break;

  case 50: /* expression: expression NEQ expression  */
#line 194 "trad3.y"
                                             { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1651 "trad3.tab.c"
    break;

  case 51: /* expression: expression EQUAl expression  */
#line 196 "trad3.y"
                                             { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1658 "trad3.tab.c"
    break;

  case 52: /* expression: expression '<' expression  */
#line 198 "trad3.y"
                                             { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1665 "trad3.tab.c"
    break;

  case 53: /* expression: expression LEQ expression  */
#line 200 "trad3.y"
                                             { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1672 "trad3.tab.c"
    break;

  case 54: /* expression: expression '>' expression  */
#line 202 "trad3.y"
                                             { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1679 "trad3.tab.c"
    break;

  case 55: /* expression: expression GEQ expression  */
#line 204 "trad3.y"
                                             { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1686 "trad3.tab.c"
    break;

  case 56: /* expression: expression '%' expression  */
#line 206 "trad3.y"
                                             { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1693 "trad3.tab.c"
    break;

  case 57: /* term: operand  */
#line 210 "trad3.y"
                                             { yyval = yyvsp[0] ; }
#line 1699 "trad3.tab.c"
    break;

  case 58: /* term: '+' operand  */
#line 211 "trad3.y"
                                             { yyval = yyvsp[-1] ; }
#line 1705 "trad3.tab.c"
    break;

  case 59: /* term: '-' operand  */
#line 212 "trad3.y"
                                             { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1712 "trad3.tab.c"
    break;

  case 60: /* term: '(' expression ')'  */
#line 214 "trad3.y"
                                             { yyval = yyvsp[-1] ; }
#line 1718 "trad3.tab.c"
    break;

  case 61: /* term: func_call  */
#line 215 "trad3.y"
                                             { yyval = yyvsp[0] ; }
#line 1724 "trad3.tab.c"
    break;

  case 62: /* operand: IDENTIF  */
#line 218 "trad3.y"
                                             { sprintf (temp, "%s%s", func_prefix, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1731 "trad3.tab.c"
    break;

  case 63: /* operand: NUMBER  */
#line 220 "trad3.y"
                                             { sprintf (temp, "%d", yyvsp[0].value) ;
                                               yyval.code = gen_code (temp) ; }
#line 1738 "trad3.tab.c"
    break;


#line 1742 "trad3.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 225 "trad3.y"
                            // SECTION 4    Code in C

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
