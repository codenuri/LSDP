#include <iostream>
#include <vector>

// 핵심 9. template method 패턴
// => 기반 클래스가 변하지 않은 알고리즘을 담은 메소드 제공(public)
// => 메소드 내부에 변해야 하는 부분을 가상함수로 분리.(protected,private)
// => 파생 클래스는 변해야 하는 부분만 재정의 할수 있게 된다.

// => 가장 널리 사용하는 패턴.

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }


	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 숨은 변해야 하는 코드는
	//    분리되어야 한다.
	// => 변하는 것을 가상함수로 분리

protected:
	virtual void draw_imp()
	{
		std::cout << "draw Shape" << std::endl;
	}

public:
	virtual void draw() final
	{ 
		std::cout << "mutex.lock" << std::endl;
		draw_imp();
		std::cout << "mutex.unlock" << std::endl;
	}





	virtual Shape* clone()
	{
		return new Shape(*this);
	}
};

class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw Rect" << std::endl; }

	virtual Shape* clone()
	{
		return new Rect(*this);
	}
};




class Circle : public Shape
{
public:
	void draw_imp() { std::cout << "draw Circle" << std::endl; }

	virtual Shape* clone()
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






