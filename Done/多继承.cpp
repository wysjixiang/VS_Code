#include <iostream>



/*********************************************
多继承：

如果派生类只有一个基类，称为单继承。
如果一个派生类有两个或者多个基类，则称为多继承
多继承容易让代码逻辑复杂、思路混乱，一直备受争议，
中小型项目中较少使用，后来的 Java、C#、PHP 等干脆取消了多继承。

多继承的语法也很简单，将多个基类用逗号隔开即可。例如已声明了
类A、类B和类C，那么可以这样来声明派生类D：

class D: public A, private B, protected C{
    //类D新增加的成员
}



*********************************************/

class Person
{
public:
    Person(std::string Name,std::string Classes)
    {
        name = Name;
        classes = Classes;
    }
    virtual ~Person()
    {

        std::cout<< "Person Destructor!\n"<<std::endl;
    }
protected:
        std::string name;
        std::string classes;
};

class Student:public Person
{
public:
    Student(std::string name,std::string classes);
    virtual ~Student();
    virtual void Introduce();

};

Student:: Student(std::string name,std::string classes):
Person(name,classes)
{
}

Student::~Student()
{
    std::cout<< "Student Destructor!\n"<<std::endl;
}

void Student::Introduce()
{

    std::cout<< "I am a student";
    std::cout<< "My name is "<< name;
    std::cout<< "I'm studying in class: "<< classes <<std::endl;
}


class Teacher:public Person
{
public:
    Teacher(std::string name,std::string classes);
    virtual ~Teacher();
    virtual void Introduce();

};

Teacher:: Teacher(std::string name,std::string classes):
Person(name,classes)
{
}

Teacher::~Teacher()
{
    std::cout<< "Teacher Destructor!\n"<<std::endl;
}

void Teacher::Introduce()
{

    std::cout<< "I am a teacher";
    std::cout<< "My name is "<< name;
    std::cout<< "I'm teaching in class: "<< classes <<std::endl;
}


class TeacherStudent: public Student, public Teacher
{
public:
    TeacherStudent(std::string name,
std::string classes);
    ~TeacherStudent()
    {
        std::cout<< "TeacherStudent Destructor!\n"<<std::endl;
    }
    void Introduce();

};

TeacherStudent::TeacherStudent(std::string name,
std::string classes):Student(name,classes),Teacher(name,classes)
{

}

//注意这个函数。因为多继承的两个父对象，Teacher和Student都包含
//name，class这个属性，因此子类包含了两个name和两个class属性
//所以不指定范围的话，是会报错的！
void TeacherStudent::Introduce()
{
    std::cout<< "I am a teacher & student";
    std::cout<< "My name is "<< Student::name;  
    std::cout<< "I'm teaching in class: "<< 
    Student::classes <<std::endl;
}




int main()
{
    TeacherStudent *a = new TeacherStudent("little pig","class 1");
    a->Introduce();
    
    delete a; 
    system("pause");
    return 0;
}
