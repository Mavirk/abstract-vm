#include <iostream>
#include "avm.hpp"
#include "exception.hpp"
// #include "parser.hpp"
#include "Ioperand.hpp"

int main(int argc , char **argv ){
    try {
        AVM	vm(argv[1]);
        // Parser::createOperand(Int8, "test");
        vm.run();

    } catch (Exception const& e) {
        std::cerr << e.what() << std::endl;
        return 0;
    }
}