#include "lexer.hpp"

Lexer::Lexer(){
    return;
}

Lexer::~Lexer(){
    return;
}

Lexer::Lexer(const Lexer &obj){
    *this = obj;
    return;
}

Lexer::Lexer(int argc, char** argv) : _lexemes(0){
    if (argc > 2){
        std::cout << "too many args" <<std::endl;
        return;
    }
    if (argc == 2){
        infile.open(argv[1]);
        if (infile.is_open() && infile.good()){
            while (getline(infile, line)){
                line += '\n';
                rawLines.push_back(line);
            }
        }else{
            std::cout << "file is not readable" << std::endl;
        }
    }
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
    for (size_t i = 0 ; i < rawLines.size(); i++){
        lex(rawLines[i]);
    }
    for (size_t i = 0; i < _lexemes.size(); i++){
        std::cout << "type : " << _lexemes[i].type;
        std::cout << " value : " <<_lexemes[i].value << std::endl;
    }
}

void
Lexer::lex(std::string line) {
    char c;
    std::string curr = "";
    std::regex i8("int8\\(-?[0-9]+\\)");
    std::regex i16("int16\\(-?[0-9]+\\)");
    std::regex i32("int32\\(-?[0-9]+\\)");
    std::regex d("double\\(-?[0-9]+\\.?[0-9]+\\)");
    std::regex f("float\\(-?[0-9]+\\.?[0-9]+\\)");
    for (size_t i = 0; i < line.length(); i++){
        c = line[i];
        if (c == ';')
            while (i < line.length())
                i++;
        
        if (isspace(c)){
            if (curr == "push"){
                _lexemes.emplace_back(Lexeme{PUSH, curr});
            }else if(curr == "pop"){
                _lexemes.emplace_back(Lexeme{POP, curr});
            }else if(curr == "dump"){
                _lexemes.emplace_back(Lexeme{DUMP, curr});
            }else if(curr == "assert"){
                _lexemes.emplace_back(Lexeme{ASSERT, curr});
            }else if(curr == "add"){
                _lexemes.emplace_back(Lexeme{ADD, curr});
            }else if(curr == "sub"){
                _lexemes.emplace_back(Lexeme{SUB, curr});
            }else if(curr == "mul"){
                _lexemes.emplace_back(Lexeme{MUL, curr});
            }else if(curr == "div"){
                _lexemes.emplace_back(Lexeme{DIV, curr});
            }else if(curr == "mod"){
                _lexemes.emplace_back(Lexeme{MOD, curr});
            }else if(curr == "print"){
                _lexemes.emplace_back(Lexeme{PRINT, curr});
            }else if(curr == "exit"){
                _lexemes.emplace_back(Lexeme{EXIT, curr});
            }else if(std::regex_match(curr, i8)){
                _lexemes.emplace_back(Lexeme{INT8, curr});
            }else if(std::regex_match(curr, i16)){
                _lexemes.emplace_back(Lexeme{INT16, curr});
            }else if(std::regex_match(curr, i32)){
                _lexemes.emplace_back(Lexeme{INT32, curr});
            }else if(std::regex_match(curr, f)){
                _lexemes.emplace_back(Lexeme{FLOAT, curr});
            }else if(std::regex_match(curr, d)){
                _lexemes.emplace_back(Lexeme{DOUBLE, curr});
            }else if (curr != ""){
                std::cout << "ERROR" << std::endl;
            }
            curr = "";
        }
        if (!isspace(c))
            curr += c;
    }
}    


