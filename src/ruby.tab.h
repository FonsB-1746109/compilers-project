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

#ifndef YY_YY_RUBY_TAB_H_INCLUDED
# define YY_YY_RUBY_TAB_H_INCLUDED
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
    SEMICOLON = 258,               /* SEMICOLON  */
    LPAREN = 259,                  /* LPAREN  */
    RPAREN = 260,                  /* RPAREN  */
    COMMA = 261,                   /* COMMA  */
    IF = 262,                      /* IF  */
    THEN = 263,                    /* THEN  */
    ELSIF = 264,                   /* ELSIF  */
    ELSE = 265,                    /* ELSE  */
    UNLESS = 266,                  /* UNLESS  */
    WHILE = 267,                   /* WHILE  */
    DO = 268,                      /* DO  */
    UNTIL = 269,                   /* UNTIL  */
    CASE = 270,                    /* CASE  */
    WHEN = 271,                    /* WHEN  */
    END = 272,                     /* END  */
    RETURN = 273,                  /* RETURN  */
    ASSIGN = 274,                  /* ASSIGN  */
    PLUSASSIGN = 275,              /* PLUSASSIGN  */
    MINUSASSIGN = 276,             /* MINUSASSIGN  */
    MULASSIGN = 277,               /* MULASSIGN  */
    DIVASSIGN = 278,               /* DIVASSIGN  */
    ANDASSIGN = 279,               /* ANDASSIGN  */
    ORASSIGN = 280,                /* ORASSIGN  */
    PLUS = 281,                    /* PLUS  */
    MINUS = 282,                   /* MINUS  */
    MUL = 283,                     /* MUL  */
    DIV = 284,                     /* DIV  */
    GT = 285,                      /* GT  */
    GE = 286,                      /* GE  */
    LT = 287,                      /* LT  */
    LE = 288,                      /* LE  */
    EQ = 289,                      /* EQ  */
    NE = 290,                      /* NE  */
    AND = 291,                     /* AND  */
    OR = 292,                      /* OR  */
    NOT = 293,                     /* NOT  */
    BOOLEAN = 294,                 /* BOOLEAN  */
    INTEGER = 295,                 /* INTEGER  */
    IDENTIFIER = 296,              /* IDENTIFIER  */
    UNDEF = 297,                   /* UNDEF  */
    DEF = 298,                     /* DEF  */
    NEWLINE = 299,                 /* NEWLINE  */
    UMINUS = 300                   /* UMINUS  */
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

#endif /* !YY_YY_RUBY_TAB_H_INCLUDED  */
