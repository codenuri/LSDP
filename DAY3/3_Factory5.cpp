#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create()
	{
		return new Rect;
	}
	Rect* clone() override { return new Rect(*this); }
};




class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create()
	{
		return new Circle;
	}

	Circle* clone() override { return new Circle(*this); }

};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> prototyp_map;

public:
	void Register(int key, Shape* p)
	{
		prototyp_map[key] = p;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;

		auto ret = prototyp_map.find(type);

		if (ret != prototyp_map.end())
		{
			p = ret->second->clone(); 
		}

		return p;
	}
};





int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();


	// ���忡 Ŭ������ ����ϴ� �ǹ��� �ڵ� �Դϴ�.
//	factory.Register(1, &Rect::Create);
//	factory.Register(2, &Circle::Create);

	// ���� ����� �Ǵ� ��ü�� �ߺ��� ���� ��������
	Rect* redRect = new Rect;
	Rect* blueRect = new Rect;
	Circle* redCircle = new Circle;

	// ���忡 ��ü�� ����մϴ�.
	factory.Register(1, redRect);
	factory.Register(2, blueRect);
	factory.Register(3, redCircle);


//	factory.showRegisteredPrototype();


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




