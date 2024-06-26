#include "printer.h"

// ref: https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
template <typename... Args>
std::string strfmt(const std::string& format, Args... args) {
    int size_s = std::snprintf(nullptr, 0, format.c_str(), args...) + 1;  // Extra space for '\0'
    if (size_s <= 0) {
        throw std::runtime_error("Error during formatting.");
    }
    auto size = static_cast<size_t>(size_s);
    std::unique_ptr<char[]> buf(new char[size]);
    std::snprintf(buf.get(), size, format.c_str(), args...);
    return std::string(buf.get(), buf.get() + size - 1);  // We don't want the '\0' inside
}

std::string Printer::visit(CompUnitAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "CompUnit:\n";
    depth += 2;
    for (auto& i : ast.declDefList) {
        ans += visit(*i);
    }
    depth -= 2;
    return ans;
}

std::string Printer::visit(DeclDefAST& ast) {
    std::string ans = "";
    if (ast.Decl != nullptr) {
        ans += visit(*ast.Decl);
    }
    else {
        ans += visit(*ast.funcDef);
    }
    return ans;
}

std::string Printer::visit(DeclAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "Decl:\n";
    depth += 2;
    if (ast.isConst) {
        ans += strfmt("%*s", depth, "");
        ans += "const\n";
    }
    ans += strfmt("%*s", depth, "");
    if (ast.bType == TYPE_INT) ans += "BType:int\n";
    else ans += "BType:float\n";
    for (auto& def : ast.defList) {
        ans += visit(*def);
    }
    depth -= 2;
    return ans;
}

std::string Printer::visit(DefAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "Def:\n";
    depth += 2;
    ans += strfmt("%*s", depth, "");
    ans += "id:" + *(ast.id) + "\n";
    if (!ast.arrays.empty()) {
        ans += strfmt("%*s", depth, "");
        ans += "Arrays:\n";
        depth += 2;
        for (auto& i : ast.arrays) {
            ans += visit(*i);
        }
        depth -= 2;
    }
    if (ast.initVal != nullptr) ans += visit(*ast.initVal);
    depth -= 2;
    return ans;
}

std::string Printer::visit(InitValAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "InitValAST:";
    depth += 2;
    if (ast.exp != nullptr) {
        ans += "\n";
        ans += visit(*ast.exp);
    }
    else if (!ast.initValList.empty()) {
        ans += "\n";
        ans += strfmt("%*s", depth, "");
        ans += "InitValList:\n";
        depth += 2;
        for (auto& initVal : ast.initValList) {
            ans += visit(*initVal);
        }
        depth -= 2;
    }
    else {
        ans += "{}\n";
    }
    depth -= 2;
    return ans;
}

std::string Printer::visit(FuncDefAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "FuncDef:\n";
    depth += 2;
    ans += strfmt("%*s", depth, "");
    if (ast.funcType == TYPE_VOID) ans += "funcType:void\n";
    else if (ast.funcType == TYPE_INT) ans += "funcType:int\n";
    else ans += "funcType:float\n";
    ans += strfmt("%*s", depth, "");
    ans += "id:" + *ast.id + "\n";
    if (!ast.funcFParamList.empty()) {
        ans += strfmt("%*s", depth, "");
        ans += "FuncFParamList:\n";
        depth += 2;
        for (auto& i : ast.funcFParamList) {
            ans += visit(*i);
        }
        depth -= 2;
    }
    ans += visit(*ast.block);
    depth -= 2;
    return ans;
}

std::string Printer::visit(FuncFParamAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "FuncFParam:\n";
    depth += 2;
    ans += strfmt("%*s", depth, "");
    if (ast.bType == TYPE_INT) ans += "BType:int\n";
    else ans += "BType:float\n";
    ans += strfmt("%*s", depth, "");
    ans += "id:" + *ast.id + "\n";
    if (ast.isArray) {
        ans += strfmt("%*s", depth, "");
        ans += "Array:[]\n";
    }
    if (!ast.arrays.empty()) {
        ans += strfmt("%*s", depth, "");
        ans += "Arrays:\n";
        depth += 2;
        for (auto& i : ast.arrays) {
            ans += visit(*i);
        }
        depth -= 2;
    }
    depth -= 2;
    return ans;
}

