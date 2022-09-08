#include <iostream>
#include <string>
#include <fstream>

class Worker
{
public:
    virtual void ShowInfo() = 0;
    virtual void Modify() = 0;
    virtual Worker* Getptr() = 0;
    virtual char* GetZGBH() =0;
    virtual char* GetNAME() =0;
    virtual char* GetBMBH() =0;
    virtual char* GetGZNR() =0;

protected:
    char ZGBH[32] = {0};
    char NAME[32] = {0};
    char BMBH[32] = {0};
    char GZNR[32] = {"������&�ϰ壡"};

};

class Employee: public Worker
{
public:
    void ShowInfo();
    void Modify();
    virtual Worker* Getptr();
    char* GetZGBH();
    char* GetNAME();
    char* GetBMBH();
    char* GetGZNR();

protected:
    char GZNR[32] = {"������"};


};

void Employee::ShowInfo()
{
    std::cout<< "ְ����ţ� " <<this->ZGBH << "  ";
    std::cout<< "ְ������:  "<<this->NAME << "      ";
    std::cout<< "���ű��:  "<<this->BMBH << "  ";
    std::cout<< "�������ݣ�  "<<this->GZNR << std::endl;
}

void Employee::Modify()
{
    std::cout<<"������Ա����ְ����š����������ű�ţ���������"<<
    "���� �������Ÿ������س���β��"<<std::endl;
    int i=0;
    char str;
    std::cin.ignore(100, '\n');//Ϊ�˰�����Ļس��������յ���
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
        while((str = std::cin.get()) != ',')
        {
            this->BMBH[i++] = str;
        }
        this->BMBH[i] = '\0';
        i=0;
        while((str = std::cin.get()) != '\n')
        {
            this->GZNR[i++] = str;
        }
        this->GZNR[i] = '\0';
        break;
    }

}
Worker* Employee::Getptr()
{
    return this;
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

    void ShowInfo();
    void Modify();
    virtual Worker* Getptr();
    char* GetZGBH();
    char* GetNAME();
    char* GetBMBH();
    char* GetGZNR();
protected:
    char GZNR[32] = {"������ϰ壡"};
};

void Manager::ShowInfo()
{
    std::cout<< "ְ����ţ� " <<this->ZGBH << "  ";
    std::cout<< "ְ������:  "<<this->NAME << "      ";
    std::cout<< "���ű��:  "<<this->BMBH << "  ";
    std::cout<< "�������ݣ�  "<<this->GZNR << std::endl;
}


void Manager::Modify()
{
    std::cout<<"������Ա����ְ����š����������ű�ţ���������"<<
    "���� �������Ÿ������س���β��"<<std::endl;
    int i=0;
    char str;
    std::cin.ignore(100, '\n');//Ϊ�˰�����Ļس��������յ���
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
        while((str = std::cin.get()) != ',')
        {
            this->BMBH[i++] = str;
        }
        this->BMBH[i] = '\0';
        i=0;
        while((str = std::cin.get()) != '\n')
        {
            this->GZNR[i++] = str;
        }
        this->GZNR[i] = '\0';
        break;
    }

}

Worker* Manager::Getptr()
{
    return this;
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

    void ShowInfo();
    void Modify();
    virtual Worker* Getptr();
    char* GetZGBH();
    char* GetNAME();
    char* GetBMBH();
    char* GetGZNR();
protected:
    char GZNR[32] = {"ѹեԱ����"};
};

void Boss::ShowInfo()
{
    std::cout<< "ְ����ţ� " <<this->ZGBH << "  ";
    std::cout<< "ְ������:  "<<this->NAME << "      ";
    std::cout<< "���ű��:  "<<this->BMBH << "  ";
    std::cout<< "�������ݣ�  "<<this->GZNR << std::endl;
}


void Boss::Modify()
{
    std::cout<<"������Ա����ְ����š����������ű�ţ���������"<<
    "���� �������Ÿ������س���β��"<<std::endl;
    int i=0;
    char str;
    std::cin.ignore(100, '\n');//Ϊ�˰�����Ļس��������յ���
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
        while((str = std::cin.get()) != ',')
        {
            this->BMBH[i++] = str;
        }
        this->BMBH[i] = '\0';
        i=0;
        while((str = std::cin.get()) != '\n')
        {
            this->GZNR[i++] = str;
        }
        this->GZNR[i] = '\0';
        break;
    }

}

Worker* Boss::Getptr()
{
    return this;
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