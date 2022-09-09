#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
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
    std::cout<<"*******   7.��������ļ�   *******"<<std::endl;
    std::cout<<"*******   8.����ն˴���   *******"<<std::endl;
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
        //std::cin.ignore(100, '\n');//Ϊ�˰�����Ļس��������յ���
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
    std::string str_BH,str_NAME;
    char choice = '0';
    int delete_flag = 0;
    while(1)
    {
        delete_flag = 0;
        if(this-> num == 0)
        {
            std::cout<< "��Ա���������ϰ������ˣ�"<<std::endl;
            return ;
        }
        
        std::cout<< "��������Ҫɾ��Ա���ı�ţ�"<<std::endl;
        std::cin >> str_BH;
        std::cout<< "��������Ҫɾ��Ա����������"<<std::endl;
        std::cin >> str_NAME;

        for(int i=0;i< this->num; i++)
        {
            if( (InfoStore[i]->GetZGBH() == str_BH) &&
            (InfoStore[i]->GetNAME() == str_NAME))
            {
                delete_flag = 1;
                delete InfoStore[i];
                InfoStore[i] = InfoStore[this->num -1];
                InfoStore[this->num -1] = NULL;
                this-> num -=1;
                break;
            }
        }

        if(delete_flag)
        {
            std::cout<< "ɾ��Ա����Ϣ��ɣ�"<<std::endl;
        }
        else
        {
            std::cout<< "���޴��ˣ�"<<std::endl;
            std::cout<< "������ְԱ����Ϣ�Ƿ����£�"<<std::endl;
            std::cout<< "ְ����ţ� "<< str_BH << "  ������" << str_NAME << std::endl;
        }

        while(1)
        {
        std::cout<< "����ɾ��Ա�������� Y/N"<<std::endl;
        std::cin >> choice;
        if(choice == 'Y' || choice == 'y' )
        {
            break;
        }
        else if(choice == 'N'|| choice == 'n')
        {
            std::cout<< "�˳�ɾ��ϵͳ"<<std::endl;
            return ;
        }
        else
        {
            std::cout<< "��������ȷ��ѡ�"<<std::endl;
        }

        }



    }
}

void Worksystem::ModifyInfo()
{

    if(this->num ==0)
    {
        std::cout<< "��Ա���������ϰ������ˣ�"<<std::endl;
        return ;
    }

    std::string BH;
    int Mod_flag = 0;
    char choice;
    std::cout<< "����Ա����Ϣ�޸�ϵͳ..."<<std::endl;
    std::cout<< "������Ա�����"<<std::endl;
    std::cin >> BH;

    while(1)
    {
        Mod_flag = 0;
        for(int i=0;i< this->num; i++)
        {
            if( InfoStore[i]->GetZGBH() == BH )
            {
                Mod_flag =1;
                std::cout<< "ԭְ����Ϣ����:"<<std::endl;
                InfoStore[i]->ShowInfo();
                InfoStore[i]->Modify();
                break;
            }
        }

        if(Mod_flag)
        {
            std::cout<< "ְ����Ϣ�޸���ɣ�"<<std::endl;
        }
        else
        {
            std::cout<< "���޴��ˣ�"<<std::endl;
            std::cout<< "����Ա������Ƿ���д��ȷ��"<<std::endl;
        }

        while(1)
        {
            std::cout<< "�����޸�ְ����Ϣ������ Y/N"<<std::endl;
            std::cin >> choice;
            if(choice == 'Y' || choice == 'y' )
            {
                break;
            }
            else if(choice == 'N'|| choice == 'n')
            {
                std::cout<< "�˳�Ա����Ϣ�޸�ϵͳ..."<<std::endl;
                return ;
            }
            else
            {
                std::cout<< "��������ȷ��ѡ�"<<std::endl;
            }

        }


    }


}

