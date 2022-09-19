#include <iostream>
#include <string>
#include <fstream>

#include <vector>
#include <algorithm>





int main()
{

    

	std::string str;
    str = "This is a test!";
    std::string substr;
    substr = str.substr(0,6);


    std::cout << str << std::endl;
    std::cout << substr << std::endl;

    system("pause"); 
    return 0;
}