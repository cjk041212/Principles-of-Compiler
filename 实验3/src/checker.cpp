#include "checker.h"

/* 静态语义分析
 1. Redefined Variable 变量重复定义/函数形参重复定义
 2. Redefined Function 函数重复定义
 3. Use Undefined Variable 使用未定义变量
 4. Use Undefined Function 使用未定义函数
 5. Can not Match Function Parameters 函数参数/类型不匹配
 6. Func return type not match 函数返回值类型不匹配,
 例如函数返回类型void/float时，函数内出现带返回值为int的return语句
 7. Array index not int 数组下标不是整数
 8. Break not in loop break语句不在循环中
 9. Continue not in loop continue语句不在循环中
 10. Visit non-array variable in the form of subscript variables
 对非数组变量采用下标变量的形式访问
*/

/**
 * @brief 访问CompUnitAST节点检测语义
 *
 * @description:
 * 访问CompUnitAST节点检测语义，注意创建新的表项，遍历所有的变量及函数定义
 * @param {CompUnitAST&} ast - 单元类，也是语法树的根节点
 */
void Checker::visit(CompUnitAST& ast) {
    //创建新的表项
    make_new_table();
    for (auto& decl : ast.declDefList) {
        decl->accept(*this);
    }
}

/**
 * @brief 访问DeclDefAST节点检测语义
 *
 * @description: 访问当前的变量声明节点或函数定义节点
 * @param {DeclDefAST&} ast - 声明和函数定义类
 */
void Checker::visit(DeclDefAST& ast) {
    if (ast.Decl) {
        ast.Decl->accept(*this);
    }
    if (ast.funcDef) {
        ast.funcDef->accept(*this);
    }
}

/**
 * @brief 访问DeclAST节点检测语义
 *
 * @description:
 * 访问变量声明，并将所有变量插入到符号表中，注意变量不能重复分配。
 * @param {DeclDefAST&} ast - 声明和函数定义类
 */
void Checker::visit(DeclAST& ast) {
    for (auto& def : ast.defList) {
        def->accept(*this);
    }
    // 将定义的变量插入符号表
    if (!InsertVar(ast)) {
        // TODO 变量重复定义
        exit(int(ErrorType::VarDuplicated));
    }
}

/**
 * @brief 访问DefAST节点检测语义
 *
 * @description: 访问定义AST节点并进行语义检查
 *
 * @param {DefAST&} ast - 定义AST节点
 */
void Checker::visit(DefAST& ast) {
    if (ast.initVal) {
        ast.initVal->accept(*this);
    }
}

/**
 * @brief 访问InitValAST节点检测语义
 *
 * @description: 访问初始化值AST节点并进行语义检查
 *
 * @param {InitValAST&} ast - 初始化值AST节点
 */

void Checker::visit(InitValAST& ast) {
    if (ast.exp) {
        ast.exp->accept(*this);
    }
    else {
        for (auto& initVal : ast.initValList) {
            initVal->accept(*this);
        }
    }
}

/**
 * @brief 访问FuncFParamAST节点检测语义
 *
 * @description: 访问函数形参AST节点并进行语义检查
 *
 * @param {FuncFParamAST&} ast - 函数形参AST节点
 */

void Checker::visit(FuncFParamAST& ast) {
    for (auto& exp : ast.arrays) {
        if (exp) {
            exp->accept(*this);
        }
    }
}

/**
 *  @brief 访问ReturnStmtAST节点检测语义
 *
 *  @description:
 * 遍历ReturnStmtAST节点，并通过符号表table检测函数返回类型是否与return语句的返回值类型相同。
 *
 *  @param {ReturnStmtAST&} ast - 返回语句的AST节点
 **/
void Checker::visit(ReturnStmtAST& ast) {
    if (ast.exp) {
        ast.exp->accept(*this);
    }
    else {
        this->current_type.type = TYPE::TYPE_VOID;
    }

    auto entry = find_func();
    // TODO 函数返回类型不匹配
    if (entry->type != this->current_type.type) {
        err.error(ErrorType::FuncReturnTypeNotMatch, " ");
        exit(int(ErrorType::FuncReturnTypeNotMatch));
    }
}

