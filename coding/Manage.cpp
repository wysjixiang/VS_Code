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