void Worksystem::FindInfo()
{
    if(this->num ==0)
    {
        std::cout<< "��Ա���������ϰ������ˣ�"<<std::endl;
        return ;
    }


    int i=0;
    int j=0;
    std::string str;
    char bh[32];
    char name[32];
    char bm[32];

    int find_flag = 0;
    int constrain = 1;
    char choice;

    std::cout<< "����Ա������ϵͳ..."<<std::endl;
    while(1)
    {
        std::cout<< "�밴��Ա�����,����,���ŵĸ�ʽ����,δ֪������дUK"<<std::endl;
        i=0;
        j=0;
        find_flag = 0;
        //��ȡ���룬���ҽ���ţ����������Ŷ�������
        std::cin >> str;
        while(str[i] != ',')
        {
            bh[j++] = str[i++];
        }
        i++;
        bh[j] = '\0';
        j=0;

        while(str[i] != ',')
        {
            name[j++] = str[i++];
        }
        i++;
        name[j] = '\0';
        j=0;

        while(str[i] != '\0')
        {
            bm[j++] = str[i++];
        }
        bm[j] = '\0';

        //Ѱ��ƥ��
        for(i=0; i< this->num; i++)
        {
            constrain = 1;
            //if( bh == "UK" || bh == "uk" )
            // strcmp�ȽϺ�������������ַ�����ͬ������0
            if(!(strcmp(bh,"UK") & strcmp(bh,"uk")))    
            {
                ;
            }
            else
            {
                if(!strcmp(InfoStore[i]->GetZGBH(),bh))
                {
                    ;
                }
                else
                {
                    constrain =0;
                }
            }


            if(!(strcmp(name,"UK") & strcmp(name,"uk"))) 
            {
                ;
            }
            else
            {
                if(!strcmp(InfoStore[i]->GetNAME(),name))
                {
                    ;
                }
                else
                {
                    constrain =0;
                }
            }

            if(!(strcmp(bm,"UK") & strcmp(bm,"uk"))) 
            {
                ;
            }
            else
            {
                if(!strcmp(InfoStore[i]->GetBMBH(),bm))
                {
                    ;
                }
                else
                {
                    constrain =0;
                }
            }

            if(constrain == 1)
            {
                InfoStore[i]->ShowInfo();
                find_flag =1;
            }

        }

        if(!find_flag)
        {
            std::cout<<"���޴��ˣ�����խ��������������"<<std::endl;
        }
        else
        {
            std::cout<<"����Ա����Ϣ������ϣ�"<<std::endl;
        }

        while(1)
        {
            std::cout<< "��������Ա����Ϣ�� Y/N"<<std::endl;
            std::cin >> choice;
            if(choice == 'Y' || choice == 'y' )
            {
                break;
            }
            else if(choice == 'N'|| choice == 'n')
            {
                std::cout<< "�˳�Ա������ϵͳ..."<<std::endl;
                return ;
            }
            else
            {
                std::cout<< "��������ȷ��ѡ�"<<std::endl;
                std::cin.ignore(100, '\n');//Ϊ�˰�����Ļس��������յ���
            }

        }

    }


}


void Worksystem::SortInfo()
{
    std::cout<<"���ڿ�����...�����ڴ�"<<std::endl;
}

void Worksystem::ClearInfo()
{
    if(this->num == 0)
    {
        std::cout<<"��Ա�����ݣ�������ϰ�������!"<<std::endl;
        return ;
    }

    std::cout<<"����Ա����Ϣ���ϵͳ..."<<std::endl;
    char choice;
    while(1)
    {   
        std::cout<< "ȷ��Ҫɾ������Ա��������? Y/N"<<std::endl;
        std::cin >> choice;
        if(choice == 'Y' || choice == 'y' )
        {
            //ɾ�����е�ָ���������ŵ�����
            for(int i=0;i<this->num;i++)
            {
                if(InfoStore[i] != NULL)
                {
                    delete InfoStore[i];
                    InfoStore[i] == NULL;
                }
            }
            //��InforStoreָ��Ҳ�ͷŵ����ؽ�һ��ֻ�г�ʼ�ռ���ڴ�
            delete [] InfoStore;
            InfoStore = NULL;
            InfoStore = new Worker* [addnum];
            this->num = 0;
            this->rom = addnum;
            std::cout<<"�Ѿ�ɾ�⣬��׼����Ͱ��·�ɣ�"<<std::endl;
            return ;
        }
        else if(choice == 'N'|| choice == 'n')
        {
            std::cout<< "�˳�Ա����Ϣ���ϵͳ..."<<std::endl;
            return ;
        }
        else
        {
            std::cout<< "��������ȷ��ѡ�"<<std::endl;
            std::cin.ignore(100, '\n');//Ϊ�˰�����Ļس��������յ���
        }

    }

}

Worker* Worksystem::GetInfoAddr()
{
    return (Worker*)this->InfoStore;
}

int Worksystem::Getnum()
{
    return this->num;
}