/**
 *  @brief 访问FuncDefAST节点检测语义
 *
 *  @description:
 *将函数插入到符号表中，注意函数不能重复定义，同时进入新函数作用域
 *
 *  @param {FuncDefAST&} ast - 函数定义AST节点
 **/
void Checker::visit(FuncDefAST& ast) {
    // 将函数插入符号表
    // TODO 函数重复定义
    if (!InsertFunc(ast)) {
        exit(int(ErrorType::FuncDuplicated));
    }
    start_of_new_func = true;
    ast.block->accept(*this);
}

/**
 * @brief 访问BlockAST节点进行语义检查
 *
 * @description:
 * 对于函数体块，检查函数体内的语句和变量定义，包括语义分析和作用域控制。
 * @param {BlockAST&} ast - 函数体块类
 */
void Checker::visit(BlockAST& ast) {
    //一个新的函数在插入时就已经建了新的符号表，这里不用重复建
    if (start_of_new_func)
        start_of_new_func = false;
    //对非函数定义的语句块添加新的符号表
    else
        make_new_table();

    for (auto& item : ast.blockItemList) {
        item->accept(*this);
    }

    //语句块作用域结束，删除之前添加的符号表
    delete_table();
}

/**
 * @brief 访问BlockItemAST节点进行语义检查
 *
 * @description: 对函数体块中的单个语句或变量定义进行语义分析。
 * @param {BlockItemAST&} ast - 函数体块内的单个语句或变量定义
 */
void Checker::visit(BlockItemAST& ast) {
    if (ast.stmt) {
        ast.stmt->accept(*this);
    }
    if (ast.decl) {
        ast.decl->accept(*this);
    }
}

/**
 * @brief 访问StmtAST节点进行语义检查
 *
 * @description:
 * 对语句进行语义分析，包括处理返回语句、选择语句、循环语句和表达式等。注意break和continue语句在循环中。
 * @param {StmtAST&} ast - 语句类
 */
void Checker::visit(StmtAST& ast) {
    if (ast.returnStmt) {
        ast.returnStmt->accept(*this);
    }
    if (ast.selectStmt) {
        ast.selectStmt->accept(*this);
    }
    if (ast.block) {
        ast.block->accept(*this);
    }
    if (ast.lVal) {
        ast.lVal->accept(*this);
    }
    if (ast.exp) {
        ast.exp->accept(*this);
    }

    if (ast.sType == STYPE::BRE) { // 当前节点为Break语句类型
        // TODO 检查该break语句是否在循环体内,若不是应报错
        if (!this->in_loop) {
            err.error(ErrorType::BreakNotInLoop," ");
            exit(int(ErrorType::BreakNotInLoop));
        }
    }
    else if (ast.sType == STYPE::CONT) { // 当前节点为Continue语句类型
        // TODO 检查该continuek语句是否在循环体内,若不是应报错
        if (!this->in_loop) {
            err.error(ErrorType::ContinueNotInLoop, " ");
            exit(int(ErrorType::ContinueNotInLoop));
        }
    }
}

/**
 * @brief 访问SelectStmtAST节点进行语义检查
 *
 * @description:
 * 对选择语句（if-else语句）进行语义分析，包括处理条件表达式、if分支和else分支。
 * @param {SelectStmtAST&} ast - 选择语句类
 */
void Checker::visit(SelectStmtAST& ast) {
    if (ast.elseStmt) {
        ast.elseStmt->accept(*this);
    }
    if (ast.ifStmt) {
        ast.ifStmt->accept(*this);
    }
    if (ast.cond) {
        ast.cond->accept(*this);
    }
}

