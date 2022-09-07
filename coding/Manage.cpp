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
    std::cout<<"*******欢迎使用职工管理系统！******"<<std::endl;
    std::cout<<"*******   0.退出管理程序   *******"<<std::endl;
    std::cout<<"*******   1.增加职工信息   *******"<<std::endl;
    std::cout<<"*******   2.显示职工信息   *******"<<std::endl;
    std::cout<<"*******   3.删除离职职工   *******"<<std::endl;
    std::cout<<"*******   4.修改职工信息   *******"<<std::endl;
    std::cout<<"*******   5.查找职工信息   *******"<<std::endl;
    std::cout<<"*******   6.按照编号排序   *******"<<std::endl;
    std::cout<<"*******   7.清空所有文档   *******"<<std::endl;
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
    char GZNR[32] = {"跪舔老板！"};

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
    std::cout<< "职工编号： " <<this->ZGBH << "  ";
    std::cout<< "职工姓名:  "<<this->NAME << "  ";
    std::cout<< "部门编号:  "<<this->BMBH << "  ";
    std::cout<< "工作内容：  "<<this->GZNR << std::endl;
}

void Employee::Modify()
{
    std::cout<<"请输入修改后员工的职工编号、姓名、部门编号，"<<
    "并以 ‘，’号隔开，回车结尾！"<<std::endl;
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

    char GZNR[32] = {"跪舔大老板！"};
    void ShowInfo();
    void Modify();
    char* GetZGBH();
    char* GetNAME();
    char* GetBMBH();
    char* GetGZNR();

};

void Manager::ShowInfo()
{
    std::cout<< "职工编号： " <<this->ZGBH << "  ";
    std::cout<< "职工姓名:  "<<this->NAME << "  ";
    std::cout<< "部门编号:  "<<this->BMBH << "  ";
    std::cout<< "工作内容：  "<<this->GZNR << std::endl;
}


void Manager::Modify()
{
    std::cout<<"请输入修改后经理的职工编号、姓名、部门编号，"<<
    "并以 ‘，’号隔开，回车结尾！"<<std::endl;
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

    char GZNR[32] = {"跪舔大老板！"};
    void ShowInfo();
    void Modify();
    char* GetZGBH();
    char* GetNAME();
    char* GetBMBH();
    char* GetGZNR();

};

void Boss::ShowInfo()
{
    std::cout<< "职工编号： " <<this->ZGBH << "  ";
    std::cout<< "职工姓名:  "<<this->NAME << "  ";
    std::cout<< "部门编号:  "<<this->BMBH << "  ";
    std::cout<< "工作内容：  "<<this->GZNR << std::endl;
}


void Boss::Modify()
{
    std::cout<<"请输入修改后老板的职工编号、姓名、部门编号，"<<
    "并以 ‘，’号隔开，回车结尾！"<<std::endl;
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
        std::cout<<"请输入您的选择："<<std::endl;
        std::cin >> choice;
        switch(choice)
        {
		case 0: //退出系统
            ComSystem.Exit();

			break;
		case 1: //添加职工


			break;
		case 2: //显示职工


			break;
		case 3: //删除职工


			break;
		case 4: //修改职工
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
		case 5: //查找职工
			break;
		case 6: //排序职工
			break;
		case 7: //清空文件
			break;
		default:
			system("cls");
			break;


        }


    }


    
    

    system("pause");
    return 0;
}