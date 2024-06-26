#ifndef CARROTCOMPILER_CHECKER_H
#define CARROTCOMPILER_CHECKER_H

#include "ast.h"
#include "define.h"
#include "errorReporter.h"
#include <list>
#include <map>
#include <vector>

/**
 * @brief 语义分析器类，用于检查源代码中的语法和语义错误
 */
class Checker : public Visitor {
public:
  explicit Checker(ErrorReporter &e) : err(e) {}
  void visit(CompUnitAST &ast) override;
  void visit(DeclDefAST &ast) override;
  void visit(DeclAST &ast) override;
  void visit(DefAST &ast) override;
  void visit(InitValAST &ast) override;
  void visit(FuncDefAST &ast) override;
  void visit(FuncFParamAST &ast) override;
  void visit(BlockAST &ast) override;
  void visit(BlockItemAST &ast) override;
  void visit(StmtAST &ast) override;
  void visit(ReturnStmtAST &ast) override;
  void visit(SelectStmtAST &ast) override;
  void visit(IterationStmtAST &ast) override;
  void visit(AddExpAST &ast) override;
  void visit(MulExpAST &ast) override;
  void visit(UnaryExpAST &ast) override;
  void visit(PrimaryExpAST &ast) override;
  void visit(LValAST &ast) override;
  void visit(NumberAST &ast) override;
  void visit(CallAST &ast) override;
  void visit(RelExpAST &ast) override;
  void visit(EqExpAST &ast) override;
  void visit(LAndExpAST &ast) override;
  void visit(LOrExpAST &ast) override;

private:
  ErrorReporter &err;
  bool Expr_int{};          //表达式的值是否为整型
  bool start_of_new_func{}; //是否是一个新函数定义的开始
  int Expr_value{};         //表达式的值
  bool in_loop;             //当前是否在循环中

  // 用于表示符号表中的各种类型信息的结构体
  struct Entry {
    bool is_array{};                       //是否为数组
    bool is_func{};                        //是否为函数
    TYPE type;                             //变量类型or返回值类型
    int array_length{};                    //如果是数组，则长度非0
    std::vector<int> arlen_value;          //数组的每一维长度
    std::vector<struct Entry> func_params; //函数参数列表
  };

  Entry current_type; //当前的type
  // list的每一项是一个作用域顶层的符号表，之间是嵌套关系
  std::list<std::map<std::string, Entry>> table;

  /**
   * @brief 在符号表中查找给定名称的条目
   *
   * @description: 从当前作用域开始向外逐层查找，返回找到的条目或nullptr
   * @param {std::string} name - 要查找的条目名称
   * @return {Entry*} - 找到的条目或nullptr
   */
  Entry *Lookup(const std::string &name) {
    for (auto it = table.begin(); it != table.end(); it++) {
      auto entry = it->find(name);
      if (entry != it->end()) {
        return &entry->second;
      }
    }
    return nullptr;
  }

  /**
   * @brief 插入变量到符号表
   *
   * @description:
   * 将变量声明插入到符号表中，包括遍历每个变量定义，检查数组类型等。
   * @param {DeclAST&} node - 变量声明节点
   * @return {bool} - 插入是否成功
   */
  bool InsertVar(const DeclAST &node) {
    // 由于每个变量声明包含若干个变量定义，所以需要遍历
    // 同时每个变量定义的类型信息在DeclAST中，所以需要传入

    if (!node.defList.empty()) {
      for (auto &def : node.defList) {
        Entry tmp;
        tmp.is_func = false;
        tmp.type = node.bType;
        if (!def->arrays.empty()) {
          tmp.is_array = true;
          for (auto &exp : def->arrays) {
            exp->accept(*this);
            // TODO ERROR
            // 例如 int a[0][1.2]; 这种情况
            if (!Expr_int) {
              err.error(ErrorType::ArrayIndexNotInt, *def->id);
              exit(int(ErrorType::ArrayIndexNotInt));
            }
            // tmp.arlen_value.push_back(Expr_value);
          }
          tmp.array_length = def->arrays.size();

        } else {
          tmp.is_array = false;
        }

        auto result =
            table.front().insert(std::pair<std::string, Entry>(*def->id, tmp));
        if (!result.second) {
          err.error(ErrorType::VarDuplicated, *def->id);
          return false;
        }
      }
    }
    return true;
  }

  /**
   * @brief 插入函数到符号表
   *
   * @description: 将函数定义插入到符号表，包括处理函数参数、检查重复定义等。
   * @param {FuncDefAST&} node - 函数定义节点
   * @return {bool} - 插入是否成功
   **/
  bool InsertFunc(const FuncDefAST &node) {
    // 为函数作用域分配新的符号表
    std::map<std::string, struct Entry> new_table;

    Entry tmp;
    tmp.is_array = false;
    tmp.is_func = true;
    tmp.type = node.funcType;
    if (!node.funcFParamList.empty()) {
      for (auto &param : node.funcFParamList) {
        //对每一个参数遍历
        Entry p;
        p.is_func = false;
        p.type = param->bType;
        //如果参数类型是数组
        if (param->isArray) {
          p.is_array = true;
          for (auto &exp : param->arrays) {
            if (exp == nullptr) //表明是一个指针
              p.arlen_value.push_back(-1);
            else {
              exp->accept(*this);
              p.arlen_value.push_back(Expr_value);
            }
          }
          p.array_length = param->arrays.size();
        } else
          p.is_array = false;
        //插入到函数参数列表
        tmp.func_params.push_back(p);
        //插入到函数作用域符号表
        auto result = new_table.insert(
            std::pair<std::string, struct Entry>(*param->id, p));
        //函数形参重复定义
        if (!result.second) {
          err.error(ErrorType::VarDuplicated, *param->id);
          exit(int(ErrorType::VarDuplicated));
        }
      }
    }

    // 这里检查函数定义是否重复
    auto checkFuncEntry = table.front().find(*node.id);
    if (checkFuncEntry != table.front().end()) {
      // TODO ERROR
      // 函数重复定义
      if (checkFuncEntry->second.is_func) {
        err.error(ErrorType::FuncDuplicated, *node.id);
        exit(int(ErrorType::FuncDuplicated));
      }
    }

    // 插入到当前作用域的符号表
    auto result = table.front().insert(
        std::pair<std::string, struct Entry>(*node.id, tmp));
    if (result.second) {
      // 更改作用域
      table.push_front(new_table);
      return true;
    } else {
      return false;
    }
  }

  /**
   * @brief 创建新的符号表
   *
   * @description: 为新的作用域创建一个空的符号表，并将其添加到符号表链中。
   **/
  void make_new_table() {
    std::map<std::string, Entry> new_table;
    table.push_front(new_table);
  }

  /**
   * @brief 删除当前作用域的符号表
   *
   * @description: 删除当前作用域的符号表，将符号表链中的当前作用域移除。
   **/
  void delete_table() { table.pop_front(); }

  /**
   * @brief 查找当前符号表链中的函数
   *
   * @description:
   *在符号表链中查找并返回当前函数的条目，如果没有函数则返回nullptr。
   * @return {Entry*} - 找到的函数条目或nullptr
   **/
  Entry *find_func() {
    for (auto &it : table) {
      for (auto &entry : it) {
        if (entry.second.is_func) {
          return &entry.second;
        }
      }
    }
    return nullptr;
  }
};

#endif // CARROTCOMPILER_CHECKER_H
