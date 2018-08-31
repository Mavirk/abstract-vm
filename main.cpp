#include <iostream>
#include "avm.hpp"
#include "exception.hpp"
// #include "parser.hpp"
#include "Ioperand.hpp"

int main(int argc , char **argv ){
    try {
        if(argc == 1){
            AVM mm("");
            mm.run();

        }else{
            AVM	vm(argv[1]);
            vm.run();
        }
        // Parser::createOperand(Int8, "test");

    } catch (Exception const& e) {
        std::cerr << e.what() << std::endl;
        return 0;
    }
}