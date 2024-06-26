#ifndef TEST_DEFINE_H
#define TEST_DEFINE_H
#pragma once

enum STYPE {
    SEMI, ASS, EXP, CONT, BRE, RET, BLK, SEL, ITER
};

enum UOP {
    UOP_ADD, UOP_MINUS, UOP_NOT
};

enum AOP {
    AOP_ADD, AOP_MINUS
};

enum MOP {
    MOP_MUL, MOP_DIV, MOP_MOD
};

enum ROP {
    ROP_GTE, ROP_LTE, ROP_GT, ROP_LT
};

enum EOP {
    EOP_EQ, EOP_NEQ
};

enum TYPE {
    TYPE_VOID, TYPE_INT, TYPE_FLOAT
};

#endif //TEST_DEFINE_H
