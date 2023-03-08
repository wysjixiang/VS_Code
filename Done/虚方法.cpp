#include <iostream>



/*********************************************
虚方法

背景：  C++允许我们定义一个基类的指针指向子类的数据空间。但当子类中存在覆盖基类的方法时，我们想用指针调用子类的方法，
就会出现问题，结果是调用了基类的方法。在编译的时候，编译器会认为这里是一个基类型的指针，因此也就认为指针中的方法
是基类的方法。

解决方案： 将方法声明为虚方法！ 只要前面加上virtual关键字就行。并且虚方法是继承的，在子类里就不能再把它声明为非虚方法 
虚方法的运行速度会比较慢一些。 析构器都是虚方法！


*********************************************/


class Pet
{
public:
    virtual void eat()
    {
        std::cout<< "Pet eatting!\n" <<std::endl;
    }

};

class Pig: public Pet
{
public:
    void eat()
    {
        std::cout<< "Pig eatting!\n" <<std::endl;
    }
};


int main()
{

    Pet *pig1 = new Pig;    //用 Pig *pig1 = new Pig;就没有问题
    pig1 ->eat();

    system("pause");
    return 0;
}
