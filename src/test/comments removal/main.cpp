#include <sstream>
#include <iostream>
 
int main()
{
    std::cout << "test0";
    std::string s = "h;ello my name is robert" ;
    std::cout << "test1";
    std::istringstream s1(s);
    std::cout << "test2";
    char str[s.length()];
    s1.get(str, s.length(), ';');     // reads "llo,"
    std::cout << str << std::endl;
    return (0);
}