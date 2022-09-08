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
    char GZNR[32] = {"跪舔经理&老板！"};

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
    char GZNR[32] = {"跪舔经理！"};


};

void Employee::ShowInfo()
{
    std::cout<< "职工编号： " <<this->ZGBH << "  ";
    std::cout<< "职工姓名:  "<<this->NAME << "      ";
    std::cout<< "部门编号:  "<<this->BMBH << "  ";
    std::cout<< "工作内容：  "<<this->GZNR << std::endl;
}

void Employee::Modify()
{
    std::cout<<"请输入员工的职工编号、姓名、部门编号，工作内容"<<
    "并以 ‘，’号隔开，回车结尾！"<<std::endl;
    int i=0;
    char str;
    std::cin.ignore(100, '\n');//为了把输入的回车符号吸收掉！
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
    char GZNR[32] = {"跪舔大老板！"};
};

void Manager::ShowInfo()
{
    std::cout<< "职工编号： " <<this->ZGBH << "  ";
    std::cout<< "职工姓名:  "<<this->NAME << "      ";
    std::cout<< "部门编号:  "<<this->BMBH << "  ";
    std::cout<< "工作内容：  "<<this->GZNR << std::endl;
}


void Manager::Modify()
{
    std::cout<<"请输入员工的职工编号、姓名、部门编号，工作内容"<<
    "并以 ‘，’号隔开，回车结尾！"<<std::endl;
    int i=0;
    char str;
    std::cin.ignore(100, '\n');//为了把输入的回车符号吸收掉！
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
    char GZNR[32] = {"压榨员工！"};
};

void Boss::ShowInfo()
{
    std::cout<< "职工编号： " <<this->ZGBH << "  ";
    std::cout<< "职工姓名:  "<<this->NAME << "      ";
    std::cout<< "部门编号:  "<<this->BMBH << "  ";
    std::cout<< "工作内容：  "<<this->GZNR << std::endl;
}


void Boss::Modify()
{
    std::cout<<"请输入员工的职工编号、姓名、部门编号，工作内容"<<
    "并以 ‘，’号隔开，回车结尾！"<<std::endl;
    int i=0;
    char str;
    std::cin.ignore(100, '\n');//为了把输入的回车符号吸收掉！
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