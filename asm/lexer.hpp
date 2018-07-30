#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <vector>

typedef uint8_t byte;
typedef std::vector<std::string> strings;

enum State : byte{
    START,
    READCHAR,
    READBLOCK,
    SKIP,
    DUMP,
    COMMENT,
    END,
}

class Lexer {
    bool isSpace(char c);
    bool isSpecial(char c);
    bool isGroup(char c);
    char end_char;
    char beg_char;

};
#endif
