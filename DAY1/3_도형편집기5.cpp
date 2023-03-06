#include <iostream>
#include <vector>

// 핵심 6. 리팩토링 분야의 유명한 용어 입니다 의미를 생각해 보세요

// "Replace Conditional With Polymorphism"
// => if(switch) 를 가상함수로 변경하면 확장성이 좋다는의미


// 핵심 7. 디자인패턴 이란 ?
// => 자주 사용되는 코딩 패턴에 이름을 부여 한것
// => 1994년 출간된 "디자인 패턴"이라 책에서..
// => 23개의 디자인 패턴 (현재 1개는사용되지 않음)
// 
// 핵심 8. prototype - 견본이 되는 객체를 만들고
//					  복사본으로 객체들을 생성하는 패턴
//					  clone() 가상함수.



class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw Shape" << std::endl; }


	// 자신의 복사본을 만들수 있는 가상함수는 
	// 아주 널리 사용되는 기술 입니다
	virtual Shape* clone()
	{
		return new Shape(*this); // 복사 생성자로 자신을 복사
	}
};



class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect" << std::endl; }

	virtual Shape* clone()
	{
		return new Rect(*this);
	}
};




class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle" << std::endl; }

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

			// k번째 만든 도형과 동일한 도형을 복사해서
			// v에 추가합니다.
			// 어떻게 해야 할까요 ? k번째 도형이 뭔지 어떻게 알까요 ?

			// C언어 개발자의 선택
			// => OCP를 만족하지 않은 확장성 없는 코드
			/*
			if (k 번째 도형조사 == Rect)
				v.push_back(new Rect);
			else if (k 번째 도형조사 == Circle)
				v.push_back(new Circle);
			*/

			// OCP를 만족하려면
			// k번째 도형이 무엇인지 알필요 없다
			v.push_back(v[k]->clone()); // 다형성!!!
		}
	}
}






