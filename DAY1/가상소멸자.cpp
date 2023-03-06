// ����Ҹ���.cpp - ������ 1�� �����ؿ�����
// 

#include <iostream>

// ��� : ��� Ŭ������ ���Ǵ� ��� Ŭ������ �Ҹ��ڴ�
//	     �ݵ�� �����Լ� �̾�� �մϴ�.!

class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	virtual ~Base() { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:
	
	Derived() 		
	{
		std::cout << "Derived()" << std::endl;
	}
	Derived(int a)	
	{
		std::cout << "Derived(int)" << std::endl;
	}
	~Derived()
	{
		std::cout << "~Derived()" << std::endl;

	}
};
int main()
{
//	Derived d1;		
	
//	Derived* p1 = new Derived;
//	delete p1;

	Base* p1 = new Derived;
	delete p1;

	// delete p1
	// 1. �Ҹ��� ȣ��
	//	  A. �Ҹ��ڰ� �����Լ��� �ƴϸ� p1�� Ÿ������ �Ҹ���ȣ��
	//       p1�� Base* �̹Ƿ� Base �Ҹ��ڸ� ȣ��
	// 
	//    B. �Ҹ��� �����̸� p1�� ����Ű�� �޸� ������ 
	//       �Ҹ��� ȣ��
	// 
	// 2. �޸� ����
}











