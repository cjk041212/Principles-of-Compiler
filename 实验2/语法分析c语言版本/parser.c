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
#line 3 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "ast.h"

ASTNode *root;

extern FILE *yyin;
extern int line_cnt;
extern int yylineno;
extern char *yytext;
extern int yylex();
extern int yyparse();
//extern void yyerror(char *msg);
void yyerror(const char* fmt, ...);
int syntax_error = 0;
char filename[100];

#line 93 "parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INT_LIT = 4,                    /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 5,                  /* FLOAT_LIT  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_VOID = 8,                       /* VOID  */
  YYSYMBOL_CONST = 9,                      /* CONST  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_BREAK = 14,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 15,                  /* CONTINUE  */
  YYSYMBOL_LP = 16,                        /* LP  */
  YYSYMBOL_RP = 17,                        /* RP  */
  YYSYMBOL_LB = 18,                        /* LB  */
  YYSYMBOL_RB = 19,                        /* RB  */
  YYSYMBOL_LC = 20,                        /* LC  */
  YYSYMBOL_RC = 21,                        /* RC  */
  YYSYMBOL_COMMA = 22,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 23,                 /* SEMICOLON  */
  YYSYMBOL_MINUS = 24,                     /* MINUS  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_ASSIGN = 26,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 27,                      /* PLUS  */
  YYSYMBOL_MUL = 28,                       /* MUL  */
  YYSYMBOL_DIV = 29,                       /* DIV  */
  YYSYMBOL_MOD = 30,                       /* MOD  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_EQ = 33,                        /* EQ  */
  YYSYMBOL_NE = 34,                        /* NE  */
  YYSYMBOL_LT = 35,                        /* LT  */
  YYSYMBOL_LE = 36,                        /* LE  */
  YYSYMBOL_GT = 37,                        /* GT  */
  YYSYMBOL_GE = 38,                        /* GE  */
  YYSYMBOL_LEX_ERR = 39,                   /* LEX_ERR  */
  YYSYMBOL_THEN = 40,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_Root = 42,                      /* Root  */
  YYSYMBOL_CompUnit = 43,                  /* CompUnit  */
  YYSYMBOL_ConstDecl = 44,                 /* ConstDecl  */
  YYSYMBOL_ConstDef = 45,                  /* ConstDef  */
  YYSYMBOL_ConstExpArray = 46,             /* ConstExpArray  */
  YYSYMBOL_ConstInitVal = 47,              /* ConstInitVal  */
  YYSYMBOL_ConstExp = 48,                  /* ConstExp  */
  YYSYMBOL_VarDecl = 49,                   /* VarDecl  */
  YYSYMBOL_VarDef = 50,                    /* VarDef  */
  YYSYMBOL_InitVal = 51,                   /* InitVal  */
  YYSYMBOL_InitVals = 52,                  /* InitVals  */
  YYSYMBOL_FuncDef = 53,                   /* FuncDef  */
  YYSYMBOL_FuncFParam = 54,                /* FuncFParam  */
  YYSYMBOL_Block = 55,                     /* Block  */
  YYSYMBOL_BlockItem = 56,                 /* BlockItem  */
  YYSYMBOL_Stmt = 57,                      /* Stmt  */
  YYSYMBOL_Exp = 58,                       /* Exp  */
  YYSYMBOL_AddExp = 59,                    /* AddExp  */
  YYSYMBOL_MulExp = 60,                    /* MulExp  */
  YYSYMBOL_UnaryExp = 61,                  /* UnaryExp  */
  YYSYMBOL_FuncRParams = 62,               /* FuncRParams  */
  YYSYMBOL_PrimaryExp = 63,                /* PrimaryExp  */
  YYSYMBOL_LVal = 64,                      /* LVal  */
  YYSYMBOL_Cond = 65,                      /* Cond  */
  YYSYMBOL_LOrExp = 66,                    /* LOrExp  */
  YYSYMBOL_LAndExp = 67,                   /* LAndExp  */
  YYSYMBOL_EqExp = 68,                     /* EqExp  */
  YYSYMBOL_RelExp = 69,                    /* RelExp  */
  YYSYMBOL_ExpArray = 70                   /* ExpArray  */
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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   275

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    52,    53,    54,    55,    56,    57,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,   100,   101,   102,
     103,   104,   112,   114,   116,   118,   120,   122,   124,   126,
     128,   130,   132,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   173,   174
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INT_LIT",
  "FLOAT_LIT", "INT", "FLOAT", "VOID", "CONST", "RETURN", "IF", "ELSE",
  "WHILE", "BREAK", "CONTINUE", "LP", "RP", "LB", "RB", "LC", "RC",
  "COMMA", "SEMICOLON", "MINUS", "NOT", "ASSIGN", "PLUS", "MUL", "DIV",
  "MOD", "AND", "OR", "EQ", "NE", "LT", "LE", "GT", "GE", "LEX_ERR",
  "THEN", "$accept", "Root", "CompUnit", "ConstDecl", "ConstDef",
  "ConstExpArray", "ConstInitVal", "ConstExp", "VarDecl", "VarDef",
  "InitVal", "InitVals", "FuncDef", "FuncFParam", "Block", "BlockItem",
  "Stmt", "Exp", "AddExp", "MulExp", "UnaryExp", "FuncRParams",
  "PrimaryExp", "LVal", "Cond", "LOrExp", "LAndExp", "EqExp", "RelExp",
  "ExpArray", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-165)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     107,    25,    33,    35,   133,    44,  -165,   107,   107,   107,
      -5,    24,    64,    34,    51,    72,    72,  -165,  -165,  -165,
    -165,    20,   230,    -4,  -165,    42,  -165,    92,    70,    87,
      99,    90,   126,   136,   143,   102,  -165,  -165,   230,   230,
     230,   230,   155,    77,   115,  -165,  -165,   179,   187,   136,
     168,   136,   182,   175,  -165,  -165,     2,    73,   148,  -165,
     136,   201,   230,  -165,   185,  -165,    78,  -165,  -165,  -165,
      70,   230,   230,   230,   230,   230,    70,  -165,    65,   188,
    -165,  -165,   136,  -165,   136,   216,   194,   163,   196,   163,
     179,   179,   226,   200,   206,   204,   214,  -165,   148,   148,
    -165,   202,   148,   215,   198,  -165,  -165,   217,   227,   228,
    -165,   230,   230,  -165,  -165,  -165,  -165,  -165,  -165,  -165,
     223,   231,   179,  -165,  -165,   103,   234,  -165,   240,  -165,
     240,  -165,  -165,   225,   230,   230,  -165,  -165,  -165,  -165,
    -165,  -165,  -165,   230,   230,  -165,   240,  -165,  -165,   187,
    -165,  -165,  -165,   125,    72,   237,   238,  -165,    96,   244,
    -165,   232,   235,   161,   245,   242,  -165,  -165,  -165,  -165,
     216,  -165,   163,   163,   230,   230,   230,   230,   173,   230,
     230,   230,   230,   173,  -165,   246,  -165,  -165,  -165,  -165,
    -165,  -165,   251,  -165,  -165,  -165,  -165,  -165,  -165,   173,
    -165
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
      13,     0,    13,     0,     0,     0,     0,     1,     6,     7,
       8,     0,     0,    24,    22,     0,    23,     0,    13,     0,
       0,     0,     0,     0,     0,    97,    81,    82,     0,     0,
       0,     0,     0,    19,    67,    71,    80,     0,     0,     0,
       0,     0,     0,     0,     9,    10,    39,    40,    48,    33,
       0,     0,     0,    83,     0,    63,    64,    75,    76,    74,
      13,     0,     0,     0,     0,     0,    13,    26,     0,    25,
      28,    34,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,    48,    48,
      55,     0,    48,     0,    80,    36,    72,    77,     0,     0,
      79,     0,     0,    14,    21,    20,    68,    69,    70,    29,
      31,     0,     0,    37,    38,     0,    11,    15,    97,    43,
      97,    44,    62,     0,     0,     0,    59,    60,    49,    50,
      47,    51,    53,     0,     0,    73,    97,    66,    65,     0,
      30,    27,    16,     0,     0,    41,    42,    61,    92,     0,
      84,    85,    87,    89,     0,     0,    78,    98,    32,    17,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,     0,    45,    46,    93,    95,
      94,    96,    57,    86,    88,    90,    91,    58,    18,     0,
      56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -165,  -165,   158,   -37,   -13,   -16,  -115,   247,   -15,     3,
     220,   121,  -165,   -23,   -26,    -2,  -164,   -32,  -103,   -22,
     140,   127,  -165,   -57,   137,    94,    95,    27,   -39,  -113
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,    29,    23,   126,   127,     8,    11,
     120,   121,     9,    34,   100,   101,   102,   103,    65,    66,
      44,   108,    45,    46,   159,   160,   161,   162,   163,    63
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,   104,    50,    30,    52,    13,    64,    59,   147,   148,
     153,    21,    53,    22,   192,   155,    80,   156,    47,   197,
      86,    98,    48,    81,    87,    83,    31,    32,    10,   107,
     109,   158,   158,   167,   105,   200,    12,    33,    14,   114,
     115,   104,   104,    99,    17,   104,    80,    24,    31,    32,
      77,   116,   117,   118,   113,   185,   123,    26,   124,    49,
     133,    98,    98,    43,   129,    98,   131,    27,    35,    36,
      37,   158,   158,   158,   158,    28,   158,   158,   158,   158,
      25,    38,    22,    99,    99,    78,   119,    99,    22,    39,
      40,    88,    41,    56,    13,    89,   138,   139,    31,    32,
     141,    71,   111,    43,    72,   112,    35,    36,    37,    51,
      54,   165,   107,     1,     2,     3,     4,    80,    61,    38,
      62,   104,    55,   125,   152,   151,   104,    39,    40,    57,
      41,   174,   175,   176,   177,   188,   189,   190,   191,    15,
      16,   171,   104,    73,    74,    75,   169,   170,    43,   186,
     187,    35,    36,    37,    90,    91,    58,     4,    92,    93,
      60,    94,    95,    96,    38,    18,    19,    20,    58,    31,
      32,    97,    39,    40,    70,    41,    35,    36,    37,    67,
      68,    69,    76,    92,    93,    82,    94,    95,    96,    38,
      35,    36,    37,    58,   181,   182,    97,    39,    40,    84,
      41,    85,   110,    38,    35,    36,    37,    78,   195,   196,
     122,    39,    40,   128,    41,   130,   134,    38,   106,    35,
      36,    37,   135,   140,   143,    39,    40,   136,    41,    35,
      36,    37,    38,    35,    36,    37,   125,   137,   142,   144,
      39,    40,    38,    41,   145,   149,    38,   146,   157,   132,
      39,    40,   150,    41,    39,    40,   154,    41,    62,   172,
     173,   178,   183,   199,   179,   184,   180,   198,    79,    42,
     168,   166,   164,   193,     0,   194
};

