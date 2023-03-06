#include <iostream>
#include <vector>

// 파워포인트 같은 프로그램을 만들어 봅시다.
// 핵심 1. 모든 도형을 타입화 하면 편리하다.

// 핵심 2. 모든 도형의 공통의 기반 클래스가 있다면
//        모든 도형을 하나의 컨테이너에 보관할수 있다.

class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle" << std::endl; }
};
int main()
{
//	std::vector<Rect*> v;
	std::vector<Shape*> v;
}






