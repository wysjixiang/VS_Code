#include <iostream>
#include <string>
#include <fstream>



class Worksystem
{
public:
    void Menu();
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




int main()
{

    Worksystem ComSystem;
    ComSystem.Menu();

    system("pause");
    return 0;
}