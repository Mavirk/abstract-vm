#include "lexer.hpp"
#include "parser.hpp"

int main(int argc, char **argv){
    Lexer   lexer(argc, argv);
    lexer.run();
    Parser  parser();
    return (0); 
}