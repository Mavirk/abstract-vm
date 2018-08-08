#include "lexer.hpp"

int main(int argc, char **argv){
    Lexer   lexer(argc, argv);
    lexer.run();  
    return (0); 
}