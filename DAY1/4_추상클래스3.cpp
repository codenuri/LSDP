#include <iostream>

// 강한결합(tightly coupling)
// => 하나의 클래스가 다른 클래스 사용시 클래스 이름을 직접 사용
// => 교체 불가능한 경직된 디자인


// 약한결합(loosely coupling)
// => 하나의 클래스가 다른 클래스 사용시 
//    규칙을 담은 클래스(인터페이스) 이름을 사용
// 
// => 교체 가능한 유연한 디자인

// 추상 클래스 : 지켜야 하는 규칙(순수가상함수) + 다른 멤버
// 인터 페이스 : 지켜야 하는 규칙(순수가상함수)만 있는 경우

// java, C# 은 abstract, interface 라는 별도의 키워드 존재


// 카메라와 사람 사이에 지켜야 하는 규칙을 먼저 설계 합니다.
// 규칙 : 모든 카메라는 아래 클래스로 부터 파생 되어야 한다. 라고 하지 말고
// 규칙 : 모든 카메라는 아래 인터페이스를 구현 해야 한다. 라고 표현

#define interface struct 

//struct ICamera
interface ICamera
{
	virtual void take() = 0;
	virtual ~ICamera() {}   // 기반 클래스 이므로
							// 가상 소멸자로!
};



// 카메라는 없지만 규칙이 있다.
// 사용자는 규칙 대로만 사용하면 된다.
class People
{
public:
	void useCamera(ICamera* p) { p->take(); }
};

class Camera : public ICamera
{
public:
	void take() { std::cout << "Camera take" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "HDCamera take" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "UHDCamera take" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera hc;
	p.useCamera(&hc); 

	UHDCamera uhc;
	p.useCamera(&uhc); 
}




