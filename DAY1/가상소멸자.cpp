// 가상소멸자.cpp - 생성자 1번 복사해오세요
// 

#include <iostream>

// 결론 : 기반 클래스로 사용되는 모든 클래스의 소멸자는
//	     반드시 가상함수 이어야 합니다.!

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
	// 1. 소멸자 호출
	//	  A. 소멸자가 가상함수가 아니면 p1의 타입으로 소멸자호출
	//       p1이 Base* 이므로 Base 소멸자만 호출
	// 
	//    B. 소멸자 가상이면 p1이 가리키는 메모리 조사후 
	//       소멸자 호출
	// 
	// 2. 메모리 제거
}











