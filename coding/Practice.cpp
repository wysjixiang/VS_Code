#include <iostream>
#include <string>
#include <fstream>








class Person
{
public:
    char ZGBH[32] = {0};
    char NAME[32] = {0};
    char BMBH[32] = {0};

};

int main()
{
    Person person;
    int i=0;
    std::ifstream ifs;
    ifs.open("file.csv",std::ios::in);
    char str;
    std::string s;
    getline(ifs, s);
    std::cout<< s << std::endl;
    while( (str = ifs.get()) != '\n' && str != EOF)
    {
        i=0;
        while(str != ',')
        {
            person.ZGBH[i++] = str;
            str = ifs.get();
        }
        person.ZGBH[i] = '\0';
        i=0;
        while((str = ifs.get()) != ',')
        {
            person.NAME[i++] = str; 
        }
        person.NAME[i] = '\0';
        i=0;
        while((str = ifs.get()) != '\n')
        {
            person.BMBH[i++] = str;
        }
        person.BMBH[i] = '\0';
    }

    std::cout<< person.ZGBH << std::endl;
    std::cout<< person.NAME << std::endl;
    std::cout<< person.BMBH << std::endl;

    ifs.close();
    // std::ifstream ifs;
    // ifs.open("file.csv",std::ios::in);
    // std::string  readStr((std::istreambuf_iterator<char>(ifs)),  std::istreambuf_iterator<char>()); 
    // std::cout<< readStr.c_str();
    // ifs.close();
    system("pause");
    return 0;
}