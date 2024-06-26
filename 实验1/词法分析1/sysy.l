%option yylineno
%option noyywrap
%{
#include <stdio.h>

enum target
{
    TYPE = 1,
    KEYWORD,
    OPERATOR,
    COMPARISON,
    NONZERO,
    DIGIT,
    LETTER,
    OCTAL_DIGIT,
    OCTAL_CONST,
    ILLEGAL_OCTAL_CONST,
    HEX_PREFIX,
    HEX_DIGIT,
    HEX_CONST,
    ILLEGAL_HEX_CONST,
    NONDIGIT,
    ID,
    DEC_CONST,
    COMMENT1,
    COMMENT2,
    UNEXPECTED,
    LPARENT,
    RPARENT,
    LBRACKET,
    RBRACKET,
    LBRACE,
    RBRACE,
    SEMICN,
    COMMA,
    AND,
    OR
};
%}

TYPE                int|void
KEYWORD             if|else|while|break|continue|return
OPERATOR            "+"|"-"|"!"|"*"|"%"|"/"|"="
COMPARISON          "=="|"!="|">"|"<"|">="|"<="
NONZERO             [1-9]
DIGIT               [0-9]
LETTER              [A-Za-z]
OCTAL_DIGIT         [0-7]
OCTAL_CONST         0{OCTAL_DIGIT}*
ILLEGAL_OCTAL_CONST 0[0-9a-wy-zA-WY-Z]({LETTER}|{DIGIT})*
HEX_PREFIX          0x|0X
HEX_DIGIT           [0-9a-fA-F]
HEX_CONST           {HEX_PREFIX}{HEX_DIGIT}+
ILLEGAL_HEX_CONST   {HEX_PREFIX}({LETTER}|{DIGIT})*
NONDIGIT            {LETTER}|"_"
ID                  {NONDIGIT}({DIGIT}|{NONDIGIT})*
DEC_CONST           {NONZERO}{DIGIT}*  
COMMENT1            "/*"[^*]*"*"+([^*/][^*]*"*"+)*"/"
COMMENT2            "//".*                                                                                

%%


{TYPE}                  { printf("TYPE\t\t%s\n",yytext);return TYPE; }
{OCTAL_CONST}           { printf("OCTAL_CONST\t");return OCTAL_CONST; }
{ILLEGAL_OCTAL_CONST}   { return ILLEGAL_OCTAL_CONST; }
{HEX_CONST}             { printf("HEX_CONST\t");return HEX_CONST; }
{ILLEGAL_HEX_CONST}     { return ILLEGAL_HEX_CONST; }
{DEC_CONST}             { printf("DEC_CONST\t%s\n",yytext);return DEC_CONST; }
{KEYWORD}               { printf("KEYWORD\t\t%s\n",yytext);return KEYWORD; }
{ID}                    { printf("ID\t\t%s\n",yytext);return ID; }
{OPERATOR}              { printf("OPERATOR\t%s\n",yytext);return OPERATOR; }
{COMPARISON}            { printf("COMPARISON\t%s\n",yytext);return COMPARISON; }
"("                     { printf("LPARENT\t\t%s\n",yytext);return LPARENT; }
")"                     { printf("RPARENT\t\t%s\n",yytext);return RPARENT; }
"["                     { printf("LBRACKET\t%s\n",yytext);return LBRACKET; }
"]"                     { printf("RBRACKET\t%s\n",yytext);return RBRACKET; }
"{"                     { printf("LBRACE\t\t%s\n",yytext);return LBRACE; }
"}"                     { printf("RBRACE\t\t%s\n",yytext);return RBRACE; }
";"                     { printf("SEMICN\t\t%s\n",yytext);return SEMICN; }
","                     { printf("COMMA\t\t%s\n",yytext);return COMMA; }
"&&"                    { printf("AND\t\t%s\n",yytext);return AND; }
"||"                    { printf("OR\t\t%s\n",yytext);return OR; }
{COMMENT1}|{COMMENT2}   { }
[ \t\n]                 { }
.                       { return UNEXPECTED; }

%%


int main(){
    int op;
    while (op = yylex()){
        if (op == UNEXPECTED)
            printf("Error type A at Line %d: Invalid character \"%s\"\n", yylineno, yytext);
        else if (op == OCTAL_CONST){
            int ans = 0;
            for (int i = 1; i < yyleng; i++)
                ans = ans * 8 + (yytext[i] - '0');
            printf("%d\n", ans);
        }
        else if (op == HEX_CONST){
            int ans = 0;
            for (int i = 2; i < yyleng; i++){
                if (yytext[i] <= '9' && yytext[i] >= '0')
                    ans = ans * 16 + (yytext[i] - '0');
                else{
                    switch (yytext[i]){
                    case 'a':
                    case 'A':
                        ans = ans * 16 + 10;
                        break;
                    case 'b':
                    case 'B':
                        ans = ans * 16 + 11;
                        break;
                    case 'c':
                    case 'C':
                        ans = ans * 16 + 12;
                        break;
                    case 'd':
                    case 'D':
                        ans = ans * 16 + 13;
                        break;
                    case 'e':
                    case 'E':
                        ans = ans * 16 + 14;
                        break;
                    case 'f':
                    case 'F':
                        ans = ans * 16 + 15;
                        break;
                    }
                }
            }
            printf("%d\n", ans);
        }
        else if (op == ILLEGAL_OCTAL_CONST)
            printf("Error type B at line %d: Illegal octal number \'%s\'\n", yylineno, yytext);
        else if (op == ILLEGAL_HEX_CONST)
            printf("Error type B at line %d: Illegal  hexadecimal number \'%s\'\n", yylineno, yytext);
    }
}
