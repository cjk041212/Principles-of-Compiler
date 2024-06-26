#ifndef DEF_H
#define DEF_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "stdarg.h"
#include "parser.h" //��bison����parser.y����
#define MAXLENGTH   200
#define DX 3*sizeof(int)          /*���¼������Ϣ��Ҫ�ĵ�Ԫ�����������ʵ��ϵͳ����*/
//�����﷨��������͡�����ַ������͵ȶ�������ο���ʵ��ʱһ��Ҫ�����Լ������������
extern int LEV;      //���
#define BLOCK -2147483647

typedef enum node_type {
    CompUnit,
    ConstDecl,
    VarDecl,
    FuncDef,
    ConstDef,
    ConstInitVal,
    VarDef,
    InitVal,
    FuncFParam,
    ExpArray,
    Exp,
    Block,
    BlockItem,
    Stmt,
    LVal,
    PrimaryExp,
    UnaryExp,
    LOrExp,
    FuncRParams,
    MulExp,
    RelExp,
    EqExp,
    LAndExp,
    Cond,
    ConstExp,
    ConstExpArray,
    BlankStmt,   //�����
    ExpStmt,     // ���ʽ���
    AssignStmt,  // ��ֵ���
    IfStmt,      // If���
    IfElseStmt,  // If-Else���
    WhileStmt,   //  while���
    BreakStmt,   //  break���
    ContinueStmt, // continue���
    BlankReturnStmt, //��������ֵ��return���
    AddExp,
    ReturnStmt,   // ������ֵ��return���
    NonType,
    Float,
    Int,
    InitVals,
    Void,
    Plus,
    Minus,
    Root
} node_type;

// AST�ڵ�(��������ӽڵ㣺lef,mid,right,��ֻ�����ڵ�ʱ����midΪnull):
typedef struct ASTNode {
    node_type type;
    struct ASTNode* left;
    struct ASTNode* mid;
    struct ASTNode* right;
    int int_val;
    float float_val;
    char* symbol;
    node_type d_type;
}ASTNode;

ASTNode* new_node(node_type type, ASTNode* left, ASTNode* mid, ASTNode* right, int int_val, float float_val, char* symbol, node_type d_type);

void display(ASTNode* T);
int getBranchNum(ASTNode* T);
void printVarType(node_type type);
void gapProcess();
void nextDisplay(ASTNode* T);
void nextDisplayReverse(ASTNode* T);

void print_root(ASTNode* T);
void print_comp_unit(ASTNode* T);
void print_const_decl(ASTNode* T);
void print_const_def(ASTNode* T);
void print_const_exp_array(ASTNode* T);
void print_const_init_val(ASTNode* T);
void print_const_exp(ASTNode* T);
void print_var_decl(ASTNode* T);
void print_var_def(ASTNode* T);
void print_init_val(ASTNode* T);
void print_init_vals(ASTNode* T);
void print_func_def(ASTNode* T);
void print_func_f_param(ASTNode* T);
void print_block(ASTNode* T);
void print_block_item(ASTNode* T);
void print_stmt(ASTNode* T);
void print_exp(ASTNode* T);
void print_add_exp(ASTNode* T);
void print_mul_exp(ASTNode* T);
void print_unary_exp(ASTNode* T);
void print_func_r_params(ASTNode* T);
void print_primary_exp(ASTNode* T);
void print_lv_al(ASTNode* T);
void print_cond(ASTNode* T);
void print_l_and_exp(ASTNode* T);
void print_eq_exp(ASTNode* T);
void print_rel_exp(ASTNode* T);
void print_exp_array(ASTNode* T);
void print_unknown(ASTNode* T);

#endif