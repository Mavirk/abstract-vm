#ifndef LEXER_HPP
#define LEXER_HPP

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <regex>
enum token {
    PUSH = 10,
    POP = 11,
    DUMP = 12,
    ASSERT = 13,
    ADD = 14,
    SUB = 15,
    MUL = 16,
    DIV = 17,
    MOD = 18,
    PRINT = 19,
    EXIT = 20,
    INT8 = 21,
    INT16 = 22,
    INT32 = 23,
    FLOAT = 24,
    DOUBLE = 25,
    ERROR = -1
};

struct Lexeme
{
    token           type;
    std::string     value;
    size_t             l;
};

class Lexer {
    public:
        Lexer(std::vector<std::string> raw);
        ~Lexer();
        Lexer(const Lexer& obj);
        Lexer                   &operator=(Lexer const& rhs);

        std::vector<Lexeme>         getLexemes() const;
        void                        run();
        void                        lex(std::string line, size_t j);

    private:
        std::vector<Lexeme>         _lexemes;
        std::string                 _line;
        std::vector<std::string>    _rawLines;
};
#endif