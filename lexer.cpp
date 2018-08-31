#include "lexer.hpp"

Lexer::Lexer(std::vector<std::string> raw) {
    _rawLines = raw;
}

Lexer::~Lexer(){
    return;
}

Lexer::Lexer(const Lexer &obj){
    *this = obj;
    return;
}

Lexer&
Lexer::operator=(Lexer const &rhs){
    if (this != &rhs){
        this->_lexemes = rhs.getLexemes();
    }
    return *this;
}

std::vector<Lexeme>
Lexer::getLexemes() const{
    return this->_lexemes;
}

void
Lexer::run() {
    for (size_t i = 0 ; i < _rawLines.size(); i++){
        lex(_rawLines[i], i + 1);
    }
    // for (size_t i  = 0; i < _lexemes.size(); i++){
    //     std::cout << " type " <<_lexemes[i].type << " value ";
    //     std::cout << _lexemes[i].value << std::endl ;

    // }
}

void
Lexer::lex(std::string line, size_t j) {
    char c;
    std::string curr = "";
    std::regex i8("int8\\(-?[0-9]+\\)");
    std::regex i16("int16\\(-?[0-9]+\\)");
    std::regex i32("int32\\(-?[0-9]+\\)");
    std::regex d("double\\([-]?([0-9]*[.])?[0-9]+\\)");
    std::regex f("float\\([-]?([0-9]*[.])?[0-9]+\\)");
    for (size_t i = 0; i < line.length(); i++){
        c = line[i];
        if (c == ';'){
            c = ' ';
            while (i < line.length())
                i++;
        }
        // std::cout << "curr " << curr << std::endl;
        if (isspace(c)){
            if (curr == "push"){
                _lexemes.emplace_back(Lexeme{PUSH, curr, j});
            }else if(curr == "pop"){
                _lexemes.emplace_back(Lexeme{POP, curr, j});
            }else if(curr == "dump"){
                _lexemes.emplace_back(Lexeme{DUMP, curr, j});
            }else if(curr == "assert"){
                _lexemes.emplace_back(Lexeme{ASSERT, curr, j});
            }else if(curr == "add"){
                _lexemes.emplace_back(Lexeme{ADD, curr, j});
            }else if(curr == "sub"){
                _lexemes.emplace_back(Lexeme{SUB, curr, j});
            }else if(curr == "mul"){
                _lexemes.emplace_back(Lexeme{MUL, curr, j});
            }else if(curr == "div"){
                _lexemes.emplace_back(Lexeme{DIV, curr, j});
            }else if(curr == "mod"){
                _lexemes.emplace_back(Lexeme{MOD, curr, j});
            }else if(curr == "print"){
                _lexemes.emplace_back(Lexeme{PRINT, curr, j});
            }else if(curr == "exit"){
                _lexemes.emplace_back(Lexeme{EXIT, curr, j});
            }else if(std::regex_match(curr, i8)){
                _lexemes.emplace_back(Lexeme{INT8, curr, j});
            }else if(std::regex_match(curr, i16)){
                _lexemes.emplace_back(Lexeme{INT16, curr, j});
            }else if(std::regex_match(curr, i32)){
                _lexemes.emplace_back(Lexeme{INT32, curr, j});
            }else if(std::regex_match(curr, f)){
                _lexemes.emplace_back(Lexeme{FLOAT, curr, j});
            }else if(std::regex_match(curr, d)){
                _lexemes.emplace_back(Lexeme{DOUBLE, curr, j});
            }else if (curr != ""){
                _lexemes.emplace_back(Lexeme{ERROR, curr, j});
            }
            curr = "";
        }
        if (!isspace(c))
            curr += c;
    }
}    