/**
 * @brief 访问IterationStmtAST节点进行语义检查
 *
 * @description: 对循环语句进行语义分析，包括处理循环条件和循环体。
 * @param {IterationStmtAST&} ast - 循环语句类
 */
void Checker::visit(IterationStmtAST& ast) {
    this->in_loop = true;
    if (ast.cond) {
        ast.cond->accept(*this);
    }
    if (ast.stmt) {
        ast.stmt->accept(*this);
    }
    this->in_loop = false;
}

/**
 * @brief 访问AddExpAST节点进行语义检查
 *
 * @description: 对加法表达式进行语义分析，处理加法运算。
 * @param {AddExpAST&} ast - 加法表达式类
 */
void Checker::visit(AddExpAST& ast) {
    if (ast.addExp) {
        ast.addExp->accept(*this);
    }
    if (ast.mulExp) {
        ast.mulExp->accept(*this);
    }
}

/**
 * @brief 访问MulExpAST节点进行语义检查
 *
 * @description: 对乘法表达式进行语义分析，处理乘法运算。
 * @param {MulExpAST&} ast - 乘法表达式类
 */
void Checker::visit(MulExpAST& ast) {
    if (ast.mulExp) {
        ast.mulExp->accept(*this);
    }
    if (ast.unaryExp) {
        ast.unaryExp->accept(*this);
    }
}

/**
 * @brief 访问UnaryExpAST节点进行语义检查
 *
 * @description:
 * 对一元表达式进行语义分析，包括处理一元运算符、基本表达式和函数调用。
 * @param {UnaryExpAST&} ast - 一元表达式类
 */
void Checker::visit(UnaryExpAST& ast) {
    if (ast.primaryExp) {
        ast.primaryExp->accept(*this);
    }
    if (ast.unaryExp) {
        ast.unaryExp->accept(*this);
    }
    if (ast.call) {
        ast.call->accept(*this);
    }
}

/**
 * @brief 访问PrimaryExpAST节点进行语义检查
 *
 * @description: 对基本表达式进行语义分析，包括处理表达式、左值和常数。
 * @param {PrimaryExpAST&} ast - 基本表达式类
 */
void Checker::visit(PrimaryExpAST& ast) {
    if (ast.exp) {
        ast.exp->accept(*this);
    }
    if (ast.lval) {
        ast.lval->accept(*this);
    }
    if (ast.number) {
        ast.number->accept(*this);
    }
}

/**
 * @brief 访问LValAST节点进行语义检查
 *
 * @description:
 * 对左值表达式进行语义分析，包括数组下标检查、变量查找和访问控制。
 * @param {LValAST&} ast - 左值表达式类
 */
void Checker::visit(LValAST& ast) {
    for (auto& exp : ast.arrays) {
        if (exp) {
            exp->accept(*this);
        }

        // TODO ERROR
        // 左值数组下标不是整数
        // 例如c[0.1] = 1;
        if (!Expr_int) {
            err.error(ErrorType::ArrayIndexNotInt, *ast.id);
            exit(int(ErrorType::ArrayIndexNotInt));
        }
    }

    auto str = ast.id.get();
    //在符号表中查找对应变量
    Entry* entry = Lookup(*str);
    if (entry == nullptr) {
        // TODO ERROR
        // 使用未定义变量
        err.error(ErrorType::VarUnknown, *ast.id);
        exit(int(ErrorType::VarUnknown));
    }

    // TODO ERROR
    // 对非数组变量采用下标变量的形式访问
    // 例如 int c; c[10][10] = 10;
    if (!entry->is_array && !ast.arrays.empty()) {
        err.error(ErrorType::VisitVariableError, *ast.id);
        exit(int(ErrorType::VisitVariableError));
    }

    this->current_type.type = entry->type;
    this->Expr_int = (entry->type == TYPE::TYPE_INT);
}

void Checker::visit(NumberAST& ast) {
    this->Expr_int = ast.isInt;
    this->current_type.type = ast.isInt ? TYPE::TYPE_INT : TYPE::TYPE_FLOAT;
}

