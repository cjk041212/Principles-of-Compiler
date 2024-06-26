#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include "printer.h"
#include "ast.h"

extern unique_ptr<CompUnitAST> root;
extern int yyparse();
extern void initFileName(char*);
extern FILE* yyin;
void preprocess(std::string srcFileName);
int main(int argc, char** argv) {
    assert(argc >= 2);
    char* filename;
    bool print_ast = false;
    if (argc == 2) {
        filename = argv[1];
    }
    else if (argc == 3) {
        print_ast = true;
        filename = argv[2];
    }
    yyin = fopen(filename, "r");
    if (yyin == nullptr) {
        std::cout << "yyin open " << filename << " failed" << std::endl;
        return -1;
    }
    std::string filename_out = strcpy(filename, strrchr(filename, '/') + 1);

    initFileName(filename);

    yyparse();

    if (print_ast) {
        //ofstream outfile;
        //outfile.open("../ast/" + filename_out + ".ast.txt", ios::out | ios::trunc);
        Printer printer;
        std::cout << printer.visit(*root) << std::endl;
    }
    return 0;
}
