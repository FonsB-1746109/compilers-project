/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ruby.y"

#include "absyn.hpp"

#include "lexer.h"
#include <stdio.h>



void yyerror(const char* str);

Program tree;

#line 84 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTEGER = 259,                 /* INTEGER  */
    BOOLEAN = 260,                 /* BOOLEAN  */
    SEMICOLON = 261,               /* SEMICOLON  */
    LPAREN = 262,                  /* LPAREN  */
    RPAREN = 263,                  /* RPAREN  */
    COMMA = 264,                   /* COMMA  */
    IF = 265,                      /* IF  */
    THEN = 266,                    /* THEN  */
    ELSIF = 267,                   /* ELSIF  */
    ELSE = 268,                    /* ELSE  */
    UNLESS = 269,                  /* UNLESS  */
    WHILE = 270,                   /* WHILE  */
    DO = 271,                      /* DO  */
    UNTIL = 272,                   /* UNTIL  */
    CASE = 273,                    /* CASE  */
    WHEN = 274,                    /* WHEN  */
    END = 275,                     /* END  */
    RETURN = 276,                  /* RETURN  */
    ASSIGN = 277,                  /* ASSIGN  */
    PLUSASSIGN = 278,              /* PLUSASSIGN  */
    MINUSASSIGN = 279,             /* MINUSASSIGN  */
    MULASSIGN = 280,               /* MULASSIGN  */
    DIVASSIGN = 281,               /* DIVASSIGN  */
    ANDASSIGN = 282,               /* ANDASSIGN  */
    ORASSIGN = 283,                /* ORASSIGN  */
    PLUS = 284,                    /* PLUS  */
    MINUS = 285,                   /* MINUS  */
    MUL = 286,                     /* MUL  */
    DIV = 287,                     /* DIV  */
    GT = 288,                      /* GT  */
    GE = 289,                      /* GE  */
    LT = 290,                      /* LT  */
    LE = 291,                      /* LE  */
    EQ = 292,                      /* EQ  */
    NE = 293,                      /* NE  */
    AND = 294,                     /* AND  */
    OR = 295,                      /* OR  */
    NOT = 296,                     /* NOT  */
    UNDEF = 297,                   /* UNDEF  */
    DEF = 298,                     /* DEF  */
    NEWLINE = 299,                 /* NEWLINE  */
    PRINT = 300,                   /* PRINT  */
    UMINUS = 301                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define INTEGER 259
#define BOOLEAN 260
#define SEMICOLON 261
#define LPAREN 262
#define RPAREN 263
#define COMMA 264
#define IF 265
#define THEN 266
#define ELSIF 267
#define ELSE 268
#define UNLESS 269
#define WHILE 270
#define DO 271
#define UNTIL 272
#define CASE 273
#define WHEN 274
#define END 275
#define RETURN 276
#define ASSIGN 277
#define PLUSASSIGN 278
#define MINUSASSIGN 279
#define MULASSIGN 280
#define DIVASSIGN 281
#define ANDASSIGN 282
#define ORASSIGN 283
#define PLUS 284
#define MINUS 285
#define MUL 286
#define DIV 287
#define GT 288
#define GE 289
#define LT 290
#define LE 291
#define EQ 292
#define NE 293
#define AND 294
#define OR 295
#define NOT 296
#define UNDEF 297
#define DEF 298
#define NEWLINE 299
#define PRINT 300
#define UMINUS 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "ruby.y"

  char* id;
  int integer;
  bool boolean;

  Program program;
  Compstmt compstmt;
  Stmt stmt;
  Elsif elsif;
  When when;
  Else else;
  Expr expr;
  Exprs exprs;
  Literal literal;
  Arglist arglist;

