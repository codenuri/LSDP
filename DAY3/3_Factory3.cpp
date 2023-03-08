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

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)();

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
			p = ret->second();
		}

		return p;
	}
};


class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::getInstance().Register(key, f);
	}
};

// main 함수와 전역변수생성자중 먼저 실행되는 것은 ?
// AutoRegister ar(1, &Rect::Create);






class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }


	static Shape* Create()
	{
		return new Rect;
	}

	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::Create);








class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create()
	{
		return new Circle;
	}
	static AutoRegister ar;
};
AutoRegister Circle::ar(2, &Circle::Create);



int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();


//	factory.Register(1, &Rect::Create);
//	factory.Register(2, &Circle::Create);


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




