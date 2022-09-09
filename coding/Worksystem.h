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
    Worker **InfoStore = NULL;//指向指针的指针
    static int num;
    static int rom;


};
int Worksystem::num =0;
int Worksystem::rom =0;

Worksystem::Worksystem()
{
    InfoStore = new Worker* [addnum];//指向了一个指针数组，这个数组中每个元素都是Worker类指针
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
    std::cout<<"*******   7.清空所有文件   *******"<<std::endl;
    std::cout<<"*******   8.清空终端窗口   *******"<<std::endl;
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


    Worker *p = NULL;
    while( j <= cnt)
    {   
        std::cout <<"现在录入第"<<j<<"位员工的信息"<<std::endl;
        std::cout <<"选择输入 1.普通员工 2.经理 3.老板"<<std::endl;
        std::cin >> choice;
        //std::cin.ignore(100, '\n');//为了把输入的回车符号吸收掉！
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
                    std::cin.clear();   //注意！ 当输入需求是int类型但是实际输入流中给进的是其他类型(反之亦然)，则会出现错误
                                        //此时必须调用clear()将输入流cin的状态复原！
                    std::cin.ignore(100, '\n');//清空输入缓存区
                    std::cout<<"请输入正确的选项"<<std::endl;
                    std::cin >> choice;
                    std::cin.ignore(100, '\n');//为了把输入的回车符号吸收掉！
                    
                break;
            }
        }

        InfoStore[this->num + j -1] = p; 
        p = NULL;

        j++;
    }
    this->num += cnt; 

    std::cout<<"添加员工信息完成！"<<std::endl;
    std::cout<<"现公司有"<< this->num << "位员工" <<std::endl;
    std::cout<<"管理系统内存容量为:"<< this->rom <<std::endl;
}

void Worksystem::ShowInfo()
{
    if(num == 0)
    {
        std::cout<<"无员工，黑心老板无德无能，快润！"<<std::endl;
    }
    else
    {
        std::cout<<"展示员工信息如下:"<<std::endl;
        for(int i=0; i<this->num; i++)
        {
            InfoStore[i]->ShowInfo();
        }

        //各类员工个数
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

        std::cout<<"公司现共有各类员工:"<<std::endl;
        std::cout<<"普通员工: "<< cnt_e <<"位  "<<"经理: "<< cnt_m <<"位  "<<"黑心老板: "<< cnt_b <<"位  "<<std::endl;
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
            std::cout<< "无员工，请让老板先招人！"<<std::endl;
            return ;
        }
        
        std::cout<< "请输入想要删除员工的编号："<<std::endl;
        std::cin >> str_BH;
        std::cout<< "请输入想要删除员工的姓名："<<std::endl;
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
            std::cout<< "删除员工信息完成！"<<std::endl;
        }
        else
        {
            std::cout<< "查无此人！"<<std::endl;
            std::cout<< "请检查离职员工信息是否如下："<<std::endl;
            std::cout<< "职工编号： "<< str_BH << "  姓名：" << str_NAME << std::endl;
        }

        while(1)
        {
        std::cout<< "继续删除员工操作？ Y/N"<<std::endl;
        std::cin >> choice;
        if(choice == 'Y' || choice == 'y' )
        {
            break;
        }
        else if(choice == 'N'|| choice == 'n')
        {
            std::cout<< "退出删除系统"<<std::endl;
            return ;
        }
        else
        {
            std::cout<< "请输入正确的选项！"<<std::endl;
        }

        }



    }
}

