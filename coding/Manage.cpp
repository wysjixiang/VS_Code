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
        std::cout<<"����������ѡ��"<<std::endl;
        std::cin >> choice;
        std::cin.ignore(10, '\n');//Ϊ�˰�����Ļس��������յ���  
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