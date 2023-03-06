#include <iostream>
#include <vector>

// 핵심 9. template method 패턴
// => 기반 클래스가 변하지 않은 알고리즘을 담은 메소드 제공(public)
// => 메소드 내부에 변해야 하는 부분을 가상함수로 분리.(protected,private)
// => 파생 클래스는 변해야 하는 부분만 재정의 할수 있게 된다.

// => 가장 널리 사용하는 패턴.

class unimplemented {};

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	// 가상함수 : 파생 클래스가 재정의 하지 않으면 구현을 물려준다는것
	// 
	//순수가상함수 : 파생 클래스가 반드시 만들어야 한다는 것

protected:
	virtual void draw_imp() = 0;

public:
	// 방법 1. 순수가상함수 : 파생클래스가 반드시 재정의 해라.
//	virtual Shape* clone() = 0; 

	// 방법 2. 
	// 재정의 안하고 사용도 안하면 ok
	// 재정의 안하고 사용도 하면  예외
	// 재정의 하고   사용  하면  ok
	virtual Shape* clone() 
	{
		throw unimplemented();
	}

	// 방법 3. get_area() 호출시 -1 나오면 면적을 구할수 없는
	//        타입이라고 약속하자!
	virtual int get_area() { return -1; }


public:
	virtual void draw() final
	{
		std::cout << "mutex.lock" << std::endl;
		draw_imp();
		std::cout << "mutex.unlock" << std::endl;
	}






};

class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw Rect" << std::endl; }

	// 공변반환의 법칙 : 가상함수 재정의시 반환 타입 변경가능합니다.
	Rect* clone() override
	{
		return new Rect(*this);
	}
};

// Rect* p1 = new Rect;
// ? p2 = p1->clone();


class Circle : public Shape
{
public:
	void draw_imp() { std::cout << "draw Circle" << std::endl; }

	Circle* clone() override 
	{
		return new Circle(*this);
	}
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();
		}

		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 ?";

			int k;
			std::cin >> k;


			v.push_back(v[k]->clone());
		}
	}
}