std::string Printer::visit(BlockAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "Block:\n";
    depth += 2;
    if (!ast.blockItemList.empty()) {
        ans += strfmt("%*s", depth, "");
        ans += "BlockItemList:\n";
        depth += 2;
        for (auto& i : ast.blockItemList) {
            ans += visit(*i);
        }
        depth -= 2;
    }
    depth -= 2;
    return ans;
}

std::string Printer::visit(BlockItemAST& ast) {
    std::string ans = "";
    if (ast.decl != nullptr) {
        ans += visit(*ast.decl);
    }
    else {
        ans += visit(*ast.stmt);
    }
    return ans;
}

std::string Printer::visit(StmtAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "Stmt:";
    switch (ast.sType) {
    case SEMI:
        ans += "semicolon\n";
        break;
    case ASS:
        ans += "\n";
        depth += 2;
        ans += visit(*ast.lVal);
        ans += visit(*ast.exp);
        depth -= 2;
        break;
    case EXP:
        ans += "\n";
        depth += 2;
        ans += visit(*ast.exp);
        depth -= 2;
        break;
    case CONT:
        ans += "continue\n";
        break;
    case BRE:
        ans += "break\n";
        break;
    case RET:
        ans += "\n";
        depth += 2;
        ans += visit(*ast.returnStmt);
        depth -= 2;
        break;
    case BLK:
        ans += "\n";
        depth += 2;
        ans += visit(*ast.block);
        depth -= 2;
        break;
    case SEL:
        ans += "\n";
        depth += 2;
        ans += visit(*ast.selectStmt);
        depth -= 2;
        break;
    case ITER:
        ans += "\n";
        depth += 2;
        ans += visit(*ast.iterationStmt);
        depth -= 2;
        break;
    }
    return ans;
}

std::string Printer::visit(ReturnStmtAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "return:";
    if (ast.exp == nullptr) ans += "void\n";
    else {
        ans += "\n";
        depth += 2;
        ans += visit(*ast.exp);
        depth -= 2;
    }
    return ans;
}

std::string Printer::visit(SelectStmtAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "SelectStmt:\n";
    depth += 2;
    ans += visit(*ast.cond);
    ans += visit(*ast.ifStmt);
    if (ast.elseStmt != nullptr) ans += visit(*ast.elseStmt);
    depth -= 2;
    return ans;
}

std::string Printer::visit(IterationStmtAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "IterationStmt:\n";
    depth += 2;
    ans += visit(*ast.cond);
    ans += visit(*ast.stmt);
    depth -= 2;
    return ans;
}

std::string Printer::visit(AddExpAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "AddExp:\n";
    depth += 2;
    if (ast.addExp != nullptr) {
        ans += visit(*ast.addExp);
        ans += strfmt("%*s", depth, "");
        ans += "AOP:";
        if (ast.op == AOP_ADD) ans += "+\n";
        else ans += "-\n";
    }
    ans += visit(*ast.mulExp);
    depth -= 2;
    return ans;
}

std::string Printer::visit(MulExpAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "MulExp:\n";
    depth += 2;
    if (ast.mulExp != nullptr) {
        ans += visit(*ast.mulExp);
        ans += strfmt("%*s", depth, "");
        ans += "MOP:";
        if (ast.op == MOP_MUL) ans += "*\n";
        else if (ast.op == MOP_DIV) ans += "/\n";
        else ans += "%\n";
    }
    ans += visit(*ast.unaryExp);
    depth -= 2;
    return ans;
}

