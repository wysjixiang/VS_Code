#include <iostream>
#include <string>
#include <fstream>
#include "Worksystem.h"



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
        std::cin.ignore(10, '\n');//为了把输入的回车符号吸收掉！  
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
            std::cout<< employee1.GetNAME() << std::endl;
            std::cout<< employee1.GetBMBH() << std::endl;
            std::cout<< employee1.GetGZNR() << std::endl;

            std::cout<< manager1.GetZGBH() << std::endl;
            std::cout<< manager1.GetNAME() << std::endl;
            std::cout<< manager1.GetBMBH() << std::endl;
            std::cout<< manager1.GetGZNR() << std::endl;

            std::cout<< boss1.GetZGBH() << std::endl;
            std::cout<< boss1.GetNAME() << std::endl;
            std::cout<< boss1.GetBMBH() << std::endl;
            std::cout<< boss1.GetGZNR() << std::endl;
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