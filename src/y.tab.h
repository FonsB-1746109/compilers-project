/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
  CompStmt compstmt;
  Stmt stmt;
  Elsif elsif;
  When when;
  Else els;
  Expr expr;
  Exprs exprs;
  Literal literal;
  ArgList arglist;

#line 175 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
