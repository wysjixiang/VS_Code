#include <iostream>

//友元关系 -如何申明友元

class lover
{
public:
    

    lover(std::string name)
    {
        this->name = name;
    }

private:
    std::string name;
    friend class others;    //如果没有这个友元申明，是无法访问的！
    //另外，如果类中的属性未非public，则无法通过classname.属性的
    //方式访问，如lover.name。private提供了对数据的封装，使得
    //private成员只能被类自身的成员函数以及类的友元访问，其他的
    //函数或者类想要访问private成员只能通过该类所提供的set和get的
    //方法进行访问
};


class others
{
public:
    void kiss(lover* lover)
    {
        std::cout<<"Kiss "<< lover->name <<std::endl;
    }

};


int main()
{
    lover girl("piggy");
    others badguy;
    badguy.kiss(&girl);

    system("pause");
    return 0;
}
