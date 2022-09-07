#include <iostream>
#include <string>
#include <fstream>



class Worksystem
{
public:
    void Menu();
    void Exit();
    void AddInfo();
    void ShowInfo();
    void DeleteInfo();
    void ModifyInfo();
    void FindInfo();
    void SortInfo();
    void ClearInfo();

};

void Worksystem::Menu()
{
    std::cout<<"*********************************"<<std::endl;
    std::cout<<"*******��ӭʹ��ְ������ϵͳ��******"<<std::endl;
    std::cout<<"*******   0.�˳��������   *******"<<std::endl;
    std::cout<<"*******   1.����ְ����Ϣ   *******"<<std::endl;
    std::cout<<"*******   2.��ʾְ����Ϣ   *******"<<std::endl;
    std::cout<<"*******   3.ɾ����ְְ��   *******"<<std::endl;
    std::cout<<"*******   4.�޸�ְ����Ϣ   *******"<<std::endl;
    std::cout<<"*******   5.����ְ����Ϣ   *******"<<std::endl;
    std::cout<<"*******   6.���ձ������   *******"<<std::endl;
    std::cout<<"*******   7.��������ĵ�   *******"<<std::endl;
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


class Worker
{
public:
    virtual void ShowInfo() = 0;
    virtual void Modify() = 0;
    virtual char* GetZGBH() =0;
    virtual char* GetNAME() =0;
    virtual char* GetBMBH() =0;
    virtual char* GetGZNR() =0;


    char ZGBH[32] = {0};
    char NAME[32] = {0};
    char BMBH[32] = {0};
    char GZNR[32] = {"�����ϰ壡"};

};

class Employee: public Worker
{
public:
    void ShowInfo();
    void Modify();
    char* GetZGBH();
    char* GetNAME();
    char* GetBMBH();
    char* GetGZNR();

};

void Employee::ShowInfo()
{
    std::cout<< "ְ����ţ� " <<this->ZGBH << "  ";
    std::cout<< "ְ������:  "<<this->NAME << "  ";
    std::cout<< "���ű��:  "<<this->BMBH << "  ";
    std::cout<< "�������ݣ�  "<<this->GZNR << std::endl;
}

void Employee::Modify()
{
    std::cout<<"�������޸ĺ�Ա����ְ����š����������ű�ţ�"<<
    "���� �������Ÿ������س���β��"<<std::endl;
    int i=0;
    char str;
    //std::cin.get();
    std::cin.ignore(10, '\n');
    while( (str = std::cin.get()) != '\n' && str != EOF)
    {
        i=0;
        while(str != ',')
        {
            this->ZGBH[i++] = str;
            str = std::cin.get();
        }
        this->ZGBH[i] = '\0';
        i=0;
        while((str = std::cin.get()) != ',')
        {
            this->NAME[i++] = str; 
        }
        this->NAME[i] = '\0';
        i=0;
        while((str = std::cin.get()) != '\n')
        {
            this->BMBH[i++] = str;
        }
        this->BMBH[i] = '\0';
        break;
    }

}

char* Employee::GetZGBH()
{
    return this->ZGBH;
}


char* Employee::GetNAME()
{
    return this->NAME;
}

char* Employee::GetBMBH()
{
    return this->BMBH;
}

char* Employee::GetGZNR()
{
    return this->GZNR;
}


class Manager: public Worker
{
public:

    char GZNR[32] = {"������ϰ壡"};
    void ShowInfo();
    void Modify();
    char* GetZGBH();
    char* GetNAME();
    char* GetBMBH();
    char* GetGZNR();

};

void Manager::ShowInfo()
{
    std::cout<< "ְ����ţ� " <<this->ZGBH << "  ";
    std::cout<< "ְ������:  "<<this->NAME << "  ";
    std::cout<< "���ű��:  "<<this->BMBH << "  ";
    std::cout<< "�������ݣ�  "<<this->GZNR << std::endl;
}


void Manager::Modify()
{
    std::cout<<"�������޸ĺ����ְ����š����������ű�ţ�"<<
    "���� �������Ÿ������س���β��"<<std::endl;
    int i=0;
    char str;
    //std::cin.get();
    std::cin.ignore(10, '\n');
    while( (str = std::cin.get()) != '\n' && str != EOF)
    {
        i=0;
        while(str != ',')
        {
            this->ZGBH[i++] = str;
            str = std::cin.get();
        }
        this->ZGBH[i] = '\0';
        i=0;
        while((str = std::cin.get()) != ',')
        {
            this->NAME[i++] = str; 
        }
        this->NAME[i] = '\0';
        i=0;
        while((str = std::cin.get()) != '\n')
        {
            this->BMBH[i++] = str;
        }
        this->BMBH[i] = '\0';
        break;
    }

}

char* Manager::GetZGBH()
{
    return this->ZGBH;
}


char* Manager::GetNAME()
{
    return this->NAME;
}

char* Manager::GetBMBH()
{
    return this->BMBH;
}

char* Manager::GetGZNR()
{
    return this->GZNR;
}



class Boss: public Worker
{
public:

    char GZNR[32] = {"������ϰ壡"};
    void ShowInfo();
    void Modify();
    char* GetZGBH();
    char* GetNAME();
    char* GetBMBH();
    char* GetGZNR();

};

void Boss::ShowInfo()
{
    std::cout<< "ְ����ţ� " <<this->ZGBH << "  ";
    std::cout<< "ְ������:  "<<this->NAME << "  ";
    std::cout<< "���ű��:  "<<this->BMBH << "  ";
    std::cout<< "�������ݣ�  "<<this->GZNR << std::endl;
}


void Boss::Modify()
{
    std::cout<<"�������޸ĺ��ϰ��ְ����š����������ű�ţ�"<<
    "���� �������Ÿ������س���β��"<<std::endl;
    int i=0;
    char str;
    //std::cin.get();
    std::cin.ignore(10, '\n');
    while( (str = std::cin.get()) != '\n' && str != EOF)
    {
        i=0;
        while(str != ',')
        {
            this->ZGBH[i++] = str;
            str = std::cin.get();
        }
        this->ZGBH[i] = '\0';
        i=0;
        while((str = std::cin.get()) != ',')
        {
            this->NAME[i++] = str; 
        }
        this->NAME[i] = '\0';
        i=0;
        while((str = std::cin.get()) != '\n')
        {
            this->BMBH[i++] = str;
        }
        this->BMBH[i] = '\0';
        break;
    }

}

char* Boss::GetZGBH()
{
    return this->ZGBH;
}


char* Boss::GetNAME()
{
    return this->NAME;
}

char* Boss::GetBMBH()
{
    return this->BMBH;
}

char* Boss::GetGZNR()
{
    return this->GZNR;
}



int main()
{
    int choice= -1;

    Worksystem ComSystem;
    Employee employee1;
    Manager manager1;
    Boss boss1;



    while(1)
    {
        ComSystem.Menu();
        std::cout<<"����������ѡ��"<<std::endl;
        std::cin >> choice;
        switch(choice)
        {
		case 0: //�˳�ϵͳ
            ComSystem.Exit();

			break;
		case 1: //���ְ��


			break;
		case 2: //��ʾְ��


			break;
		case 3: //ɾ��ְ��


			break;
		case 4: //�޸�ְ��
            employee1.Modify();
            manager1.Modify();
            boss1.Modify();
            std::cout<< employee1.GetZGBH() << std::endl;
            std::cout<< employee1.NAME << std::endl;
            std::cout<< employee1.BMBH << std::endl;
            std::cout<< employee1.GZNR << std::endl;

            std::cout<< manager1.GetZGBH() << std::endl;
            std::cout<< manager1.NAME << std::endl;
            std::cout<< manager1.BMBH << std::endl;
            std::cout<< manager1.GZNR << std::endl;

            std::cout<< boss1.GetZGBH() << std::endl;
            std::cout<< boss1.NAME << std::endl;
            std::cout<< boss1.BMBH << std::endl;
            std::cout<< boss1.GZNR << std::endl;
			break;
		case 5: //����ְ��
			break;
		case 6: //����ְ��
			break;
		case 7: //����ļ�
			break;
		default:
			system("cls");
			break;


        }


    }


    
    

    system("pause");
    return 0;
}