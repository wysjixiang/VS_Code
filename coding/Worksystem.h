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
    Worker **InfoStore = NULL;//ָ��ָ���ָ��
    static int num;
    static int rom;


};
int Worksystem::num =0;
int Worksystem::rom =0;

Worksystem::Worksystem()
{
    InfoStore = new Worker* [addnum];//ָ����һ��������ָ��
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
    std::cout<<"*******��ӭʹ��ְ������ϵͳ  ******"<<std::endl;
    std::cout<<"*******   0.�˳��������?   *******"<<std::endl;
    std::cout<<"*******   1.����ְ����Ϣ   *******"<<std::endl;
    std::cout<<"*******   2.��ʾְ����Ϣ   *******"<<std::endl;
    std::cout<<"*******   3.ɾ����ְְ��   *******"<<std::endl;
    std::cout<<"*******   4.�޸�ְ����Ϣ   *******"<<std::endl;
    std::cout<<"*******   5.����ְ����Ϣ   *******"<<std::endl;
    std::cout<<"*******   6.���ձ������   *******"<<std::endl;
    std::cout<<"*******   7.��������ļ�?   *******"<<std::endl;
    std::cout<<"*********************************"<<std::endl;

}

void Worksystem::Exit()
{
    std::cout<< "��ӭ���´�ʹ�ã�"<<std::endl;
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

    std::cout<< "��������Ҫ���Ա���ĸ�����"<<std::endl;
    std::cin >> cnt;

    //����ռ䲻��������ռ�
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

        std::cout<<"�ռ䲻�㣬�Ѿ����ݣ�"<<std::endl;
    }

    while( j <= cnt)
    {   

        std::cout <<"����¼���"<<j<<"λԱ������Ϣ"<<std::endl;
        std::cout <<"ѡ������ 1.��ͨԱ�� 2.���� 3.�ϰ�"<<std::endl;
        std::cin >> choice;
        std::cin.ignore(10, '\n');//Ϊ�˰�����Ļس��������յ���
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
                    std::cout<<"��������ȷ��ѡ��"<<std::endl;
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