void Worksystem::ModifyInfo()
{

    if(this->num ==0)
    {
        std::cout<< "无员工，请让老板先招人！"<<std::endl;
        return ;
    }

    std::string BH;
    int Mod_flag = 0;
    char choice;
    std::cout<< "进入员工信息修改系统..."<<std::endl;
    std::cout<< "请输入员工编号"<<std::endl;
    std::cin >> BH;

    while(1)
    {
        Mod_flag = 0;
        for(int i=0;i< this->num; i++)
        {
            if( InfoStore[i]->GetZGBH() == BH )
            {
                Mod_flag =1;
                std::cout<< "原职工信息如下:"<<std::endl;
                InfoStore[i]->ShowInfo();
                InfoStore[i]->Modify();
                break;
            }
        }

        if(Mod_flag)
        {
            std::cout<< "职工信息修改完成！"<<std::endl;
        }
        else
        {
            std::cout<< "查无此人！"<<std::endl;
            std::cout<< "请检查员工编号是否填写正确！"<<std::endl;
        }

        while(1)
        {
            std::cout<< "继续修改职工信息操作？ Y/N"<<std::endl;
            std::cin >> choice;
            if(choice == 'Y' || choice == 'y' )
            {
                break;
            }
            else if(choice == 'N'|| choice == 'n')
            {
                std::cout<< "退出员工信息修改系统..."<<std::endl;
                return ;
            }
            else
            {
                std::cout<< "请输入正确的选项！"<<std::endl;
            }

        }


    }


}

void Worksystem::FindInfo()
{
    if(this->num ==0)
    {
        std::cout<< "无员工，请让老板先招人！"<<std::endl;
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

    std::cout<< "进入员工检索系统..."<<std::endl;
    while(1)
    {
        std::cout<< "请按照员工编号,姓名,部门的格式输入,未知项请填写UK"<<std::endl;
        i=0;
        j=0;
        find_flag = 0;
        //读取输入，并且将编号，姓名，部门都存起来
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

        //寻找匹配
        for(i=0; i< this->num; i++)
        {
            constrain = 1;
            //if( bh == "UK" || bh == "uk" )
            // strcmp比较函数，如果两个字符串相同，返回0
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
            std::cout<<"查无此人！请收窄搜索限制条件！"<<std::endl;
        }
        else
        {
            std::cout<<"本次员工信息检索完毕！"<<std::endl;
        }

        while(1)
        {
            std::cout<< "继续检索员工信息？ Y/N"<<std::endl;
            std::cin >> choice;
            if(choice == 'Y' || choice == 'y' )
            {
                break;
            }
            else if(choice == 'N'|| choice == 'n')
            {
                std::cout<< "退出员工检索系统..."<<std::endl;
                return ;
            }
            else
            {
                std::cout<< "请输入正确的选项！"<<std::endl;
                std::cin.ignore(100, '\n');//为了把输入的回车符号吸收掉！
            }

        }

    }


}


void Worksystem::SortInfo()
{
    std::cout<<"正在开发中...敬请期待"<<std::endl;
}

void Worksystem::ClearInfo()
{
    if(this->num == 0)
    {
        std::cout<<"无员工数据，请黑心老板先招人!"<<std::endl;
        return ;
    }

    std::cout<<"进入员工信息清除系统..."<<std::endl;
    char choice;
    while(1)
    {   
        std::cout<< "确定要删除所有员工数据吗? Y/N"<<std::endl;
        std::cin >> choice;
        if(choice == 'Y' || choice == 'y' )
        {
            //删除所有的指针数组里存放的数据
            for(int i=0;i<this->num;i++)
            {
                if(InfoStore[i] != NULL)
                {
                    delete InfoStore[i];
                    InfoStore[i] == NULL;
                }
            }
            //将InforStore指针也释放掉，重建一个只有初始空间的内存
            delete [] InfoStore;
            InfoStore = NULL;
            InfoStore = new Worker* [addnum];
            this->num = 0;
            this->rom = addnum;
            std::cout<<"已经删库，请准备提桶跑路吧！"<<std::endl;
            return ;
        }
        else if(choice == 'N'|| choice == 'n')
        {
            std::cout<< "退出员工信息清除系统..."<<std::endl;
            return ;
        }
        else
        {
            std::cout<< "请输入正确的选项！"<<std::endl;
            std::cin.ignore(100, '\n');//为了把输入的回车符号吸收掉！
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

