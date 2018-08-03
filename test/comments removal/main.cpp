#include <sstream>
#include <iostream>
 
int main()
{
    // std::cout << "test0";
    // std::string s = "; -------------\n; exemple.avm -\n; -------------\n\npush int32(42)\npush int32(33)\n\nadd\n\npush float(44.55)\n\nmul\n\npush double(42.42)\npush int32(42)\n\ndump\n\npop\n\nassert double(42.42)\n\nexit\n";
    std::string s = "mon;day tuesday wednesday";
    // std::cout << s;
    std::istringstream s1(s);
    // std::cout << "test2";
    char str[s.length()];
    s1.get(str, s.length(), ';');     // reads "llo,"
    std::cout << str << std::endl;
    return (0);
}