/**
 * @brief 访问CallAST节点进行语义检查
 *
 * @description: 对函数调用进行语义分析，包括检查参数匹配和特殊函数处理。
 * @param {CallAST&} ast - 函数调用类
 */
void Checker::visit(CallAST& ast) {
    //特殊函数不做处理
    if (!ast.id->compare("getint") || !ast.id->compare("getfloat") ||
        !ast.id->compare("getch") || !ast.id->compare("getarray") ||
        !ast.id->compare("get_float_array") || !ast.id->compare("putint") ||
        !ast.id->compare("putfloat") || !ast.id->compare("putch") ||
        !ast.id->compare("putarray") || !ast.id->compare("put_float_array")) {
        return;
    }

    // 在符号表中查找对应函数
    Entry* entry = Lookup(*ast.id);

    // TODO 函数未定义
    // TODO 参数长度不匹配
    // TODO 参数类型不匹配

    if (entry == nullptr) {
        // TODO ERROR
        // 函数未定义
        err.error(ErrorType::FuncUnknown, *ast.id);
        exit(int(ErrorType::FuncUnknown));
    }
    else {
        //参数长度不匹配
        if (entry->func_params.size() != ast.funcCParamList.size()) {
            // TODO ERROR
            // 函数参数/类型不匹配
            err.error(ErrorType::FuncParamsNotMatch, *ast.id);
            exit(int(ErrorType::FuncParamsNotMatch));
        }
        else {
            //遍历实参与形参
            int i = 0;
            for (auto& exp : ast.funcCParamList) {
                exp->accept(*this);
                if (this->current_type.type != entry->func_params[i].type) {
                    err.error(ErrorType::FuncParamsNotMatch, *ast.id);
                    exit(int(ErrorType::FuncParamsNotMatch));
                }
                else {
                    i++;
                }
            }
        }
        this->current_type.type = entry->type;
        this->Expr_int = (entry->type == TYPE::TYPE_INT);
    }
}

/**
 * @brief 访问RelExpAST节点进行语义检查
 *
 * @description: 对关系表达式进行语义分析，确定表达式的类型。
 * @param {RelExpAST&} ast - 关系表达式类
 */
void Checker::visit(RelExpAST& ast) {
    if (ast.relExp) {
        ast.relExp->accept(*this);
    }
    if (ast.addExp) {
        ast.addExp->accept(*this);
    }
    this->Expr_int = false;
    this->current_type.type = TYPE::TYPE_BOOL;
}

/**
 * @brief 访问EqExpAST节点进行语义检查
 *
 * @description: 对等式表达式进行语义分析，确定表达式的类型。
 * @param {EqExpAST&} ast - 等式表达式类
 */
void Checker::visit(EqExpAST& ast) {
    if (ast.eqExp) {
        ast.eqExp->accept(*this);
    }
    if (ast.relExp) {
        ast.relExp->accept(*this);
    }
    this->Expr_int = false;
    this->current_type.type = TYPE::TYPE_BOOL;
}

/**
 * @brief 访问LAndExpAST节点进行语义检查
 *
 * @description: 对逻辑与表达式进行语义分析，确定表达式的类型。
 * @param {LAndExpAST&} ast - 逻辑与表达式类
 */
void Checker::visit(LAndExpAST& ast) {
    if (ast.lAndExp) {
        ast.lAndExp->accept(*this);
    }
    if (ast.eqExp) {
        ast.eqExp->accept(*this);
    }
}

/**
 * @brief 访问LOrExpAST节点进行语义检查
 *
 * @description: 对逻辑或表达式进行语义分析，确定表达式的类型。
 * @param {LOrExpAST&} ast - 逻辑或表达式类
 */
void Checker::visit(LOrExpAST& ast) {
    if (ast.lOrExp) {
        ast.lOrExp->accept(*this);
    }
    if (ast.lAndExp) {
        ast.lAndExp->accept(*this);
    }
}
