#include <iostream>

class Animal
{
public:
	int age;

	// 모든 기반 클래스의 소멸자는 가상함수 이어야 한다.
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

	// 핵심 1. 기반 클래스 포인터로 파생 클래스 객체의 주소를
	//		   담을수 있다.
	Animal* p3 = &d; // ok

	// 핵심 2. Animal* 인 p3를 가지고는 Animal 의 멤버만
	//		  접근 가능
	p3->age = 10;	// ok
//	p3->color = 10;	// error

	// 핵심 3. Dog고유 멤버에 접근하려면 캐스팅 필요!
	// 단 아래 코드는 p3가 가리키는 곳이 Dog라는 확신이 
	// 있을때만 사용가능.
	static_cast<Dog*>(p3)->color = 10; // ok
	*/
	// 핵심 4. p3가 가리키는 객체가 Dog인지 조사 하는 방법
	

	Animal a;
	Dog    d;
//	Animal* p = &a;
	Animal* p = &d;

	// if (사용자입력==1) p = &d;

	// static_cast : 컴파일 시간 캐스팅
//	Dog* pdog = static_cast<Dog*>(p);

	// dynamic_cast : 실행 시간 캐스팅
	Dog* pdog = dynamic_cast<Dog*>(p);

	std::cout << pdog << std::endl;

}






