#include <iostream>

//子类继承父类时，可以通过覆盖的方法来覆盖实现方法等。
// 只需要重新声明、定义实现方法即可，如下
//声明了eat()这个函数，直接继承父类。或者在子类中覆盖，实现新功能。

class Animal
{
public:
    std::string name;

    Animal(std::string name)
    {
        this->name = name;
        std::cout<<"Animal class constructor!\n"<<std::endl;
    }

    ~Animal(){};

    void showname()
    {

        std:: cout<< "My name is:" << name << std::endl;
    }


    void eat()
    {

        std:: cout<< "Animal "<<name << " eating!" << std::endl;
    }


};


//此处只继承父类里的public
class Pig : public Animal
{
public:

    //在子类中的构造函数，可以直接继承父类的，语法如下：
    Pig(std::string name):Animal(name){};

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


    void eat()
    {
        Animal::eat();
        std:: cout<< "pig eating!" << std::endl;
    }



};


int main()
{

    Pig pig1("Little Piggy");
    pig1.showname();

    pig1.eat();

    system("pause");
    return 0;
}
