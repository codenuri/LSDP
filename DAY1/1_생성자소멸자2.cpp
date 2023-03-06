#include <iostream>

// 아래 코드에서 에러를 찾아 보세요

class Base
{
public:
	Base(int a) { }
	~Base() {  }
};

class Derived : public Base
{
public:
	// 핵심 Base에 디폴트 생성자가 없다는 점
						// 컴파일러가 변경한 코드.
//	Derived() {}       // Derived() : Base() {}
//	Derived(int a) { } // Derived(int a) : Base(){ }


	// 기반 클래스에 디폴트 생성자가 없다면
	// 파생 클래스에서 반드시 명시적으로 다른 생성자 호출해야합니다.
	Derived()      : Base(0) {}       
	Derived(int a) : Base(a) {} 

	~Derived() {  }
};

int main()
{

}









