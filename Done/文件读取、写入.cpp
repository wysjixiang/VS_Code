#include <iostream>
#include <string>
#include <fstream>

/*********************************************
文件处理：


//读数据
/*****************************************
int main()
{
    
    std::fstream ofs;
    ofs.open("file.txt",std::ios::in);

    // std::string str;
    // while(getline(ofs,str))
    // {
    //         std::cout<< str<<std::endl;
    // }

    char str;
    while( (str= ofs.get()) != EOF  )
    {

        std::cout<< str;
    }


    ofs.close();

    system("pause");
    return 0;
}


读取二进制文件！
int main()
{
    
    std::ifstream ofs;
    ofs.open("file.txt",std::ios::in | std::ios::binary);

    Pet dog{"zhutou",4};
    std::cout<<"name & age: "<<dog.name <<"  "<<dog.age<<std::endl;
    ofs.read( (char *)&dog,sizeof(dog));
    std::cout<<"name & age: "<<dog.name <<"  "<<dog.age<<std::endl;

    ofs.close();

    system("pause");
    return 0;
}
*****************************************/

class Pet
{
public:
    char name[10];
    int age = 0;

};


int main()
{
    
    std::ifstream ofs;
    ofs.open("file.txt",std::ios::in | std::ios::binary);

    Pet dog{"zhutou",4};
    std::cout<<"name & age: "<<dog.name <<"  "<<dog.age<<std::endl;
    ofs.read( (char *)&dog,sizeof(dog));
    std::cout<<"name & age: "<<dog.name <<"  "<<dog.age<<std::endl;

    ofs.close();

    system("pause");
    return 0;
}