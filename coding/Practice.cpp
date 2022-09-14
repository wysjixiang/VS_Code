#include <iostream>
#include <string>
#include <fstream>

template<class T>
class Array
{

public:
    Array(int rom)
    {
        this->rom = rom;
        this->size = 0;
        pAddr = new T[rom];
    }
    Array(const Array &arr)
    {   
        this->rom = arr.rom;
        this->size = arr.size;
        this->pAddr = new T[arr.rom];
    }
    ~Array()
    {
        if(pAddr != NULL)
        {

        delete pAddr;
        pAddr = NULL;

        }

    }

    Array& operator= (const Array &arr)
    {
        if(pAddr != NULL)
        {
            delete pAddr;
            pAddr = NULL;
        } 

        this->pAddr = new T[arr.rom];
        this->rom = arr.rom;
        this->size = arr.size;

        for(int i=0;i<arr.size;i++)
        {
            pAddr[i] = arr.pAddr[i];
        }

        return *this;
    }









private:
    T* pAddr;
    int rom;
    int size;

};



int main()
{



    system("pause");
    return 0;
}