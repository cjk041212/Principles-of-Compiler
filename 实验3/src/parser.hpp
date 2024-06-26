/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    ID = 260,                      /* ID  */
    GTE = 261,                     /* GTE  */
    LTE = 262,                     /* LTE  */
    GT = 263,                      /* GT  */
    LT = 264,                      /* LT  */
    EQ = 265,                      /* EQ  */
    NEQ = 266,                     /* NEQ  */
    INTTYPE = 267,                 /* INTTYPE  */
    FLOATTYPE = 268,               /* FLOATTYPE  */
    VOID = 269,                    /* VOID  */
    CONST = 270,                   /* CONST  */
    RETURN = 271,                  /* RETURN  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    WHILE = 274,                   /* WHILE  */
    BREAK = 275,                   /* BREAK  */
    CONTINUE = 276,                /* CONTINUE  */
    LP = 277,                      /* LP  */
    RP = 278,                      /* RP  */
    LB = 279,                      /* LB  */
    RB = 280,                      /* RB  */
    LC = 281,                      /* LC  */
    RC = 282,                      /* RC  */
    COMMA = 283,                   /* COMMA  */
    SEMICOLON = 284,               /* SEMICOLON  */
    NOT = 285,                     /* NOT  */
    POS = 286,                     /* POS  */
    NEG = 287,                     /* NEG  */
    ASSIGN = 288,                  /* ASSIGN  */
    MINUS = 289,                   /* MINUS  */
    ADD = 290,                     /* ADD  */
    MUL = 291,                     /* MUL  */
    DIV = 292,                     /* DIV  */
    MOD = 293,                     /* MOD  */
    AND = 294,                     /* AND  */
    OR = 295,                      /* OR  */
    LOWER_THEN_ELSE = 296          /* LOWER_THEN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "parser.y"

    CompUnitAST* compUnit;
    DeclDefAST* declDef;
    DeclAST* decl;
    DefListAST* defList;
    DefAST* def;
    ArraysAST* arrays;
    InitValListAST* initValList;
    InitValAST* initVal;
    FuncDefAST* funcDef;
    FuncFParamListAST* FuncFParamList;
    FuncFParamAST* funcFParam;
    BlockAST* block;
    BlockItemListAST* blockItemList;
    BlockItemAST* blockItem;
    StmtAST* stmt;
    ReturnStmtAST* returnStmt;
    SelectStmtAST* selectStmt;
    IterationStmtAST* iterationStmt;
    LValAST* lVal;
    PrimaryExpAST* primaryExp;
    NumberAST* number;
    UnaryExpAST* unaryExp;
    CallAST* call;
    FuncCParamListAST* funcCParamList;
    MulExpAST* mulExp;
    AddExpAST* addExp;
    RelExpAST* relExp;
    EqExpAST* eqExp;
    LAndExpAST* lAndExp;
    LOrExpAST* lOrExp;

    TYPE ty;
    UOP op;
	string* token;
	int int_val;
	float float_val;

#line 144 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
