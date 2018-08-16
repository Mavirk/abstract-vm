#include <iostream>
#include "avm.hpp"
#include "exception.hpp"

int main(int argc UNUSED, char **argv UNUSED){
    try {
        AVM	vm(argv[1]);
        vm.run();
    } catch (Exception const& e) {
        std::cerr << e.what() << std::endl;
        return 0;
    }
}