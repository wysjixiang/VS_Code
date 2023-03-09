#include <iostream>
#include <string>
#include <typeinfo>
#include <cxxabi.h> // 所需头文件

/*
类模板实例化出的对象，向函数传参的方式有3种
1. 指定传入类型 --用的最多！
2. 参数模板化
3. 整个类模板化
*/

/*
1.  子类在继承父类模板时，必须要指定父类中T的类型
2.  类模板函数类外实现时，需要加上模板参数列表
3.  类模板分文件编写- 将声明和实现写道一起，文件后缀名改为.hpp   主流方法！

*/






//注： typeid.name()函数，由于编译器的不同，输出也不同，GCC编译器输出结果难懂，因此用__cxa_demangle函数转译

template<class NameType,class AgeType>
class Person
{
public:
    Person(NameType name,AgeType age)
    {
        Pname = name;
        Page = age;
    }
    //~Person();

    void showperson()
    {

        std::cout<<"name: "<<this->Pname<<" age: "<<this->Page<<std::endl;

    }

private:

NameType Pname;
AgeType Page;


};


//1. 指定传入类型

/*
    注： 如下函数fun(const std::string& str) 表示的是将str直接传给函数，而不是简单的拷贝一份。在前加const，表示不可修改str的值。
    因此注意这三种参数传递的区别！
*/

void printPerson1(Person<std::string,int> &p)
{

    p.showperson();
}

void test01()
{
    Person <std::string,int> person1("孙悟空",999);
    printPerson1(person1);

}

//2. 参数模板化
template<class T1,class T2>
void printPerson2(Person<T1,T2> &p)
{
    p.showperson();
    std::cout <<"T1的类型为: " << abi::__cxa_demangle(typeid(T1).name(),NULL,NULL,NULL)<<std::endl;
    std::cout <<"T2的类型为: " << abi::__cxa_demangle(typeid(T2).name(),NULL,NULL,NULL)<<std::endl;
}

void test02()
{
    Person <std::string,int> person2("红孩儿",888);
    printPerson2(person2);

}

//3.整个类模板化
template<class T>
void printPerson3(T &p)
{
    p.showperson();
    std::cout<<"T的类型为: "<< abi::__cxa_demangle(typeid(T).name(),NULL,NULL,NULL)<<std::endl;
}

void test03()
{
    Person <std::string,int> person3("猪头",666);
    printPerson3(person3);

}

int main()
{

    test01();
    test02();
    test03();

    system("pause");
    return 0;
}