#ifndef TEST_PRINTER_H
#define TEST_PRINTER_H

#include "ast.h"

class Printer {
public:
    int depth = 0;
    std::string visit(CompUnitAST& ast);
    std::string visit(DeclDefAST& ast);
    std::string visit(DeclAST& ast);
    std::string visit(DefAST& ast);
    std::string visit(InitValAST& ast);
    std::string visit(FuncDefAST& ast);
    std::string visit(FuncFParamAST& ast);
    std::string visit(BlockAST& ast);
    std::string visit(BlockItemAST& ast);
    std::string visit(StmtAST& ast);
    std::string visit(ReturnStmtAST& ast);
    std::string visit(SelectStmtAST& ast);
    std::string visit(IterationStmtAST& ast);
    std::string visit(AddExpAST& ast);
    std::string visit(LValAST& ast);
    std::string visit(MulExpAST& ast);
    std::string visit(UnaryExpAST& ast);
    std::string visit(PrimaryExpAST& ast);
    std::string visit(CallAST& ast);
    std::string visit(NumberAST& ast);
    std::string visit(RelExpAST& ast);
    std::string visit(EqExpAST& ast);
    std::string visit(LAndExpAST& ast);
    std::string visit(LOrExpAST& ast);
};



#endif //TEST_PRINTER_H
