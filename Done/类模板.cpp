#include <iostream>
#include <string>
#include <typeinfo>
#include <cxxabi.h> // ����ͷ�ļ�

/*
��ģ��ʵ�������Ķ����������εķ�ʽ��3��
1. ָ���������� --�õ���࣡
2. ����ģ�廯
3. ������ģ�廯
*/

/*
1.  �����ڼ̳и���ģ��ʱ������Ҫָ��������T������
2.  ��ģ�庯������ʵ��ʱ����Ҫ����ģ������б�
3.  ��ģ����ļ���д- ��������ʵ��д��һ���ļ���׺����Ϊ.hpp   ����������

*/






//ע�� typeid.name()���������ڱ������Ĳ�ͬ�����Ҳ��ͬ��GCC�������������Ѷ��������__cxa_demangle����ת��

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


//1. ָ����������

/*
    ע�� ���º���fun(const std::string& str) ��ʾ���ǽ�strֱ�Ӵ��������������Ǽ򵥵Ŀ���һ�ݡ���ǰ��const����ʾ�����޸�str��ֵ��
    ���ע�������ֲ������ݵ�����
*/

void printPerson1(Person<std::string,int> &p)
{

    p.showperson();
}

void test01()
{
    Person <std::string,int> person1("�����",999);
    printPerson1(person1);

}

//2. ����ģ�廯
template<class T1,class T2>
void printPerson2(Person<T1,T2> &p)
{
    p.showperson();
    std::cout <<"T1������Ϊ: " << abi::__cxa_demangle(typeid(T1).name(),NULL,NULL,NULL)<<std::endl;
    std::cout <<"T2������Ϊ: " << abi::__cxa_demangle(typeid(T2).name(),NULL,NULL,NULL)<<std::endl;
}

void test02()
{
    Person <std::string,int> person2("�캢��",888);
    printPerson2(person2);

}

//3.������ģ�廯
template<class T>
void printPerson3(T &p)
{
    p.showperson();
    std::cout<<"T������Ϊ: "<< abi::__cxa_demangle(typeid(T).name(),NULL,NULL,NULL)<<std::endl;
}

void test03()
{
    Person <std::string,int> person3("��ͷ",666);
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