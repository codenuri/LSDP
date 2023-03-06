#include <iostream>
#include <vector>


// 핵심 3. 모든 파생클래스(도형)의 공통의 특징은 반드시
//        기반 클래스에도 있어야 한다(문법적 제약이 아닌 디자인 관점)
//        그래야, 기반 클래스 포인터로 관리할때 해당 특징을 사용
//        할수 있다.

// 핵심 4. 기반 클래스 멤버 함수중 파생 클래스가 재정의 하는것은
//        반드시 가상함수로 설계 되어야 한다.

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	// 아래 함수는 가상으로 할까요 ? 하지 말까요 ? => 가상일필요없음
	void set_color(int c) { color = c; }

	// 아래 함수는 가상이어야 합니다.
	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw Shape" << std::endl; }

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
	}
}






