#include <iostream>
#include <string>

class Person
{
	std::string name;
	int age;
public:
	// 모든 멤버가 안전한 값이 되도록 생성자 제공
	Person(const std::string& n, int a)
		: name(n), age(a) 
	{
	}
};
// Person 에서 상속 받는 Student 만드세요
// int id 멤버로 추가하고, 생성자 만들어 보세요
// main 에서 Student 객체 생성해 보세요.

class Student : public Person
{
	int id;
public:
//	Student(int n) : id(n) // : Person(), id(n)

	Student(const std::string& name, int age, int id) 
		: Person(name, age), id(id)
	{

	}
};

int main()
{
	Student s("kim", 35, 15);   //  모든 멤버 초기화 되도록해 보세요

//	Person p("kim", 35);
}



