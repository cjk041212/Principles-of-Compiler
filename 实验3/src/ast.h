#ifndef TEST_AST_H
#define TEST_AST_H
#pragma once

#include <cstring>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "define.h"

using namespace std;
class BaseAST;

class CompUnitAST;
class DeclDefAST;
class DeclAST;
class DefListAST;
class DefAST;
class ArraysAST;
class InitValListAST;
class InitValAST;
class FuncDefAST;
class FuncFParamListAST;
class FuncFParamAST;
class BlockAST;
class BlockItemListAST;
class BlockItemAST;
class StmtAST;
class ReturnStmtAST;
class SelectStmtAST;
class IterationStmtAST;
class LValAST;
class PrimaryExpAST;
class NumberAST;
class UnaryExpAST;
class CallAST;
class FuncCParamListAST;
class MulExpAST;
class AddExpAST;
class RelExpAST;
class EqExpAST;
class LAndExpAST;
class LOrExpAST;

class Visitor;

extern int yylineno;
class BaseAST {
public:
    virtual void accept(Visitor &visitor) = 0;
    BaseAST(){
        line = yylineno;
    };
    virtual ~BaseAST() = default;
    int line;
};

class CompUnitAST : public BaseAST {
public:
    vector<unique_ptr<DeclDefAST>> declDefList;
    void accept(Visitor &visitor) override;

};

class DeclDefAST : public BaseAST {
public:
    unique_ptr<DeclAST> Decl = nullptr;
    unique_ptr<FuncDefAST> funcDef = nullptr;
    void accept(Visitor &visitor) override;
};

class DeclAST : public BaseAST {
public:
    TYPE bType;
    bool isConst;
    vector<unique_ptr<DefAST>> defList;
    void accept(Visitor &visitor) override;
};

class DefListAST {
public:
    vector<unique_ptr<DefAST>> list;
};

class DefAST : public BaseAST {
public:
    unique_ptr<string> id;
    vector<unique_ptr<AddExpAST>> arrays;
    unique_ptr<InitValAST> initVal;
    void accept(Visitor &visitor) override;
};

class ArraysAST {
public:
    vector<unique_ptr<AddExpAST>> list;
};

class InitValAST:public BaseAST {
public:
    unique_ptr<AddExpAST> exp;
    vector<unique_ptr<InitValAST>> initValList;
    void accept(Visitor &visitor) override;
};


class InitValListAST {
public:
    vector<unique_ptr<InitValAST>> list;
};

class FuncDefAST : public BaseAST {
public:
    TYPE funcType;
    unique_ptr<string> id;
    vector<unique_ptr<FuncFParamAST>> funcFParamList;
    unique_ptr<BlockAST> block = nullptr;
    void accept(Visitor &visitor) override;
};

class FuncFParamListAST {
public:
    vector<unique_ptr<FuncFParamAST>> list;
};

class FuncFParamAST:public BaseAST {
public:
    TYPE bType;
    unique_ptr<string> id;
    bool isArray = false; //用于区分是否是数组参数，此时一维数组和多维数组expArrays都是empty
    vector<unique_ptr<AddExpAST>> arrays;
    void accept(Visitor &visitor) override;
};

class BlockAST : public BaseAST {
public:
    vector<unique_ptr<BlockItemAST>> blockItemList;
    void accept(Visitor &visitor) override;
};

class BlockItemListAST {
public:
    vector<unique_ptr<BlockItemAST>> list;
};

class BlockItemAST : public BaseAST {
public:
    unique_ptr<DeclAST> decl = nullptr;
    unique_ptr<StmtAST> stmt = nullptr;
    void accept(Visitor &visitor) override;
};

class StmtAST : public BaseAST {
public:
    STYPE sType;
    unique_ptr<LValAST> lVal = nullptr;
    unique_ptr<AddExpAST> exp= nullptr;
    unique_ptr<ReturnStmtAST> returnStmt = nullptr;
    unique_ptr<SelectStmtAST> selectStmt = nullptr;
    unique_ptr<IterationStmtAST> iterationStmt = nullptr;
    unique_ptr<BlockAST> block = nullptr;
    void accept(Visitor &visitor) override;
};

class ReturnStmtAST : public BaseAST {
public:
    unique_ptr<AddExpAST> exp = nullptr;
    void accept(Visitor &visitor) override;
};

