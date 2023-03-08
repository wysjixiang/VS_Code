#include <iostream>



/*********************************************
虚继承：

在多继承的基础上，派生类可能继承了基类的很多属性，有可能
就有相同的，比如name。而我们只需要一个name即可，但是在多
继承的情况下，必然是包含了多种name属性。
为了解决这个问题，引入虚继承。

通过虚继承某个基类，就是在告诉编译器：从当前这个类再派生
出来的子类只能拥有那个基类的一个实例

虚继承的语法：在基类前加上virtual即可
class Teacher: virtual public Person

此时查看析构函数的输出，会发现，这种情况下Person类只有一个
实例，因为Student和Teacher都是虚继承，所以没有拷贝。


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

class Student: virtual public Person
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


class Teacher: virtual public Person
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

//注意这里！ 最后构造函数要加上基类的（Person）
TeacherStudent::TeacherStudent(std::string name,
std::string classes):Student(name,classes),Teacher(name,classes),
Person(name,classes)    
{

}

//注意这个函数。因为多继承的两个父对象，Teacher和Student都包含
//name，class这个属性，因此子类包含了两个name和两个class属性
//所以不指定范围的话，是会报错的！
//注意，基类是必定有一份拷贝的
void TeacherStudent::Introduce()
{
    std::cout<< "I am a teacher & student";
    std::cout<< "My name is "<< name;  
    std::cout<< "I'm teaching in class: "<< 
    classes <<std::endl;
}




int main()
{
    Student *a = new Student("little pig","class 1");
    a->Introduce();
    
    delete a;
    system("pause");
    return 0;
}
