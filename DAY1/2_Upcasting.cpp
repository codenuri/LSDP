#include <iostream>

class Animal
{
public:
	int age;

	// ��� ��� Ŭ������ �Ҹ��ڴ� �����Լ� �̾�� �Ѵ�.
	virtual ~Animal() {}
};

class Dog : public Animal 
{
public:
	int color;
};

int main()
{
	/*
	Dog    d;

	Dog* p1 = &d; // ok

//	int* p2 = &d; // error

	// �ٽ� 1. ��� Ŭ���� �����ͷ� �Ļ� Ŭ���� ��ü�� �ּҸ�
	//		   ������ �ִ�.
	Animal* p3 = &d; // ok

	// �ٽ� 2. Animal* �� p3�� ������� Animal �� �����
	//		  ���� ����
	p3->age = 10;	// ok
//	p3->color = 10;	// error

	// �ٽ� 3. Dog���� ����� �����Ϸ��� ĳ���� �ʿ�!
	// �� �Ʒ� �ڵ�� p3�� ����Ű�� ���� Dog��� Ȯ���� 
	// �������� ��밡��.
	static_cast<Dog*>(p3)->color = 10; // ok
	*/
	// �ٽ� 4. p3�� ����Ű�� ��ü�� Dog���� ���� �ϴ� ���
	

	Animal a;
	Dog    d;
//	Animal* p = &a;
	Animal* p = &d;

	// if (������Է�==1) p = &d;

	// static_cast : ������ �ð� ĳ����
//	Dog* pdog = static_cast<Dog*>(p);

	// dynamic_cast : ���� �ð� ĳ����
	Dog* pdog = dynamic_cast<Dog*>(p);

	std::cout << pdog << std::endl;

}