#line 245 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_BOOLEAN = 5,                    /* BOOLEAN  */
  YYSYMBOL_SEMICOLON = 6,                  /* SEMICOLON  */
  YYSYMBOL_LPAREN = 7,                     /* LPAREN  */
  YYSYMBOL_RPAREN = 8,                     /* RPAREN  */
  YYSYMBOL_COMMA = 9,                      /* COMMA  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_THEN = 11,                      /* THEN  */
  YYSYMBOL_ELSIF = 12,                     /* ELSIF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_UNLESS = 14,                    /* UNLESS  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_DO = 16,                        /* DO  */
  YYSYMBOL_UNTIL = 17,                     /* UNTIL  */
  YYSYMBOL_CASE = 18,                      /* CASE  */
  YYSYMBOL_WHEN = 19,                      /* WHEN  */
  YYSYMBOL_END = 20,                       /* END  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_PLUSASSIGN = 23,                /* PLUSASSIGN  */
  YYSYMBOL_MINUSASSIGN = 24,               /* MINUSASSIGN  */
  YYSYMBOL_MULASSIGN = 25,                 /* MULASSIGN  */
  YYSYMBOL_DIVASSIGN = 26,                 /* DIVASSIGN  */
  YYSYMBOL_ANDASSIGN = 27,                 /* ANDASSIGN  */
  YYSYMBOL_ORASSIGN = 28,                  /* ORASSIGN  */
  YYSYMBOL_PLUS = 29,                      /* PLUS  */
  YYSYMBOL_MINUS = 30,                     /* MINUS  */
  YYSYMBOL_MUL = 31,                       /* MUL  */
  YYSYMBOL_DIV = 32,                       /* DIV  */
  YYSYMBOL_GT = 33,                        /* GT  */
  YYSYMBOL_GE = 34,                        /* GE  */
  YYSYMBOL_LT = 35,                        /* LT  */
  YYSYMBOL_LE = 36,                        /* LE  */
  YYSYMBOL_EQ = 37,                        /* EQ  */
  YYSYMBOL_NE = 38,                        /* NE  */
  YYSYMBOL_AND = 39,                       /* AND  */
  YYSYMBOL_OR = 40,                        /* OR  */
  YYSYMBOL_NOT = 41,                       /* NOT  */
  YYSYMBOL_UNDEF = 42,                     /* UNDEF  */
  YYSYMBOL_DEF = 43,                       /* DEF  */
  YYSYMBOL_NEWLINE = 44,                   /* NEWLINE  */
  YYSYMBOL_PRINT = 45,                     /* PRINT  */
  YYSYMBOL_UMINUS = 46,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_compstmt = 49,                  /* compstmt  */
  YYSYMBOL_stmt = 50,                      /* stmt  */
  YYSYMBOL_elsif = 51,                     /* elsif  */
  YYSYMBOL_when = 52,                      /* when  */
  YYSYMBOL_else = 53,                      /* else  */
  YYSYMBOL_expr = 54,                      /* expr  */
  YYSYMBOL_literal = 55,                   /* literal  */
  YYSYMBOL_exprs = 56,                     /* exprs  */
  YYSYMBOL_arglist = 57,                   /* arglist  */
  YYSYMBOL_then = 58,                      /* then  */
  YYSYMBOL_do = 59,                        /* do  */
  YYSYMBOL_t = 60                          /* t  */
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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   309

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    66,    66,    70,    72,    74,    78,    80,    82,    84,
      86,    88,    90,    92,    94,    96,   101,   102,   107,   108,
     114,   115,   119,   121,   123,   125,   127,   129,   131,   133,
     135,   137,   139,   141,   143,   145,   147,   149,   151,   153,
     155,   157,   159,   161,   163,   165,   167,   169,   173,   175,
     180,   181,   183,   188,   189,   191,   195,   196,   197,   200,
     201,   202,   205,   206
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTEGER", "BOOLEAN", "SEMICOLON", "LPAREN", "RPAREN", "COMMA", "IF",
  "THEN", "ELSIF", "ELSE", "UNLESS", "WHILE", "DO", "UNTIL", "CASE",
  "WHEN", "END", "RETURN", "ASSIGN", "PLUSASSIGN", "MINUSASSIGN",
  "MULASSIGN", "DIVASSIGN", "ANDASSIGN", "ORASSIGN", "PLUS", "MINUS",
  "MUL", "DIV", "GT", "GE", "LT", "LE", "EQ", "NE", "AND", "OR", "NOT",
  "UNDEF", "DEF", "NEWLINE", "PRINT", "UMINUS", "$accept", "program",
  "compstmt", "stmt", "elsif", "when", "else", "expr", "literal", "exprs",
  "arglist", "then", "do", "t", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
