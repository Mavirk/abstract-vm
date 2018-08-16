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
    _fptr["mod"] = &AVM::mod;
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
    std::cout << "this is a test" << std::endl;
}
void
AVM::push(std::string const &str){
    _stack.emplace(Parser::operand(str));
}
void
AVM::pop(std::string const &str UNUSED){
    if (_stack.empty())
        throw StackError("Pop on empty");
    _stack.pop();
}
void
AVM::dump(std::string const &str UNUSED){
    std::stack<IOperand *> s = _stack;
    while (!s.empty()){
        std::cout << s.top()->toString() << std::endl;
        s.pop();
    }
}
void
AVM::ass(std::string const &str){
    IOperand const		*cmp = Parser::operand(str);
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
    _stack.pop();
    b = _stack.top();
    _stack.pop();
    _stack.emplace(*a + *b);
}
void
AVM::sub(std::string const &str UNUSED){
    IOperand    *a, *b;
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
    IOperand    *a, *b;
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
    IOperand    *a, *b;
    if (_stack.size() < 2)
        throw StackLessThan2("");
    a = _stack.top();
    _stack.pop();
    b = _stack.top();
    _stack.pop();
    _stack.emplace(*a / *b);

}
void
AVM::mod(std::string const &str UNUSED){
    IOperand    *a, *b;
    if (_stack.size() < 2)
        throw StackLessThan2("");
    a = _stack.top();
    _stack.pop();
    b = _stack.top();
    _stack.pop();
    _stack.emplace(*a % *b);

}
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