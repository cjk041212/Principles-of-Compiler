#include "errorReporter.h"
#include "string"

ErrorReporter::ErrorReporter(std::ostream &error_stream) : err(error_stream) {}

// void ErrorReporter::error(const std::string &msg) {
//  std::cerr << "Error: " << msg << std::endl;
//}

void ErrorReporter::error(ErrorType type, const std::string &ast) {
  std::string error_msg = "Error: ";
  switch (type) {
  case ErrorType::VarUnknown:
    error_msg += "Use Undefined Variable";
    std::cerr << error_msg + " \"" + ast + "\"." << std::endl;
    break;
  case ErrorType::VarDuplicated:
    error_msg += "Redefined Variable";
    std::cerr << error_msg + " \"" + ast + "\"." << std::endl;
    break;
  case ErrorType::FuncUnknown:
    error_msg += "Use Undefined Function";
    std::cerr << error_msg + " \"" + ast + "\"." << std::endl;
    break;
  case ErrorType::FuncDuplicated:
    error_msg += "Redefined Function";
    std::cerr << error_msg + " \"" + ast + "\"." << std::endl;
    break;
  case ErrorType::FuncParamsNotMatch:
    error_msg += "Can not Match Function Parameters";
    std::cerr << error_msg + " \"" + ast + "\"." << std::endl;
    break;
  case ErrorType::FuncReturnTypeNotMatch:
    error_msg += "Func return type not match.";
    std::cerr << error_msg << std::endl;
    break;
  case ErrorType::ArrayIndexNotInt:
    error_msg += "Array";
    std::cerr << error_msg + " \"" + ast + "\" index not int." << std::endl;
    break;
  case ErrorType::BreakNotInLoop:
    error_msg += "Break not in loop.";
    std::cerr << error_msg << std::endl;
    break;
  case ErrorType::ContinueNotInLoop:
    error_msg += "Continue not in loop.";
    std::cerr << error_msg << std::endl;
    break;
  case ErrorType::VisitVariableError:
    error_msg += "Visit non-array variable in the form of subscript variables.";
    std::cerr << error_msg << std::endl;
    break;
    //        case ErrorType::ReturnNotInFunc:
    //            error_msg += "Return not in function";
    //            std::cerr << error_msg << std::endl;
    //            break;
  default:
    break;
  }
}