#endif

#define YYPACT_NINF (-97)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-51)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     150,   -97,   116,   -97,   -97,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    11,    13,    20,    29,   -97,     9,
     269,   -97,    60,    75,    75,    75,    75,    75,    75,    75,
     218,   167,   167,   202,   202,   257,   269,   -97,   -97,   -97,
      28,    75,   -97,   -97,   -97,   107,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,   269,     4,
     269,   269,   269,   269,   269,   269,   269,   -97,   -97,   150,
      44,   150,   -97,   150,    41,   150,    75,    56,   235,   -97,
       6,     6,   -97,   -97,   269,   269,   269,   269,   269,   269,
       2,     2,   -97,    75,    50,   -97,    53,    52,   -97,    54,
     167,   -97,    31,   -97,   269,    75,    53,   150,    55,   -97,
     -97,   150,   150,    67,   167,    61,   -97,   -97,    64,    65,
     -97,   150,   -97,    75,    53,   -97,    50,   167,    66,   -97,
     150,   -97,    64,   -97
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    47,    43,    49,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
      15,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,    44,    41,     7,
       0,     0,     1,    62,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
      22,    23,    24,    25,    26,    27,    28,    46,    57,     0,
      56,     0,    60,     0,    59,     0,     0,    53,     0,     5,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    45,     0,    16,    58,    20,     0,    61,     0,
       0,    54,     0,     6,    52,     0,    20,     0,     0,    12,
      13,     0,     0,     0,     0,     0,    21,    11,    18,     0,
      55,     0,    10,     0,    20,     8,    16,     0,     0,    17,
       0,    14,    18,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -97,   -97,   -15,   -97,   -53,   -48,   -96,    -5,   -97,   -97,
     -97,   -23,    59,    -8
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    17,    18,    19,   106,   124,   108,    20,    21,    59,
     102,    69,    73,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    31,    32,    33,    34,    35,    36,    37,    38,    71,
     115,    45,    92,    93,    39,    43,    40,    58,    60,    61,
      62,    63,    64,    65,    66,    74,    74,    41,   128,    42,
      79,    46,    47,    48,    49,    77,    78,    48,    49,   112,
     113,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    44,    94,    95,    96,    98,    97,   101,
      99,     1,   105,     2,     3,     4,   107,     5,   -50,   -50,
     120,   100,   109,   129,   110,   117,     1,   111,     2,     3,
       4,   122,     5,   123,   133,   125,   131,     0,   104,     0,
      12,   121,   116,    75,     0,     0,   118,   119,     0,     0,
     114,    13,     0,     0,   130,    12,   126,    -4,     1,     0,
       2,     3,     4,     0,     5,   132,    13,     6,   127,    -4,
      -4,     7,     8,    22,     9,    10,    -4,    -4,    11,     0,
       0,     0,     0,     0,     0,     0,     0,    12,    23,    24,
      25,    26,    27,    28,    29,     0,     0,     0,    13,    14,
      15,     1,    16,     2,     3,     4,     0,     5,     0,     0,
       6,     0,     0,     0,     7,     8,     0,     9,    10,     0,
       0,    11,     0,    43,     0,     0,     0,     0,    68,     0,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,    15,     0,    16,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    43,     0,
       0,    44,     0,     0,     0,     0,     0,     0,    72,     0,
       0,     0,     0,     0,     0,     0,    67,     0,     0,     0,
       0,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   103,     0,     0,    44,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,     0,     0,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57
};

