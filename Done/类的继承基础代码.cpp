#include <iostream>

// 练习类的继承 -- 编写一个Animal类作为Turtle类和Pig类的基类
// 基类，子类的概念。 基类可以派生出其他的类，子类从基类派生而来

class Animal
{
public:
    std::string name;

    Animal(std::string name)
    {
        this->name = name;
        std::cout<<"Animal class constructor!\n"<<std::endl;
    }

    ~Animal()
    {
        std::cout<<"Animal class destructor!\n"<<std::endl;
    }

    void showname()
    {

        std:: cout<< "My name is:" << name << std::endl;
    }

};


//此处只继承父类里的public
class Pig : public Animal
{
public:

    //在子类中的构造函数，可以直接继承父类的，语法如下：
    Pig(std::string name):Animal(name){};
    ~Pig()
    {
        std::cout<<"Pig class destructor!\n"<<std::endl;
    }

    void swim()
    {
        std::cout<<"I am a pig, I can swim!\n" << std::endl;
    }


    void modweight(double w)
    {

        weight = w;
    }

    void showweight()
    {

        std::cout<< "Weight is: "<< weight<<std::endl;
    }

    double weight = 0;

};


int main()
{

    Pig *pig1 = new Pig("Little Piggy");
    pig1->showname();

    pig1->name = "Big piggy";
    pig1->showname();

    std::cout<<"Weight is: "<< pig1->weight<<std::endl;

    pig1->modweight(70.9);

    std::cout<<"Weight is: "<< pig1->weight<<std::endl;
    delete pig1;
    system("pause");
    return 0;
}
