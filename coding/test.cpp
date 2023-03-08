#include <iostream>
#include <string>


/*********************************************
浅拷贝、拷贝构造函数(副本构造函数)：
    我们可以把一个对象赋值给一个类型与之相同的变量，编译器将生产
必要的代码把源对象各属性的值分别赋值给目标对象的对应成员。这种
赋值行为称之为逐位复制，也就是浅拷贝！
    这种行为在绝大多数场合都没有问题，但如果某些成员变量是指针的
话，对象成员逐位复制的结果是你将拥有两个一摸一样的实例，而这两个
副本里的同名指针会指向同一个地址！！这样当删除其中一个对象时，它
包含的指针也会被删除，但不巧另一个对象又引用了这个指针，就会造成
不可预估的后果！！！
    编译器为类指定了一个默认的副本构造函数，我们也可以手动指定副本构
造函数。如果指定了副本构造函数，则进行副本复制时，只会对副本构造函数中指定
的变量进行初始化。
    如果未指定副本构造函数，则进行副本复制时，主体中所有已经初始化的变
量在副本中也同样都会被初始化，初始化的值与主体相同。


解决策略->深拷贝：
    自己编写拷贝构造函数！即可在构造函数里面改写，重新为自己的指针
在堆区开辟一个内存，再将传递的参数值保存即可。这样指针指向的地址就
和传递进来的参数的地址区分开了。


解决策略->赋值运算符重载：赋值运算符 operator=, 对属性进行值拷贝

<返回类型> operator <运算符符号>（<参数>）
{
	<定义>;
}


*********************************************/



class Person
{
public:
    Person(std::string Name, int cnt)
    {
        //将传来的数值拷贝到新建的内存中
        name = new char[cnt];
        Name.copy(name,cnt,0);
    }

    ~Person()
    {
        if(name ==  NULL)
        {
            // do nothing
        }
        else
        {
            std::cout<<"delete name"<<std::endl;
            //如果需要delete的数据类型是数组，需要加[]
            delete [] name;
            name = NULL;
        }
    }

    char* Showname()
    {
        return name;
    }


protected:
    char* name = NULL;

};


int main()
{
    std::string Name;
    int cnt = 0;
    std::cout<<"Please input your name:"<<std::endl;
    std::cin >> Name;
    cnt = Name.length();    //length()求字符串长度

    Person *person1 = new Person(Name,cnt);
    Person person2(person1);

    

    std::cout<<"Person1's name = "<< person1->Showname() <<std::endl;
    delete person1;
    
    std::cout<<"Person2's name = "<< person2.Showname() <<std::endl;
    
    system("pause");
    return 0;
}
