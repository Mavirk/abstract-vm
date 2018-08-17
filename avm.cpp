#include "avm.hpp"

AVM::AVM(std::string filename){
    std::ifstream f(filename);
    _end = false;
    std::string line;
    std::vector<std::string> raw;

    if(filename.empty() || !f.good()){
        std::cout << "Input Error : Invalid File ... Starting Manual Input Mode" << std::endl;
        while (line != ";;"){
            std::getline(std::cin, line);
            line += '\n';
            if (line != ";;")
                raw.push_back(line);
            else
                raw.push_back("exit\n");
        }
    }else if (f.is_open()){
        while (getline(f, line)){
            line += '\n';
            raw.push_back(line);    
        }
    }else
        throw InputError("Unforseen error");

    Lexer   lexer(raw);
    lexer.run();
    _lexemes = lexer.getLexemes();
    
    _fptr["push"] = &AVM::push;
    _fptr["pop"] = &AVM::pop;
    _fptr["dump"] = &AVM::dump;
    _fptr["assert"] = &AVM::ass;
    _fptr["add"] = &AVM::add;
    _fptr["sub"] = &AVM::sub;
    _fptr["mul"] = &AVM::mul;
    _fptr["div"] = &AVM::div;
    // _fptr["mod"] = &AVM::mod;
    _fptr["print"] = &AVM::print;
    _fptr["exit"] = &AVM::exit;
}

AVM::~AVM(){}

AVM::AVM(const AVM& obj){
    *this = obj;
}

AVM &
AVM::operator=(const AVM & vm){
    if (this != &vm) {
        _end = vm._end;
        _buf = vm._buf;
        _stack = vm._stack;
        _fptr = vm._fptr;
    }
    return *this;
}

void
AVM::run(){
    for(size_t i = 0; i < _lexemes.size(); i++){
        std::cout << i << std::endl;
        if (_lexemes[i].value == "push" || _lexemes[i].value == "assert"){
            // std::cout << "blah" << std::endl;
            if (i + 1 < _lexemes.size()){
                std::cout << "Push or Assert ? : " << _lexemes[i].value << std::endl;
                std::cout << "Type ? : " << _lexemes[i + 1].value << std::endl;
                (this->*_fptr[_lexemes[i].value])(_lexemes[i + 1].value);
                i++;
            }else{
                throw NoExit("no exit was found");
            }
            // std::cout << "test" << std::endl;
        }else{
            // std::cout << "test2" << std::endl;                
            (this->*_fptr[_lexemes[i].value])("");
        }
    }
    if (_end)
        return;
    throw NoExit("NO exit was found");
}
void
AVM::push(std::string const &str){
    // std::cout << "push" << std::endl;
    _stack.emplace(Parser::operand(str));
    // std::cout << "called" << std::endl;
}
void
AVM::pop(std::string const &str UNUSED){
    if (_stack.empty())
        throw StackError("Pop on empty");
    _stack.pop();
}
void
AVM::dump(std::string const &str UNUSED){
    std::stack<IOperand const *> s = _stack;
    while (!s.empty()){
        std::cout << s.top()->toString() << std::endl;
        s.pop();
    }
}
void
AVM::ass(std::string const &str){
    IOperand const		*cmp = Parser::operand(str);
    // std::cout << _stack.top()->toString() << std::endl;
    if (_stack.top()->getType() != cmp->getType()
        || _stack.top()->toString() != cmp->toString()){
            throw AssertFalse(str + "cannot be asserted to top of stack");
        }
}
void
AVM::add(std::string const &str UNUSED){
    IOperand const   *a, *b;
    if (_stack.size() < 2)
        throw StackLessThan2("");
    a = _stack.top();
    std::cout << "a" << _stack.top()->toString() << std::endl;
    _stack.pop();
    b = _stack.top();
    std::cout << "b" <<_stack.top()->toString() << std::endl;
    _stack.pop();
    _stack.emplace(*a + *b);
    std::cout << _stack.top()->toString() << std::endl;
}
void
AVM::sub(std::string const &str UNUSED){
    IOperand const   *a, *b;
    if (_stack.size() < 2)
        throw StackLessThan2("");
    a = _stack.top();
    _stack.pop();
    b = _stack.top();
    _stack.pop();
    _stack.emplace(*a - *b);
}
void
AVM::mul(std::string const &str UNUSED){
    IOperand const   *a, *b;
    if (_stack.size() < 2)
        throw StackLessThan2("");
    a = _stack.top();
    _stack.pop();
    b = _stack.top();
    _stack.pop();
    _stack.emplace(*a * *b);

}
void
AVM::div(std::string const &str UNUSED){
    IOperand const   *a, *b;
    if (_stack.size() < 2)
        throw StackLessThan2("");
    a = _stack.top();
    _stack.pop();
    b = _stack.top();
    _stack.pop();
    _stack.emplace(*a / *b);

}
// void
// AVM::mod(std::string const &str UNUSED){
//     IOperand const   *a, *b;
//     if (_stack.size() < 2)
//         throw StackLessThan2("");
//     a = _stack.top();
//     _stack.pop();
//     b = _stack.top();
//     _stack.pop();
//     _stack.emplace(*a % *b);

// }
void
AVM::print(std::string const &str UNUSED){
    std::stringstream   ss;
    int                 val;

    if (_stack.top()->getType() != Int8){
        throw LogicalError("Cant print non-int8 value");
    }
    ss << _stack.top()->toString();
    ss >> val;
    std::cout << static_cast<char>(val);

}
void
AVM::exit(std::string const &str UNUSED){
    _end = true;
}