class SelectStmtAST:public BaseAST {
public:
    unique_ptr<LOrExpAST> cond;
    unique_ptr<StmtAST> ifStmt, elseStmt;
    void accept(Visitor &visitor) override;
};

class IterationStmtAST:public BaseAST {
public:
    unique_ptr<LOrExpAST> cond;
    unique_ptr<StmtAST> stmt;
    void accept(Visitor &visitor) override;
};

class AddExpAST : public BaseAST {
public:
    unique_ptr<AddExpAST> addExp;
    unique_ptr<MulExpAST> mulExp;
    AOP op;
    void accept(Visitor &visitor) override;
};

class MulExpAST :public BaseAST {
public:
    unique_ptr<UnaryExpAST> unaryExp;
    unique_ptr<MulExpAST> mulExp;
    MOP op;
    void accept(Visitor &visitor) override;
};

class UnaryExpAST :public BaseAST {
public:
    unique_ptr<PrimaryExpAST> primaryExp;
    unique_ptr<CallAST> call;
    unique_ptr<UnaryExpAST> unaryExp;
    UOP op;
    void accept(Visitor &visitor) override;
};

class PrimaryExpAST:public BaseAST {
public:
    unique_ptr<AddExpAST> exp;
    unique_ptr<LValAST> lval;
    unique_ptr<NumberAST> number;
    void accept(Visitor &visitor) override;
};

class NumberAST:public BaseAST {
public:
    bool isInt;
    union {
        int intval;
        float floatval;
    };
    void accept(Visitor &visitor) override;
};

class LValAST:public BaseAST {
public:
    unique_ptr<string> id;
    vector<unique_ptr<AddExpAST>> arrays;
    void accept(Visitor &visitor) override;
};

class CallAST:public BaseAST {
public:
    unique_ptr<string> id;
    vector<unique_ptr<AddExpAST>> funcCParamList;
    void accept(Visitor &visitor) override;
};

class FuncCParamListAST {
public:
    vector<unique_ptr<AddExpAST>> list;
};

class RelExpAST:public BaseAST {
public:
    unique_ptr<AddExpAST> addExp;
    unique_ptr<RelExpAST> relExp;
    ROP op;
    void accept(Visitor &visitor) override;
};

class EqExpAST:public BaseAST {
public:
    unique_ptr<RelExpAST> relExp;
    unique_ptr<EqExpAST> eqExp;
    EOP op;
    void accept(Visitor &visitor) override;
};

class LAndExpAST : public BaseAST {
public:
    // lAndExp不为空则说明有and符号，or类似
    unique_ptr<EqExpAST> eqExp;
    unique_ptr<LAndExpAST> lAndExp;
    void accept(Visitor &visitor) override;
};

class LOrExpAST:public BaseAST {
public:
    unique_ptr<LOrExpAST> lOrExp;
    unique_ptr<LAndExpAST> lAndExp;
    void accept(Visitor &visitor) override;
};

class Visitor {
public:
    virtual void visit(CompUnitAST& ast) = 0;
    virtual void visit(DeclDefAST& ast) = 0;
    virtual void visit(DeclAST& ast) = 0;
    virtual void visit(DefAST& ast) = 0;
    virtual void visit(InitValAST& ast) = 0;
    virtual void visit(FuncDefAST& ast) = 0;
    virtual void visit(FuncFParamAST& ast) = 0;
    virtual void visit(BlockAST& ast) = 0;
    virtual void visit(BlockItemAST& ast) = 0;
    virtual void visit(StmtAST& ast) = 0;
    virtual void visit(ReturnStmtAST& ast) = 0;
    virtual void visit(SelectStmtAST& ast) = 0;
    virtual void visit(IterationStmtAST& ast) = 0;
    virtual void visit(AddExpAST& ast) = 0;
    virtual void visit(MulExpAST& ast) = 0;
    virtual void visit(UnaryExpAST& ast) = 0;
    virtual void visit(PrimaryExpAST& ast) = 0;
    virtual void visit(LValAST& ast) = 0;
    virtual void visit(NumberAST& ast) = 0;
    virtual void visit(CallAST& ast) = 0;
    virtual void visit(RelExpAST& ast) = 0;
    virtual void visit(EqExpAST& ast) = 0;
    virtual void visit(LAndExpAST& ast) = 0;
    virtual void visit(LOrExpAST& ast) = 0;
};

#endif //TEST_AST_H