#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include "printer.h"
#include "ast.h"
#include "checker.h"


extern unique_ptr<CompUnitAST> root;
extern int yyparse();
extern void initFileName(char *);
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

extern FILE *yyin;
void preprocess(std::string srcFileName);
int main(int argc, char **argv) {
    // assert(argc >= 2);
    bool print_ast = true;
    if(argc>=2){
        char *filename;
        if(argc == 2) {
            filename = argv[1];
        }else if(argc == 3){
            print_ast = false;
            filename = argv[2];
        }
        yyin = fopen(filename, "r");
        if (yyin == nullptr) {
            std::cout << "yyin open " << filename << " failed" << std::endl;
            return -1;
        }
        std::string filename_out = strcpy(filename,strrchr(filename,'/')+1);

        initFileName(filename);
    }
    yyparse();
    extern int error_num;
    //ofstream outfile;
    //outfile.open("../ast/" + filename_out + ".ast.txt", ios::out | ios::trunc);
    Printer printer;
    std::string info = printer.visit(*root);
    if(print_ast)
        std::cout << info << std::endl;
    if(error_num)
        cout<<RED<<(std::string("There is ")+std::to_string(error_num)+" Syntax Error!\n").c_str()<<RESET;
    else
        cout<<GREEN<<"Congratulate! There is not Syntax Error!\n"<<RESET;

    std::ostringstream os;
    ErrorReporter errorReporter(os);
    Checker checker(errorReporter);
    try{
        cout<<RED<<"-------------------998244353-------------------\n"<<RESET;
        checker.visit(*root);
    }
    catch(int ReturnCode){
        cout<<RED<<"-------------------1000000007-------------------\n"<<RESET;
        std::string info = os.str();
        // printerror((std::string("There is ")+std::to_string(error_num)+" Syntax Error!\n").c_str());
        cout<<RED<<(std::string("[Means Error!] : ")+info).c_str()<<RESET;
        return -1;
    }
    cout<<GREEN<<"Congratulate! There is not YuYi Error!\n"<<RESET;
    return 0;
}
