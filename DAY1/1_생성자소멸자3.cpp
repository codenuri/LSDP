#include <iostream>
#include <string>

class Person
{
	std::string name;
	int age;
public:
	// ��� ����� ������ ���� �ǵ��� ������ ����
	Person(const std::string& n, int a)
		: name(n), age(a) 
	{
	}
};
// Person ���� ��� �޴� Student ���弼��
// int id ����� �߰��ϰ�, ������ ����� ������
// main ���� Student ��ü ������ ������.

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
	Student s("kim", 35, 15);   //  ��� ��� �ʱ�ȭ �ǵ����� ������

//	Person p("kim", 35);
}



