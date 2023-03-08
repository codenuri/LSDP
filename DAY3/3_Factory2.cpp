#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// 자신을 만드는 static 멤버 함수는 아주 유용하게 사용됩니다.
	// 1. 오직 한개의 객체만 만들때 - 싱글톤
	// 2. 속성이 동일하면 공유하자  - 플라이웨이트
	static Shape* Create()
	{
		return new Rect;
	}
};
// Rect를 만드는 2가지 방법
// 1. new Rect;       // 클래스 이름 사용
// 2. Rect::Create(); // static 멤버 함수 사용

// 자료구조에 클래스 이름을 보관할수 있을까?
// map<key, 클래스이름>  ???
// => "Rect" 라는 문자열로 보관은 가능하지만, 
// =>  문자열로 된 클래스 이름으로는 객체를 만들수 없다.











class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create()
	{
		return new Circle;
	}
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape* (*)(); // 함수 포인터 타입
						// typedef Shape* (*CREATOR)()

	std::map<int, CREATOR> create_map;

public:
	void Register(int key, CREATOR f)
	{
		create_map[key] = f;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;
	
		auto ret = create_map.find(type);

		if (ret != create_map.end())
		{
			p = ret->second(); // ret->second 가 맵에 등록된 함수
		}

		return p;
	}
};





int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// 공장에 제품을 등록합니다.
	factory.Register(1, &Rect::Create);
	factory.Register(2, &Circle::Create);



	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 7) 
		{
			Shape* p = factory.Create(cmd);

			if (p != 0)
				v.push_back(p);
		}

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();	
			}
		}
	}
}