static const yytype_int16 yycheck[] =
{
       5,     6,     7,     8,     9,    10,    11,    12,    13,    32,
     106,    19,     8,     9,     3,     6,     3,    22,    23,    24,
      25,    26,    27,    28,    29,    33,    34,     7,   124,     0,
      45,    29,    30,    31,    32,     7,    41,    31,    32,     8,
       9,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    44,    69,    11,    71,    16,    73,     3,
      75,     1,    12,     3,     4,     5,    13,     7,     8,     9,
       3,    76,    20,   126,    20,    20,     1,   100,     3,     4,
       5,    20,     7,    19,   132,    20,    20,    -1,    93,    -1,
      30,   114,   107,    34,    -1,    -1,   111,   112,    -1,    -1,
     105,    41,    -1,    -1,   127,    30,   121,     0,     1,    -1,
       3,     4,     5,    -1,     7,   130,    41,    10,   123,    12,
      13,    14,    15,     7,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    41,    42,
      43,     1,    45,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    -1,    -1,    -1,    14,    15,    -1,    17,    18,    -1,
      -1,    21,    -1,     6,    -1,    -1,    -1,    -1,    11,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    -1,    45,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     6,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     8,    -1,    -1,    44,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     7,    10,    14,    15,    17,
      18,    21,    30,    41,    42,    43,    45,    48,    49,    50,
      54,    55,     7,    22,    23,    24,    25,    26,    27,    28,
      54,    54,    54,    54,    54,    54,    54,    54,    54,     3,
       3,     7,     0,     6,    44,    60,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    54,    56,
      54,    54,    54,    54,    54,    54,    54,     8,    11,    58,
      60,    58,    16,    59,    60,    59,    19,     7,    54,    49,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,     8,     9,    49,    11,    49,    49,    16,    49,
      54,     3,    57,     8,    54,    12,    51,    13,    53,    20,
      20,    58,     8,     9,    54,    53,    49,    20,    49,    49,
       3,    58,    20,    19,    52,    20,    49,    54,    53,    51,
      58,    20,    49,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    55,    55,
      56,    56,    56,    57,    57,    57,    58,    58,    58,    59,
      59,    59,    60,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     4,     2,     7,     2,
       7,     6,     5,     5,     9,     1,     0,     5,     0,     5,
       0,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     1,     2,     4,     3,     1,     1,     1,
       0,     1,     3,     0,     1,     3,     1,     1,     2,     1,
       1,     2,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* program: compstmt  */
#line 67 "ruby.y"
        { (yyval.program) = new Program((yyvsp[0].compstmt)); tree = (yyval.program); }
#line 1398 "y.tab.c"
    break;

  case 3: /* compstmt: stmt  */
#line 71 "ruby.y"
        { (yyval.compstmt) = new Compstmt((yyvsp[0].stmt)); }
#line 1404 "y.tab.c"
    break;

  case 4: /* compstmt: stmt t  */
#line 73 "ruby.y"
        { (yyval.compstmt) = new Compstmt((yyvsp[-1].stmt)); }
#line 1410 "y.tab.c"
    break;

  case 5: /* compstmt: stmt t compstmt  */
#line 75 "ruby.y"
        { (yyval.compstmt) = new Compstmt((yyvsp[-2].stmt), (yyvsp[0].compstmt)); }
#line 1416 "y.tab.c"
    break;

  case 6: /* stmt: PRINT LPAREN expr RPAREN  */
#line 79 "ruby.y"
        { (yyval.stmt) = new PrintStmt((yyvsp[-1].expr)); }
#line 1422 "y.tab.c"
    break;

  case 7: /* stmt: UNDEF IDENTIFIER  */
#line 81 "ruby.y"
        { (yyval.stmt) = new UndefStmt((yyvsp[0].id)); }
#line 1428 "y.tab.c"
    break;

  case 8: /* stmt: DEF IDENTIFIER LPAREN arglist RPAREN compstmt END  */
#line 83 "ruby.y"
        { (yyval.stmt) = new DefStmt((yyvsp[-5].id), (yyvsp[-3].arglist), (yyvsp[-1].compstmt)); }
#line 1434 "y.tab.c"
    break;

  case 9: /* stmt: RETURN expr  */
#line 85 "ruby.y"
        { (yyval.stmt) = new ReturnStmt((yyvsp[0].expr)); }
#line 1440 "y.tab.c"
    break;

  case 10: /* stmt: IF expr then compstmt elsif else END  */
#line 87 "ruby.y"
        { (yyval.stmt) = new IfStmt((yyvsp[-5].expr), (yyvsp[-3].compstmt), (yyvsp[-2].elsif), (yyvsp[-1].else)); }
#line 1446 "y.tab.c"
    break;

  case 11: /* stmt: UNLESS expr then compstmt else END  */
#line 89 "ruby.y"
        { (yyval.stmt) = new UnlessStmt((yyvsp[-4].expr), (yyvsp[-2].compstmt), (yyvsp[-1].else)); }
#line 1452 "y.tab.c"
    break;

  case 12: /* stmt: WHILE expr do compstmt END  */
#line 91 "ruby.y"
        { (yyval.stmt) = new WhileStmt((yyvsp[-3].expr), (yyvsp[-1].compstmt)); }
#line 1458 "y.tab.c"
    break;

  case 13: /* stmt: UNTIL expr do compstmt END  */
#line 93 "ruby.y"
        { (yyval.stmt) = new UntilStmt((yyvsp[-3].expr), (yyvsp[-1].compstmt)); }
#line 1464 "y.tab.c"
    break;

  case 14: /* stmt: CASE expr WHEN expr then compstmt when else END  */
#line 95 "ruby.y"
        { (yyval.stmt) = new CaseStmt((yyvsp[-7].expr), (yyvsp[-5].expr), (yyvsp[-3].compstmt), (yyvsp[-2].when), (yyvsp[-1].else)); }
#line 1470 "y.tab.c"
    break;

  case 15: /* stmt: expr  */
#line 97 "ruby.y"
        { (yyval.stmt) = new ExprStmt((yyvsp[0].expr)); }
#line 1476 "y.tab.c"
    break;

  case 16: /* elsif: %empty  */
#line 101 "ruby.y"
        { (yyval.elsif) = new Elsif(); }
#line 1482 "y.tab.c"
    break;

  case 17: /* elsif: ELSIF expr then compstmt elsif  */
#line 103 "ruby.y"
        { (yyval.elsif) = new Elsif((yyvsp[-3].expr), (yyvsp[-1].compstmt), (yyvsp[0].elsif)); }
#line 1488 "y.tab.c"
    break;

  case 18: /* when: %empty  */
#line 107 "ruby.y"
        { (yyval.when) = new When(); }
#line 1494 "y.tab.c"
    break;

  case 19: /* when: WHEN expr then compstmt when  */
#line 109 "ruby.y"
        { (yyval.when) = new When((yyvsp[-3].expr), (yyvsp[-1].compstmt), (yyvsp[0].when)); }
#line 1500 "y.tab.c"
    break;

  case 20: /* else: %empty  */
#line 114 "ruby.y"
        { (yyval.else) = new Else(); }
#line 1506 "y.tab.c"
    break;

  case 21: /* else: ELSE compstmt  */
#line 116 "ruby.y"
        { (yyval.else) = new Else((yyvsp[0].compstmt)); }
#line 1512 "y.tab.c"
    break;

  case 22: /* expr: IDENTIFIER ASSIGN expr  */
#line 120 "ruby.y"
        { (yyval.expr) = new AssignOpExpr((yyvsp[-2].id), Assignop::Assign, (yyvsp[0].expr)); }
#line 1518 "y.tab.c"
    break;

  case 23: /* expr: IDENTIFIER PLUSASSIGN expr  */
#line 122 "ruby.y"
        { (yyval.expr) = new AssignOpExpr((yyvsp[-2].id), Assignop::PlusAssign, (yyvsp[0].expr)); }
#line 1524 "y.tab.c"
    break;

  case 24: /* expr: IDENTIFIER MINUSASSIGN expr  */
#line 124 "ruby.y"
        { (yyval.expr) = new AssignOpExpr((yyvsp[-2].id), Assignop::MinAssign, (yyvsp[0].expr)); }
#line 1530 "y.tab.c"
    break;

  case 25: /* expr: IDENTIFIER MULASSIGN expr  */
#line 126 "ruby.y"
        { (yyval.expr) = new AssignOpExpr((yyvsp[-2].id), Assignop::MulAssign, (yyvsp[0].expr)); }
#line 1536 "y.tab.c"
    break;

  case 26: /* expr: IDENTIFIER DIVASSIGN expr  */
#line 128 "ruby.y"
        { (yyval.expr) = new AssignOpExpr((yyvsp[-2].id), Assignop::DivAssign, (yyvsp[0].expr)); }
#line 1542 "y.tab.c"
    break;

  case 27: /* expr: IDENTIFIER ANDASSIGN expr  */
#line 130 "ruby.y"
        { (yyval.expr) = new AssignOpExpr((yyvsp[-2].id), Assignop::AndAssign, (yyvsp[0].expr)); }
#line 1548 "y.tab.c"
    break;

  case 28: /* expr: IDENTIFIER ORASSIGN expr  */
#line 132 "ruby.y"
        { (yyval.expr) = new AssignOpExpr((yyvsp[-2].id), Assignop::OrAssign, (yyvsp[0].expr)); }
#line 1554 "y.tab.c"
    break;

  case 29: /* expr: expr PLUS expr  */
#line 134 "ruby.y"
        { (yyval.expr) = new BinOpExpr((yyvsp[-2].expr), Binop::Plus, (yyvsp[0].expr)); }
#line 1560 "y.tab.c"
    break;

  case 30: /* expr: expr MINUS expr  */
#line 136 "ruby.y"
        { (yyval.expr) = new BinOpExpr((yyvsp[-2].expr), Binop::Minus, (yyvsp[0].expr)); }
#line 1566 "y.tab.c"
    break;

  case 31: /* expr: expr MUL expr  */
#line 138 "ruby.y"
        { (yyval.expr) = new BinOpExpr((yyvsp[-2].expr), Binop::Times, (yyvsp[0].expr)); }
#line 1572 "y.tab.c"
    break;

  case 32: /* expr: expr DIV expr  */
#line 140 "ruby.y"
        { (yyval.expr) = new BinOpExpr((yyvsp[-2].expr), Binop::Div, (yyvsp[0].expr)); }
#line 1578 "y.tab.c"
    break;

  case 33: /* expr: expr GT expr  */
#line 142 "ruby.y"
        { (yyval.expr) = new BinOpExpr((yyvsp[-2].expr), Binop::Gt, (yyvsp[0].expr)); }
#line 1584 "y.tab.c"
    break;

  case 34: /* expr: expr GE expr  */
#line 144 "ruby.y"
        { (yyval.expr) = new BinOpExpr((yyvsp[-2].expr), Binop::Ge, (yyvsp[0].expr)); }
#line 1590 "y.tab.c"
    break;

  case 35: /* expr: expr LT expr  */
#line 146 "ruby.y"
        { (yyval.expr) = new BinOpExpr((yyvsp[-2].expr), Binop::Lt, (yyvsp[0].expr)); }
#line 1596 "y.tab.c"
    break;

  case 36: /* expr: expr LE expr  */
#line 148 "ruby.y"
        { (yyval.expr) = new BinOpExpr((yyvsp[-2].expr), Binop::Le, (yyvsp[0].expr)); }
#line 1602 "y.tab.c"
    break;

  case 37: /* expr: expr EQ expr  */
#line 150 "ruby.y"
        { (yyval.expr) = new BinOpExpr((yyvsp[-2].expr), Binop::Eq, (yyvsp[0].expr)); }
#line 1608 "y.tab.c"
    break;

  case 38: /* expr: expr NE expr  */
#line 152 "ruby.y"
        { (yyval.expr) = new BinOpExpr((yyvsp[-2].expr), Binop::Ne, (yyvsp[0].expr)); }
#line 1614 "y.tab.c"
    break;

  case 39: /* expr: expr AND expr  */
#line 154 "ruby.y"
        { (yyval.expr) = new BinOpExpr((yyvsp[-2].expr), Binop::And, (yyvsp[0].expr)); }
#line 1620 "y.tab.c"
    break;

  case 40: /* expr: expr OR expr  */
#line 156 "ruby.y"
        { (yyval.expr) = new BinOpExpr((yyvsp[-2].expr), Binop::Or, (yyvsp[0].expr)); }
#line 1626 "y.tab.c"
    break;

  case 41: /* expr: NOT expr  */
#line 158 "ruby.y"
        { (yyval.expr) = new NotExpr((yyvsp[0].expr)); }
#line 1632 "y.tab.c"
    break;

  case 42: /* expr: literal  */
#line 160 "ruby.y"
        { (yyval.expr) = new LitExpr((yyvsp[0].literal)); }
#line 1638 "y.tab.c"
    break;

  case 43: /* expr: IDENTIFIER  */
#line 162 "ruby.y"
        { (yyval.expr) = new IdExpr((yyvsp[0].id)); }
#line 1644 "y.tab.c"
    break;

  case 44: /* expr: MINUS expr  */
#line 164 "ruby.y"
        { (yyval.expr) = new MinExpr((yyvsp[0].expr)); }
#line 1650 "y.tab.c"
    break;

  case 45: /* expr: IDENTIFIER LPAREN exprs RPAREN  */
#line 166 "ruby.y"
        { (yyval.expr) = new FunctionExpr((yyvsp[-3].id), (yyvsp[-1].exprs)); }
#line 1656 "y.tab.c"
    break;

  case 46: /* expr: LPAREN expr RPAREN  */
#line 168 "ruby.y"
        { (yyval.expr) = (yyvsp[-1].expr); }
#line 1662 "y.tab.c"
    break;

  case 47: /* expr: error  */
#line 170 "ruby.y"
        { (yyval.expr) = ErrorExpr(); }
#line 1668 "y.tab.c"
    break;

  case 48: /* literal: BOOLEAN  */
#line 174 "ruby.y"
        { (yyval.literal) = new Literal((yyvsp[0].boolean))}
#line 1674 "y.tab.c"
    break;

  case 49: /* literal: INTEGER  */
#line 176 "ruby.y"
        { (yyval.literal) = new Literal((yyvsp[0].integer))}
#line 1680 "y.tab.c"
    break;

  case 50: /* exprs: %empty  */
#line 180 "ruby.y"
        { (yyval.exprs) = new LastExprs(); }
#line 1686 "y.tab.c"
    break;

  case 51: /* exprs: expr  */
#line 182 "ruby.y"
        { (yyval.exprs) = new LastExprs((yyvsp[0].expr)); }
#line 1692 "y.tab.c"
    break;

  case 52: /* exprs: exprs COMMA expr  */
#line 184 "ruby.y"
        { (yyval.exprs) = new PairExprs((yyvsp[-2].exprs), (yyvsp[0].expr))}
#line 1698 "y.tab.c"
    break;

  case 53: /* arglist: %empty  */
#line 188 "ruby.y"
        { (yyval.arglist) = new LastArgList(); }
#line 1704 "y.tab.c"
    break;

  case 54: /* arglist: IDENTIFIER  */
#line 190 "ruby.y"
        { (yyval.arglist) = new LastArgList((yyvsp[0].id)); }
#line 1710 "y.tab.c"
    break;

  case 55: /* arglist: arglist COMMA IDENTIFIER  */
#line 192 "ruby.y"
        { (yyval.arglist) = new PairArgList((yyvsp[-2].arglist), (yyvsp[0].id)); }
#line 1716 "y.tab.c"
    break;


#line 1720 "y.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 210 "ruby.y"


void yyerror (const char *s)
{
  puts(s); 
}