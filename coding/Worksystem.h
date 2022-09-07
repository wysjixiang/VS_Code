#include <iostream>
#include <string>
#include <fstream>
#include "Worker.h"

const int addnum = 10;

class Worksystem
{
public:
    Worksystem();
    ~Worksystem();

    void Menu();
    void Exit();
    void AddInfo();
    void ShowInfo();
    void DeleteInfo();
    void ModifyInfo();
    void FindInfo();
    void SortInfo();
    void ClearInfo();
    int* GetInfoAddr();
    int Getnum();
    int Getrom();

protected:
    Worker **InfoStore = NULL;//指向指针的指针
    static int num;
    static int rom;


};
int Worksystem::num =0;
int Worksystem::rom =0;

Worksystem::Worksystem()
{
    InfoStore = new Worker* [addnum];//指向了一个类数组指针
    num = 0;
    rom = addnum;
}

Worksystem::~Worksystem()
{
    delete [] InfoStore;
    InfoStore = NULL;
}

void Worksystem::Menu()
{
    std::cout<<"*********************************"<<std::endl;
    std::cout<<"*******欢迎使用职工管理系统  ******"<<std::endl;
    std::cout<<"*******   0.退出管理程序?   *******"<<std::endl;
    std::cout<<"*******   1.增加职工信息   *******"<<std::endl;
    std::cout<<"*******   2.显示职工信息   *******"<<std::endl;
    std::cout<<"*******   3.删除离职职工   *******"<<std::endl;
    std::cout<<"*******   4.修改职工信息   *******"<<std::endl;
    std::cout<<"*******   5.查找职工信息   *******"<<std::endl;
    std::cout<<"*******   6.按照编号排序   *******"<<std::endl;
    std::cout<<"*******   7.清空所有文件?   *******"<<std::endl;
    std::cout<<"*********************************"<<std::endl;

}

void Worksystem::Exit()
{
    std::cout<< "欢迎您下次使用！"<<std::endl;
    system("pause");
    exit(0);

}

void Worksystem::AddInfo()
{   
    int cnt;
    int j=1;
    int addcnt =0;
    int choice;
    int caseflag = 0;

    std::cout<< "请输入您要添加员工的个数："<<std::endl;
    std::cin >> cnt;

    //如果空间不够，扩大空间
    if( this->rom <  (this->num + cnt))
    {
        while( this->rom +addcnt <= (this->num + cnt))
        {
            addcnt += addnum;
        }

        Worker **newspace = new Worker* [this->rom + addcnt];
        for(int k=0; k< this->num; k++)
        {
            newspace[k] = this->InfoStore[k];
        }
        for(int k = this->num; k< this->rom;k++)
        {
            newspace[k] = NULL;
        }

        delete [] this->InfoStore;
        this->InfoStore = newspace;
        this->rom += addcnt;

        std::cout<<"空间不足，已经扩容！"<<std::endl;
    }

    while( j <= cnt)
    {   

        std::cout <<"现在录入第"<<j<<"位员工的信息"<<std::endl;
        std::cout <<"选择输入 1.普通员工 2.经理 3.老板"<<std::endl;
        std::cin >> choice;
        std::cin.ignore(10, '\n');//为了把输入的回车符号吸收掉！
        caseflag = 0;
        while(!caseflag)
        {
            switch(choice)
            {
                case 1:
                    Employee *p = new Employee;
                    p->Modify();
                    caseflag =1;
                    break;
                case 2:
                    Manager *p = new Manager;
                    p->Modify();
                    caseflag =1;
                    break;
                case 3:
                    Boss *p = new Boss;
                    p->Modify();
                    caseflag =1;
                    break;
                default:
                    std::cout<<"请输入正确的选项"<<std::endl;
                break;

            }
        }

        InfoStore[this->num + j -1] = p->Getptr();



        
            

        j++;
    }
    



}

void Worksystem::ShowInfo()
{
    
}


void Worksystem::DeleteInfo()
{
    
}

void Worksystem::ModifyInfo()
{
    
}

void Worksystem::FindInfo()
{
    
}


void Worksystem::SortInfo()
{
    
}

void Worksystem::ClearInfo()
{
    
}

int* Worksystem::GetInfoAddr()
{
    return this->InfoStore;
}

int Worksystem::Getnum()
{
    return this->num;
}