std::string Printer::visit(UnaryExpAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "UnaryExp:\n";
    depth += 2;
    if (ast.primaryExp != nullptr) {
        ans += visit(*ast.primaryExp);
    }
    else if (ast.call != nullptr) {
        ans += visit(*ast.call);
    }
    else {
        ans += strfmt("%*s", depth, "");
        ans += "UnaryOp:";
        if (ast.op == UOP_ADD) ans += "+\n";
        if (ast.op == UOP_MINUS) ans += "-\n";
        if (ast.op == UOP_NOT) ans += "!\n";
        ans += visit(*ast.unaryExp);
    }
    depth -= 2;
    return ans;
}

std::string Printer::visit(PrimaryExpAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "PrimaryExp:\n";
    depth += 2;
    if (ast.exp != nullptr) {
        ans += visit(*ast.exp);
    }
    else if (ast.lval != nullptr) {
        ans += visit(*ast.lval);
    }
    else {
        ans += visit(*ast.number);
    }
    depth -= 2;
    return ans;
}

std::string Printer::visit(CallAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "Call:\n";
    depth += 2;
    ans += strfmt("%*s", depth, "");
    ans += "id:" + (*ast.id) + "\n";
    if (!ast.funcCParamList.empty()) {
        ans += strfmt("%*s", depth, "");
        ans += "FuncCParamList:" + std::to_string(ast.funcCParamList.size()) + "\n";
        depth += 2;
        for (auto& i : ast.funcCParamList) {
            ans += visit(*i);
        }
        depth -= 2;
    }
    depth -= 2;
    return ans;
}

std::string Printer::visit(LValAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "LVal:\n";
    depth += 2;
    ans += strfmt("%*s", depth, "");
    ans += "id:" + (*ast.id) + "\n";
    if (!ast.arrays.empty()) {
        ans += "Arrays:\n";
        depth += 2;
        for (auto& i : ast.arrays) {
            ans += visit(*i);
        }
        depth -= 2;
    }
    depth -= 2;
    return ans;
}

std::string Printer::visit(NumberAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "number:";
    if (ast.isInt) ans += std::to_string(ast.intval) + "\n";
    else ans += std::to_string(ast.floatval) + "\n";
    return ans;
}

std::string Printer::visit(RelExpAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "RelExp:\n";
    depth += 2;
    if (ast.relExp != nullptr) {
        ans += visit(*ast.relExp);
        ans += strfmt("%*s", depth, "");
        ans += "RelOP:";
        if (ast.op == ROP_GTE) ans += ">=\n";
        else if (ast.op == ROP_LTE) ans += "<=\n";
        else if (ast.op == ROP_GT) ans += ">\n";
        else if (ast.op == ROP_LT) ans += "<\n";
    }
    ans += visit(*ast.addExp);
    depth -= 2;
    return ans;
}

std::string Printer::visit(EqExpAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "EqExp:\n";
    depth += 2;
    if (ast.eqExp != nullptr) {
        ans += visit(*ast.eqExp);
        ans += strfmt("%*s", depth, "");
        ans += "EqOP:";
        if (ast.op == EOP_EQ) ans += "==\n";
        else ans += "!=\n";
    }
    ans += visit(*ast.relExp);
    depth -= 2;
    return ans;
}

std::string Printer::visit(LAndExpAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "LAndExp:\n";
    depth += 2;
    if (ast.lAndExp != nullptr) {
        ans += visit(*ast.lAndExp);
        ans += strfmt("%*s", depth, "");
        ans += "AND_OP:&&";
    }
    ans += visit(*ast.eqExp);
    depth -= 2;
    return ans;
}

std::string Printer::visit(LOrExpAST& ast) {
    std::string ans = strfmt("%*s", depth, "");
    ans += "LOrExp:\n";
    depth += 2;
    if (ast.lOrExp != nullptr) {
        ans += visit(*ast.lOrExp);
        ans += strfmt("%*s", depth, "");
        ans += "OR_OP:||";
    }
    ans += visit(*ast.lAndExp);
    depth -= 2;
    return ans;
}

