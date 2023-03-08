#include <iostream>



/*********************************************
静态属性和静态函数

声明时加上static关键字
static的作用: 1.可以隐藏，表示只在该文件有效
 2.保持变量内容的持久。存储在静态数据区的变量会在程序刚开始运行时
就完成初始化，并且是唯一一次初始化
 3.普通成员变量每个对象有各自的一份，而静态成员变量一共就一份，
为所有对象共享

在使用静态属性的时候，千万不要忘记为它们分配内存。具体做法很简单，只要在类声明的外部
对静态属性做出声明（就像声明一个变量那样）即可。


静态方法：
静态成员是所有对象共享的，所以不能在静态方法里面访问非静态的元素。
为啥呢？ 和this指针有关。 每当我们调用一个方法的时候，this指针都会随着你提供的输入参数被秘密的传递给那个方法。
正是因为如此，我们才能在方法里像使用一个局部变量那样使用this指针。
因为静态方法不是属于某个特定的对象，而是由全体对象共享的，这就意味着他们无法访问this指针。
所以我们才无法在静态方法里访问非静态的类成员！
非静态方法可以访问类的静态成员，也可以访问类的非静态成员。

调用静态方法时，请使用：
ClassName::MethodName();
而不要使用:
ObjectName.MethodName();    这样就可以和普通的方法区别开，容易判断这是静态方法！


This指针：
this指针是类的一个自动生成、自动隐藏的私有成员，它存在于类的非静态成员函数中，指向被调用函数所在的对象的地址。
当一个对象被创建时，该对象的this指针就自动指向对象数据的首地址

*********************************************/

class Pet
{
public:
    Pet(std:: string name);
    ~Pet();
    int static Getcount();

private:
    std:: string name;
    static int count;   //声明

};

int Pet::count = 0;     //为静态变量分配内存并初始化

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
