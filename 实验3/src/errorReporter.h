#ifndef CARROTCOMPILER_ERRORREPORTER_H
#define CARROTCOMPILER_ERRORREPORTER_H

#include <iostream>

enum class ErrorType {
  VarUnknown = 1,
  VarDuplicated,
  FuncUnknown,
  FuncDuplicated,
  FuncParamsNotMatch,
  FuncReturnTypeNotMatch,
  ArrayIndexNotInt,
  BreakNotInLoop,
  ContinueNotInLoop,
  VisitVariableError,
};

/**
 * @brief 错误报告器
 *
 * @description: 用于报告编译器中的错误信息，包括错误类型和相关的语法节点。
 */
class ErrorReporter {
public:
  /**
   * 构造错误报告器
   * @param error_stream - 输出错误信息的流
   */
  explicit ErrorReporter(std::ostream &error_stream);

  // void error(const std::string &msg);
  /**
   * 报告特定类型的错误
   * @param type - 错误类型
   * @param ast - 相关的语法节点信息
   **/
  void error(ErrorType type, const std::string &ast);

private:
  std::ostream &err;
};

#endif // CARROTCOMPILER_ERRORREPORTER_H