static const yytype_int16 yycheck[] =
{
      22,    58,    25,    16,    27,     2,    38,    33,   111,   112,
     125,    16,    28,    18,   178,   128,    48,   130,    22,   183,
      18,    58,    26,    49,    22,    51,     6,     7,     3,    61,
      62,   134,   135,   146,    60,   199,     3,    17,     3,    71,
      72,    98,    99,    58,     0,   102,    78,    23,     6,     7,
      47,    73,    74,    75,    70,   170,    82,    23,    84,    17,
      92,    98,    99,    85,    87,   102,    89,    16,     3,     4,
       5,   174,   175,   176,   177,     3,   179,   180,   181,   182,
      16,    16,    18,    98,    99,    20,    21,   102,    18,    24,
      25,    18,    27,     3,    91,    22,    98,    99,     6,     7,
     102,    24,    24,   125,    27,    27,     3,     4,     5,    17,
      23,   143,   144,     6,     7,     8,     9,   149,    16,    16,
      18,   178,    23,    20,    21,   122,   183,    24,    25,     3,
      27,    35,    36,    37,    38,   174,   175,   176,   177,     6,
       7,   154,   199,    28,    29,    30,    21,    22,   170,   172,
     173,     3,     4,     5,     6,     7,    20,     9,    10,    11,
      17,    13,    14,    15,    16,     7,     8,     9,    20,     6,
       7,    23,    24,    25,    19,    27,     3,     4,     5,    39,
      40,    41,     3,    10,    11,    17,    13,    14,    15,    16,
       3,     4,     5,    20,    33,    34,    23,    24,    25,    17,
      27,    26,    17,    16,     3,     4,     5,    20,   181,   182,
      22,    24,    25,    19,    27,    19,    16,    16,    17,     3,
       4,     5,    16,    21,    26,    24,    25,    23,    27,     3,
       4,     5,    16,     3,     4,     5,    20,    23,    23,    22,
      24,    25,    16,    27,    17,    22,    16,    19,    23,    23,
      24,    25,    21,    27,    24,    25,    22,    27,    18,    22,
      22,    17,    17,    12,    32,    23,    31,    21,    48,    22,
     149,   144,   135,   179,    -1,   180
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,     9,    42,    43,    44,    49,    53,
       3,    50,     3,    50,     3,     6,     7,     0,    43,    43,
      43,    16,    18,    46,    23,    16,    23,    16,     3,    45,
      45,     6,     7,    17,    54,     3,     4,     5,    16,    24,
      25,    27,    48,    60,    61,    63,    64,    22,    26,    17,
      54,    17,    54,    46,    23,    23,     3,     3,    20,    55,
      17,    16,    18,    70,    58,    59,    60,    61,    61,    61,
      19,    24,    27,    28,    29,    30,     3,    50,    20,    51,
      58,    55,    17,    55,    17,    26,    18,    22,    18,    22,
       6,     7,    10,    11,    13,    14,    15,    23,    44,    49,
      55,    56,    57,    58,    64,    55,    17,    58,    62,    58,
      17,    24,    27,    46,    58,    58,    60,    60,    60,    21,
      51,    52,    22,    55,    55,    20,    47,    48,    19,    54,
      19,    54,    23,    58,    16,    16,    23,    23,    56,    56,
      21,    56,    23,    26,    22,    17,    19,    59,    59,    22,
      21,    50,    21,    47,    22,    70,    70,    23,    59,    65,
      66,    67,    68,    69,    65,    58,    62,    70,    52,    21,
      22,    45,    22,    22,    35,    36,    37,    38,    17,    32,
      31,    33,    34,    17,    23,    47,    54,    54,    69,    69,
      69,    69,    57,    66,    67,    68,    68,    57,    21,    12,
      57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    43,    43,    43,    44,
      44,    45,    45,    46,    46,    47,    47,    47,    47,    48,
      48,    48,    49,    49,    50,    50,    50,    50,    51,    51,
      51,    52,    52,    53,    53,    53,    53,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    56,    56,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    59,    59,    59,    60,    60,    60,
      60,    61,    61,    61,    61,    61,    61,    62,    62,    63,
      63,    63,    63,    64,    65,    66,    66,    67,    67,    68,
      68,    68,    69,    69,    69,    69,    69,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     2,     4,
       4,     4,     6,     0,     4,     1,     2,     3,     5,     1,
       3,     3,     3,     3,     2,     4,     4,     6,     1,     2,
       3,     1,     3,     5,     5,     5,     6,     6,     6,     2,
       2,     5,     5,     4,     4,     7,     7,     3,     0,     2,
       2,     2,     4,     2,     1,     1,     7,     5,     5,     2,
       2,     3,     2,     1,     1,     3,     3,     1,     3,     3,
       3,     1,     3,     4,     2,     2,     2,     1,     3,     3,
       1,     1,     1,     2,     1,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     0,     4
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Root: CompUnit  */
#line 51 "parser.y"
               { root = new_node(Root, NULL, NULL, (yyvsp[0].node_val), 0, 0,  NULL, NonType); }
#line 1681 "parser.c"
    break;

  case 3: /* CompUnit: ConstDecl  */
#line 52 "parser.y"
                    { (yyval.node_val) = new_node(CompUnit, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1687 "parser.c"
    break;

  case 4: /* CompUnit: VarDecl  */
#line 53 "parser.y"
                  { (yyval.node_val) = new_node(CompUnit, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1693 "parser.c"
    break;

  case 5: /* CompUnit: FuncDef  */
#line 54 "parser.y"
                  { (yyval.node_val) = new_node(CompUnit, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1699 "parser.c"
    break;

  case 6: /* CompUnit: ConstDecl CompUnit  */
#line 55 "parser.y"
                             { (yyval.node_val) = new_node(CompUnit, (yyvsp[0].node_val), NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1705 "parser.c"
    break;

  case 7: /* CompUnit: VarDecl CompUnit  */
#line 56 "parser.y"
                           { (yyval.node_val) = new_node(CompUnit, (yyvsp[0].node_val), NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1711 "parser.c"
    break;

  case 8: /* CompUnit: FuncDef CompUnit  */
#line 57 "parser.y"
                           { (yyval.node_val) = new_node(CompUnit, (yyvsp[0].node_val), NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1717 "parser.c"
    break;

  case 9: /* ConstDecl: CONST INT ConstDef SEMICOLON  */
#line 59 "parser.y"
                                        { (yyval.node_val) = new_node(ConstDecl, NULL, NULL, (yyvsp[-1].node_val), 0, 0, NULL, Int); }
#line 1723 "parser.c"
    break;

  case 10: /* ConstDecl: CONST FLOAT ConstDef SEMICOLON  */
#line 60 "parser.y"
                                          { (yyval.node_val) = new_node(ConstDecl, NULL, NULL, (yyvsp[-1].node_val), 0, 0, NULL, Float); }
#line 1729 "parser.c"
    break;

  case 11: /* ConstDef: ID ConstExpArray ASSIGN ConstInitVal  */
#line 61 "parser.y"
                                               { (yyval.node_val) = new_node(ConstDef, NULL, (yyvsp[-2].node_val), (yyvsp[0].node_val), 0, 0, (yyvsp[-3].str_val), NonType); }
#line 1735 "parser.c"
    break;

  case 12: /* ConstDef: ID ConstExpArray ASSIGN ConstInitVal COMMA ConstDef  */
#line 62 "parser.y"
                                                              { (yyval.node_val) = new_node(ConstDef, (yyvsp[0].node_val), (yyvsp[-4].node_val), (yyvsp[-2].node_val), 0, 0, (yyvsp[-5].str_val), NonType); }
#line 1741 "parser.c"
    break;

  case 13: /* ConstExpArray: %empty  */
#line 63 "parser.y"
               { (yyval.node_val) = NULL; }
#line 1747 "parser.c"
    break;

  case 14: /* ConstExpArray: LB ConstExp RB ConstExpArray  */
#line 64 "parser.y"
                                            { (yyval.node_val) = new_node(ConstExpArray, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), 0, 0, NULL, NonType); }
#line 1753 "parser.c"
    break;

  case 15: /* ConstInitVal: ConstExp  */
#line 65 "parser.y"
                       { (yyval.node_val) = new_node(ConstInitVal, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1759 "parser.c"
    break;

  case 16: /* ConstInitVal: LC RC  */
#line 66 "parser.y"
                    { (yyval.node_val) = new_node(ConstInitVal, NULL, NULL, NULL, 0, 0, NULL, NonType); }
#line 1765 "parser.c"
    break;

  case 17: /* ConstInitVal: LC ConstInitVal RC  */
#line 67 "parser.y"
                                 { (yyval.node_val) = new_node(ConstInitVal, NULL, NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1771 "parser.c"
    break;

  case 18: /* ConstInitVal: LC ConstInitVal COMMA ConstInitVal RC  */
#line 68 "parser.y"
                                                    { (yyval.node_val) = new_node(ConstInitVal, (yyvsp[-1].node_val), NULL, (yyvsp[-3].node_val), 0, 0, NULL, NonType); }
#line 1777 "parser.c"
    break;

  case 19: /* ConstExp: MulExp  */
#line 69 "parser.y"
                 { (yyval.node_val) = new_node(ConstExp, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1783 "parser.c"
    break;

  case 20: /* ConstExp: MulExp PLUS Exp  */
#line 70 "parser.y"
                          { (yyval.node_val) = new_node(ConstExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), PLUS, 0, NULL, NonType); }
#line 1789 "parser.c"
    break;

  case 21: /* ConstExp: MulExp MINUS Exp  */
#line 71 "parser.y"
                           { (yyval.node_val) = new_node(ConstExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), MINUS, 0, NULL, NonType); }
#line 1795 "parser.c"
    break;

  case 22: /* VarDecl: INT VarDef SEMICOLON  */
#line 73 "parser.y"
                              { (yyval.node_val) = new_node(VarDecl, NULL, NULL, (yyvsp[-1].node_val), 0, 0, NULL, Int); }
#line 1801 "parser.c"
    break;

  case 23: /* VarDecl: FLOAT VarDef SEMICOLON  */
#line 74 "parser.y"
                                { (yyval.node_val) = new_node(VarDecl, NULL, NULL, (yyvsp[-1].node_val), 0, 0, NULL, Float); }
#line 1807 "parser.c"
    break;

  case 24: /* VarDef: ID ConstExpArray  */
#line 75 "parser.y"
                         { (yyval.node_val) = new_node(VarDef, NULL, (yyvsp[0].node_val), NULL, 0, 0, (yyvsp[-1].str_val), NonType); }
#line 1813 "parser.c"
    break;

  case 25: /* VarDef: ID ConstExpArray ASSIGN InitVal  */
#line 76 "parser.y"
                                        { (yyval.node_val) = new_node(VarDef, NULL, (yyvsp[-2].node_val), (yyvsp[0].node_val), 0, 0, (yyvsp[-3].str_val), NonType); }
#line 1819 "parser.c"
    break;

  case 26: /* VarDef: ID ConstExpArray COMMA VarDef  */
#line 77 "parser.y"
                                      { (yyval.node_val) = new_node(VarDef, (yyvsp[0].node_val), (yyvsp[-2].node_val), NULL, 0, 0, (yyvsp[-3].str_val), NonType); }
#line 1825 "parser.c"
    break;

  case 27: /* VarDef: ID ConstExpArray ASSIGN InitVal COMMA VarDef  */
#line 78 "parser.y"
                                                     { (yyval.node_val) = new_node(VarDef, (yyvsp[0].node_val), (yyvsp[-4].node_val), (yyvsp[-2].node_val), 0, 0, (yyvsp[-5].str_val), NonType); }
#line 1831 "parser.c"
    break;

  case 28: /* InitVal: Exp  */
#line 79 "parser.y"
             { (yyval.node_val) = new_node(InitVal, NULL, NULL, (yyvsp[0].node_val), Exp, 0, NULL, NonType); }
#line 1837 "parser.c"
    break;

  case 29: /* InitVal: LC RC  */
#line 80 "parser.y"
               { (yyval.node_val) = new_node(InitVal, NULL, NULL, NULL, InitVals, 0, NULL, NonType); }
#line 1843 "parser.c"
    break;

  case 30: /* InitVal: LC InitVals RC  */
#line 81 "parser.y"
                        { (yyval.node_val) = new_node(InitVal, NULL, NULL, (yyvsp[-1].node_val), InitVals, 0, NULL, NonType); }
#line 1849 "parser.c"
    break;

  case 31: /* InitVals: InitVal  */
#line 82 "parser.y"
                  { (yyval.node_val) = new_node(InitVals, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 1855 "parser.c"
    break;

  case 32: /* InitVals: InitVal COMMA InitVals  */
#line 83 "parser.y"
                                 { (yyval.node_val) = new_node(InitVals, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), 0, 0, NULL, NonType); }
#line 1861 "parser.c"
    break;

  case 33: /* FuncDef: INT ID LP RP Block  */
#line 85 "parser.y"
                            { (yyval.node_val) = new_node(FuncDef, NULL, NULL, (yyvsp[0].node_val), 0, 0, (yyvsp[-3].str_val), Int); }
#line 1867 "parser.c"
    break;

  case 34: /* FuncDef: FLOAT ID LP RP Block  */
#line 86 "parser.y"
                              { (yyval.node_val) = new_node(FuncDef, NULL, NULL, (yyvsp[0].node_val), 0, 0, (yyvsp[-3].str_val), Float); }
#line 1873 "parser.c"
    break;

  case 35: /* FuncDef: VOID ID LP RP Block  */
#line 87 "parser.y"
                             { (yyval.node_val) = new_node(FuncDef, NULL, NULL, (yyvsp[0].node_val), 0, 0, (yyvsp[-3].str_val), Void); }
#line 1879 "parser.c"
    break;

  case 36: /* FuncDef: INT ID LP FuncFParam RP Block  */
#line 88 "parser.y"
                                       { (yyval.node_val) = new_node(FuncDef, NULL, (yyvsp[-2].node_val), (yyvsp[0].node_val), 0, 0, (yyvsp[-4].str_val), Int); }
#line 1885 "parser.c"
    break;

  case 37: /* FuncDef: FLOAT ID LP FuncFParam RP Block  */
#line 89 "parser.y"
                                         { (yyval.node_val) = new_node(FuncDef, NULL, (yyvsp[-2].node_val), (yyvsp[0].node_val), 0, 0, (yyvsp[-4].str_val), Float); }
#line 1891 "parser.c"
    break;

  case 38: /* FuncDef: VOID ID LP FuncFParam RP Block  */
#line 90 "parser.y"
                                        { (yyval.node_val) = new_node(FuncDef, NULL, (yyvsp[-2].node_val), (yyvsp[0].node_val), 0, 0, (yyvsp[-4].str_val), Void); }
#line 1897 "parser.c"
    break;

  case 39: /* FuncFParam: INT ID  */
#line 91 "parser.y"
                   { (yyval.node_val) = new_node(FuncFParam, NULL, NULL, NULL, 0, 0, (yyvsp[0].str_val), Int); }
#line 1903 "parser.c"
    break;

  case 40: /* FuncFParam: FLOAT ID  */
#line 92 "parser.y"
                     { (yyval.node_val) = new_node(FuncFParam, NULL, NULL, NULL, 0, 0, (yyvsp[0].str_val), Float); }
#line 1909 "parser.c"
    break;

  case 41: /* FuncFParam: INT ID LB RB ExpArray  */
#line 93 "parser.y"
                                  { (yyval.node_val) = new_node(FuncFParam, NULL, NULL, (yyvsp[0].node_val), 0, 0, (yyvsp[-3].str_val), Int); }
#line 1915 "parser.c"
    break;

  case 42: /* FuncFParam: FLOAT ID LB RB ExpArray  */
#line 94 "parser.y"
                                    { (yyval.node_val) = new_node(FuncFParam, NULL, NULL, (yyvsp[0].node_val), 0, 0, (yyvsp[-3].str_val), Float); }
#line 1921 "parser.c"
    break;

  case 43: /* FuncFParam: INT ID COMMA FuncFParam  */
#line 95 "parser.y"
                                    { (yyval.node_val) = new_node(FuncFParam, (yyvsp[0].node_val), NULL, NULL, 0, 0, (yyvsp[-2].str_val), Int); }
#line 1927 "parser.c"
    break;

  case 44: /* FuncFParam: FLOAT ID COMMA FuncFParam  */
#line 96 "parser.y"
                                      { (yyval.node_val) = new_node(FuncFParam, (yyvsp[0].node_val), NULL, NULL, 0, 0, (yyvsp[-2].str_val), Float); }
#line 1933 "parser.c"
    break;

  case 45: /* FuncFParam: INT ID LB RB ExpArray COMMA FuncFParam  */
#line 97 "parser.y"
                                                   { (yyval.node_val) = new_node(FuncFParam, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), 0, 0, (yyvsp[-5].str_val), Int); }
#line 1939 "parser.c"
    break;

  case 46: /* FuncFParam: FLOAT ID LB RB ExpArray COMMA FuncFParam  */
#line 98 "parser.y"
                                                     { (yyval.node_val) = new_node(FuncFParam, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), 0, 0, (yyvsp[-5].str_val), Float); }
#line 1945 "parser.c"
    break;

  case 47: /* Block: LC BlockItem RC  */
#line 100 "parser.y"
                       { (yyval.node_val) = new_node(Block, NULL, NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1951 "parser.c"
    break;

  case 48: /* BlockItem: %empty  */
#line 101 "parser.y"
           { (yyval.node_val) = NULL; }
#line 1957 "parser.c"
    break;

  case 49: /* BlockItem: ConstDecl BlockItem  */
#line 102 "parser.y"
                               { (yyval.node_val) = new_node(BlockItem, (yyvsp[0].node_val), NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1963 "parser.c"
    break;

  case 50: /* BlockItem: VarDecl BlockItem  */
#line 103 "parser.y"
                             { (yyval.node_val) = new_node(BlockItem, (yyvsp[0].node_val), NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1969 "parser.c"
    break;

  case 51: /* BlockItem: Stmt BlockItem  */
#line 104 "parser.y"
                          { (yyval.node_val) = new_node(BlockItem, (yyvsp[0].node_val), NULL, (yyvsp[-1].node_val), 0, 0, NULL, NonType); }
#line 1975 "parser.c"
    break;

  case 52: /* Stmt: LVal ASSIGN Exp SEMICOLON  */
#line 112 "parser.y"
                                 { 
			(yyval.node_val) = new_node(Stmt,(yyvsp[-3].node_val),NULL,(yyvsp[-1].node_val),AssignStmt,0,NULL,NonType); }
#line 1982 "parser.c"
    break;

  case 53: /* Stmt: Exp SEMICOLON  */
#line 114 "parser.y"
                                { 
			(yyval.node_val) = new_node(Stmt,NULL,NULL,(yyvsp[-1].node_val),ExpStmt,0,NULL,NonType); }
#line 1989 "parser.c"
    break;

  case 54: /* Stmt: SEMICOLON  */
#line 116 "parser.y"
                            { 
			(yyval.node_val) = new_node(Stmt,NULL,NULL,(yyvsp[0].int_val),BlankStmt,0,NULL,NonType); }
#line 1996 "parser.c"
    break;

  case 55: /* Stmt: Block  */
#line 118 "parser.y"
                        { 
			(yyval.node_val) = new_node(Stmt,NULL,NULL,(yyvsp[0].node_val),Block,0,NULL,NonType); }
#line 2003 "parser.c"
    break;

  case 56: /* Stmt: IF LP Cond RP Stmt ELSE Stmt  */
#line 120 "parser.y"
                                               { 
			(yyval.node_val) = new_node(Stmt,(yyvsp[-4].node_val),(yyvsp[-2].node_val),(yyvsp[0].node_val),IfElseStmt,0,NULL,NonType);  }
#line 2010 "parser.c"
    break;

  case 57: /* Stmt: IF LP Cond RP Stmt  */
#line 122 "parser.y"
                                                { 
			(yyval.node_val) = new_node(Stmt,(yyvsp[-2].node_val),NULL,(yyvsp[0].node_val),IfStmt,0,NULL,NonType); }
#line 2017 "parser.c"
    break;

  case 58: /* Stmt: WHILE LP Cond RP Stmt  */
#line 124 "parser.y"
                                        { 
			(yyval.node_val) = new_node(Stmt,(yyvsp[-2].node_val),NULL,(yyvsp[0].node_val),WhileStmt,0,NULL,NonType); }
#line 2024 "parser.c"
    break;

  case 59: /* Stmt: BREAK SEMICOLON  */
#line 126 "parser.y"
                                   { 
			(yyval.node_val) = new_node(Stmt,NULL,NULL,NULL,BreakStmt,0,NULL,NonType); }
#line 2031 "parser.c"
    break;

  case 60: /* Stmt: CONTINUE SEMICOLON  */
#line 128 "parser.y"
                                     { 
			(yyval.node_val) = new_node(Stmt,NULL,NULL,NULL,ContinueStmt,0,NULL,NonType); }
#line 2038 "parser.c"
    break;

  case 61: /* Stmt: RETURN Exp SEMICOLON  */
#line 130 "parser.y"
                                       { 
			(yyval.node_val) = new_node(Stmt,NULL,NULL,(yyvsp[-1].node_val),ReturnStmt,0,NULL,NonType); }
#line 2045 "parser.c"
    break;

  case 62: /* Stmt: RETURN SEMICOLON  */
#line 132 "parser.y"
                                   { 
			(yyval.node_val) = new_node(Stmt,NULL,NULL,NULL,BlankReturnStmt,0,NULL,NonType); }
#line 2052 "parser.c"
    break;

  case 63: /* Exp: AddExp  */
#line 137 "parser.y"
            { (yyval.node_val) = new_node(Exp, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 2058 "parser.c"
    break;

  case 64: /* AddExp: MulExp  */
#line 138 "parser.y"
               { (yyval.node_val) = new_node(AddExp, NULL, NULL, (yyvsp[0].node_val), MUL, 0, NULL, NonType); }
#line 2064 "parser.c"
    break;

  case 65: /* AddExp: MulExp PLUS AddExp  */
#line 139 "parser.y"
                           { (yyval.node_val) = new_node(AddExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), PLUS, 0, NULL, NonType); }
#line 2070 "parser.c"
    break;

  case 66: /* AddExp: MulExp MINUS AddExp  */
#line 140 "parser.y"
                            { (yyval.node_val) = new_node(AddExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), MINUS, 0, NULL, NonType); }
#line 2076 "parser.c"
    break;

  case 67: /* MulExp: UnaryExp  */
#line 141 "parser.y"
                 { (yyval.node_val) = new_node(MulExp, NULL, NULL, (yyvsp[0].node_val), UnaryExp, 0, NULL, NonType); }
#line 2082 "parser.c"
    break;

  case 68: /* MulExp: UnaryExp MUL MulExp  */
#line 142 "parser.y"
                            { (yyval.node_val) = new_node(MulExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), MUL, 0, NULL, NonType); }
#line 2088 "parser.c"
    break;

  case 69: /* MulExp: UnaryExp DIV MulExp  */
#line 143 "parser.y"
                            { (yyval.node_val) = new_node(MulExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), DIV, 0, NULL, NonType); }
#line 2094 "parser.c"
    break;

  case 70: /* MulExp: UnaryExp MOD MulExp  */
#line 144 "parser.y"
                            { (yyval.node_val) = new_node(MulExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), MOD, 0, NULL, NonType); }
#line 2100 "parser.c"
    break;

  case 71: /* UnaryExp: PrimaryExp  */
#line 145 "parser.y"
                     { (yyval.node_val) = new_node(UnaryExp, NULL, NULL, (yyvsp[0].node_val), PrimaryExp, 0, NULL, NonType); }
#line 2106 "parser.c"
    break;

  case 72: /* UnaryExp: ID LP RP  */
#line 146 "parser.y"
                   { (yyval.node_val) = new_node(UnaryExp, NULL, NULL, NULL, FuncRParams, 0, (yyvsp[-2].str_val), NonType); }
#line 2112 "parser.c"
    break;

  case 73: /* UnaryExp: ID LP FuncRParams RP  */
#line 147 "parser.y"
                               { (yyval.node_val) = new_node(UnaryExp, NULL, NULL, (yyvsp[-1].node_val), FuncRParams, 0, (yyvsp[-3].str_val), NonType); }
#line 2118 "parser.c"
    break;

  case 74: /* UnaryExp: PLUS UnaryExp  */
#line 148 "parser.y"
                        { (yyval.node_val) = new_node(UnaryExp, NULL, NULL, (yyvsp[0].node_val), Plus, 0, NULL, NonType); }
#line 2124 "parser.c"
    break;

  case 75: /* UnaryExp: MINUS UnaryExp  */
#line 149 "parser.y"
                         { (yyval.node_val) = new_node(UnaryExp, NULL, NULL, (yyvsp[0].node_val), Minus, 0, NULL, NonType); }
#line 2130 "parser.c"
    break;

  case 76: /* UnaryExp: NOT UnaryExp  */
#line 150 "parser.y"
                       { (yyval.node_val) = new_node(UnaryExp, NULL, NULL, (yyvsp[0].node_val), NOT, 0, NULL, NonType); }
#line 2136 "parser.c"
    break;

  case 77: /* FuncRParams: Exp  */
#line 151 "parser.y"
                 { (yyval.node_val) = new_node(FuncRParams, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 2142 "parser.c"
    break;

  case 78: /* FuncRParams: Exp COMMA FuncRParams  */
#line 152 "parser.y"
                                   { (yyval.node_val) = new_node(FuncRParams, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), 0, 0, NULL, NonType); }
#line 2148 "parser.c"
    break;

  case 79: /* PrimaryExp: LP Exp RP  */
#line 153 "parser.y"
                      { (yyval.node_val) = new_node(PrimaryExp, NULL, NULL, (yyvsp[-1].node_val), Exp, 0, NULL, NonType); }
#line 2154 "parser.c"
    break;

  case 80: /* PrimaryExp: LVal  */
#line 154 "parser.y"
                 { (yyval.node_val) = new_node(PrimaryExp, NULL, NULL, (yyvsp[0].node_val), LVal, 0, NULL, NonType); }
#line 2160 "parser.c"
    break;

  case 81: /* PrimaryExp: INT_LIT  */
#line 155 "parser.y"
                    { (yyval.node_val) = new_node(PrimaryExp, NULL, NULL, NULL, (yyvsp[0].int_val), 0, NULL, Int); }
#line 2166 "parser.c"
    break;

  case 82: /* PrimaryExp: FLOAT_LIT  */
#line 156 "parser.y"
                      { (yyval.node_val) = new_node(PrimaryExp, NULL, NULL, NULL, 0, (yyvsp[0].float_val), NULL, Float); }
#line 2172 "parser.c"
    break;

  case 83: /* LVal: ID ExpArray  */
#line 157 "parser.y"
                  { (yyval.node_val) = new_node(LVal, NULL, NULL, (yyvsp[0].node_val), 0, 0, (yyvsp[-1].str_val), NonType); }
#line 2178 "parser.c"
    break;

  case 84: /* Cond: LOrExp  */
#line 159 "parser.y"
             { (yyval.node_val) = new_node(Cond, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 2184 "parser.c"
    break;

  case 85: /* LOrExp: LAndExp  */
#line 160 "parser.y"
                { (yyval.node_val) = new_node(Cond, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 2190 "parser.c"
    break;

  case 86: /* LOrExp: LAndExp OR LOrExp  */
#line 161 "parser.y"
                          { (yyval.node_val) = new_node(Cond, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), OR, 0, 0, NonType); }
#line 2196 "parser.c"
    break;

  case 87: /* LAndExp: EqExp  */
#line 162 "parser.y"
               { (yyval.node_val) = new_node(LAndExp, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 2202 "parser.c"
    break;

  case 88: /* LAndExp: EqExp AND LAndExp  */
#line 163 "parser.y"
                           { (yyval.node_val) = new_node(LAndExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), AND, 0, NULL, NonType); }
#line 2208 "parser.c"
    break;

  case 89: /* EqExp: RelExp  */
#line 164 "parser.y"
              { (yyval.node_val) = new_node(EqExp, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 2214 "parser.c"
    break;

  case 90: /* EqExp: RelExp EQ EqExp  */
#line 165 "parser.y"
                       { (yyval.node_val) = new_node(EqExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), EQ, 0, NULL, NonType); }
#line 2220 "parser.c"
    break;

  case 91: /* EqExp: RelExp NE EqExp  */
#line 166 "parser.y"
                       { (yyval.node_val) = new_node(EqExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), NE, 0, NULL, NonType); }
#line 2226 "parser.c"
    break;

  case 92: /* RelExp: AddExp  */
#line 167 "parser.y"
               { (yyval.node_val) = new_node(RelExp, NULL, NULL, (yyvsp[0].node_val), 0, 0, NULL, NonType); }
#line 2232 "parser.c"
    break;

  case 93: /* RelExp: AddExp LT RelExp  */
#line 168 "parser.y"
                         { (yyval.node_val) = new_node(RelExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), LT, 0, NULL, NonType); }
#line 2238 "parser.c"
    break;

  case 94: /* RelExp: AddExp GT RelExp  */
#line 169 "parser.y"
                         { (yyval.node_val) = new_node(RelExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), GT, 0, NULL, NonType); }
#line 2244 "parser.c"
    break;

  case 95: /* RelExp: AddExp LE RelExp  */
#line 170 "parser.y"
                         { (yyval.node_val) = new_node(RelExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), LE, 0, NULL, NonType); }
#line 2250 "parser.c"
    break;

  case 96: /* RelExp: AddExp GE RelExp  */
#line 171 "parser.y"
                         { (yyval.node_val) = new_node(RelExp, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), GE, 0, NULL, NonType); }
#line 2256 "parser.c"
    break;

  case 97: /* ExpArray: %empty  */
#line 173 "parser.y"
          { (yyval.node_val) = NULL; }
#line 2262 "parser.c"
    break;

  case 98: /* ExpArray: LB Exp RB ExpArray  */
#line 174 "parser.y"
                             { (yyval.node_val) = new_node(ExpArray, (yyvsp[0].node_val), NULL, (yyvsp[-2].node_val), 0, 0, NULL, NonType); }
#line 2268 "parser.c"
    break;


#line 2272 "parser.c"

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
  *++yylsp = yyloc;

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 175 "parser.y"


int main(int argc, char *argv[]) {
    int index = strlen(argv[1]) - 1;
    while(index > 0 && argv[1][index - 1] != '/')
        index--;
    strcpy(filename, argv[1] + index);
    freopen(argv[1], "r", stdin);
    yyparse();
    if (syntax_error == 0) 
        display(root);
    return 0;
}

/*
void yyerror(char *msg) {
    printf("%s:%d\n", name, yylineno);
    printf("error text: %s\n", yytext);
    exit(-1);
}
*/
#include<stdarg.h>
void yyerror(const char* fmt, ...)
{
    syntax_error = 1;    
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "%s:%d ", filename, yylineno);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}	
