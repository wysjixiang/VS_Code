#include <iostream>
#include <string>
#include <fstream>
#include "Worker.h"

const int addnum = 2;

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
    Worker* GetInfoAddr();
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
    InfoStore = new Worker* [addnum];//ָ����һ��ָ�����飬���������ÿ��Ԫ�ض���Worker��ָ��
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


    Worker *p = NULL;
    while( j <= cnt)
    {   
        std::cout <<"����¼���"<<j<<"λԱ������Ϣ"<<std::endl;
        std::cout <<"ѡ������ 1.��ͨԱ�� 2.���� 3.�ϰ�"<<std::endl;
        std::cin >> choice;
        std::cin.ignore(100, '\n');//Ϊ�˰�����Ļس��������յ���
        caseflag = 0;
        while(!caseflag)
        {
            switch(choice)
            {
                case 1:
                    p = new Employee;
                    p->Modify();
                    caseflag =1;
                    break;
                case 2:
                    p = new Manager;
                    p->Modify();
                    caseflag =1;
                    break;
                case 3:
                    p = new Boss;
                    p->Modify();
                    caseflag =1;
                    break;
                default:
                    std::cin.clear();   //ע�⣡ ������������int���͵���ʵ���������и���������������(��֮��Ȼ)�������ִ���
                                        //��ʱ�������clear()��������cin��״̬��ԭ��
                    std::cin.ignore(100, '\n');//������뻺����
                    std::cout<<"��������ȷ��ѡ��"<<std::endl;
                    std::cin >> choice;
                    std::cin.ignore(100, '\n');//Ϊ�˰�����Ļس��������յ���
                    
                break;
            }
        }

        InfoStore[this->num + j -1] = p; 
        p = NULL;

        j++;
    }
    this->num += cnt; 

    std::cout<<"���Ա����Ϣ��ɣ�"<<std::endl;
    std::cout<<"�ֹ�˾��"<< this->num << "λԱ��" <<std::endl;
    std::cout<<"����ϵͳ�ڴ�����Ϊ:"<< this->rom <<std::endl;
}

void Worksystem::ShowInfo()
{
    if(num == 0)
    {
        std::cout<<"��Ա���������ϰ��޵����ܣ�����"<<std::endl;
    }
    else
    {
        std::cout<<"չʾԱ����Ϣ����:"<<std::endl;
        for(int i=0; i<this->num; i++)
        {
            InfoStore[i]->ShowInfo();
        }

        //����Ա������
        int cnt_e =0;
        int cnt_m = 0;
        int cnt_b = 0;

        for(int i=0; i<this->num; i++)
        {
            if(*(InfoStore[i]->GetZGBH()) == 'E')
            {
                cnt_e +=1;
            }
            else if(*(InfoStore[i]->GetZGBH()) == 'M')
            {
                cnt_m +=1;
            }
            else if(*(InfoStore[i]->GetZGBH()) == 'B'){
                cnt_b +=1;
            }
        }

        std::cout<<"��˾�ֹ��и���Ա��:"<<std::endl;
        std::cout<<"��ͨԱ��: "<< cnt_e <<"λ  "<<"����: "<< cnt_m <<"λ  "<<"�����ϰ�: "<< cnt_b <<"λ  "<<std::endl;
    }

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

Worker* Worksystem::GetInfoAddr()
{
    return (Worker*)this->InfoStore;
}

int Worksystem::Getnum()
{
    return this->num;
}

