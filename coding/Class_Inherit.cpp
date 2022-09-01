#include <iostream>

//静态属性和静态函数

//声明时加上static关键字
//static的作用: 1.可以隐藏，表示只在该文件有效
//  2.保持变量内容的持久。存储在静态数据区的变量会在程序刚开始运行时
//就完成初始化，并且是唯一一次初始化
//  3.普通成员变量每个对象有各自的一份，而静态成员变量一共就一份，
//为所有对象共享


class Pet
{
public:
    Pet(std:: string name);
    ~Pet();
    int static Getcount();

private:
    std:: string name;
    static int count;

};

int Pet::count = 0;

Pet::Pet(std:: string name)
{

    this->name = name;
    std::cout<< name <<" borned\n"<<std::endl;
    count++;
}

Pet::~Pet()
{ 

    std::cout<< name<<" died away\n"<<std::endl;
    count--;
}

int Pet::Getcount()
{

    return count;
}


class Dog :public Pet
{
public:
    Dog(std:: string name);

};

Dog::Dog(std:: string name): Pet(name)
{

};

class Cat :public Pet
{
public:
    Cat(std:: string name);

};

Cat::Cat(std:: string name): Pet(name)
{

};


int main()
{

    Dog dog("Tom");
    Cat cat("Jerry");

    std::cout<<"Now we have "<< Pet::Getcount() << " Pet(s)!"
    <<std::endl;

    {   //此处的大括号，指示了一个生命周期
    Dog dog2("Tom2");
    Cat cat2("Jerry2");

    std::cout<<"Now we have "<< Pet::Getcount() << " Pet(s)!"
    <<std::endl;
    }

    std::cout<<"Now we have "<< Pet::Getcount() << " Pet(s)!"
    <<std::endl;


    system("pause");
    return 0;
}
