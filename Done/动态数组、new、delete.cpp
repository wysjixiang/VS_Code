#include <iostream>



/*********************************************
动态数组：

new & delete使用

其实和C中的malloc函数和free函数作用是一样的.注意格式就行！

int *p = new int[n] ;
delete [] p;


*********************************************/




int main()
{
    unsigned int count;

    std::cout<<"Please input a number:"<<std::endl;

    std::cin >> count;

    int *p = new int[count];

    for(int i=0; i<count; i++)
    {
        p[i] = i;
    }

    for(int i=0; i<count; i++)
    {
        std::cout<< "p["<< i <<"]= "<< p[i] << std::endl;
    }

    delete [] p;

    return 0;
}
