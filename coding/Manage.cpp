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
        std::cin.ignore(10, '\n');//
        switch(choice)
        {
		case 0: //
            ComSystem.Exit();

			break;
		case 1: //
            ComSystem.AddInfo();

			break;
		case 2: //
            ComSystem.ShowInfo();

			break;
		case 3: //删除离职员工信息
        
            ComSystem.DeleteInfo();
			break;
		case 4: //修改职工信息
            ComSystem.ModifyInfo();
            
			break;
		case 5: //查找职工信息
            ComSystem.FindInfo();
			break;
		case 6: //按照编号排序
			break;
		case 7: //清空所有文件
			break;
		default:
			system("cls");
			break;


        }


    }


    
    

    system("pause");
    return 0;
}