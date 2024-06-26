#include "ast.h"

void CompUnitAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void DeclDefAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void DefAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void DeclAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void InitValAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void FuncDefAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}


void FuncFParamAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}


void BlockAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void StmtAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void ReturnStmtAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void SelectStmtAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void IterationStmtAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void AddExpAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void MulExpAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void UnaryExpAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void PrimaryExpAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void NumberAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void CallAST::accept(Visitor& visitor) {
    visitor.visit(*this);

}

void LValAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void RelExpAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void EqExpAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void LAndExpAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void LOrExpAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void BlockItemAST::accept(Visitor& visitor) {
    visitor.visit(*this);
}
