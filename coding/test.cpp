#include <iostream>
#include <string>
#include <fstream>


int main()
{
    int i=0;
    int j=0;
    std::string str;
    char bh[32];
    char name[32];
    char bm[32];

    std::cout<< "����Ա������ϵͳ..."<<std::endl;
    std::cout<< "�밴��Ա�����,����,���ŵĸ�ʽ����,δ֪������дUK"<<std::endl;

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

    std::cout<< bh <<std::endl;
    std::cout<< name <<std::endl;
    std::cout<< bm <<std::endl;



    system("pause");
    return 0;
}