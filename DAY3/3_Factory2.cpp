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

	// �ڽ��� ����� static ��� �Լ��� ���� �����ϰ� ���˴ϴ�.
	// 1. ���� �Ѱ��� ��ü�� ���鶧 - �̱���
	// 2. �Ӽ��� �����ϸ� ��������  - �ö��̿���Ʈ
	static Shape* Create()
	{
		return new Rect;
	}
};
// Rect�� ����� 2���� ���
// 1. new Rect;       // Ŭ���� �̸� ���
// 2. Rect::Create(); // static ��� �Լ� ���

// �ڷᱸ���� Ŭ���� �̸��� �����Ҽ� ������?
// map<key, Ŭ�����̸�>  ???
// => "Rect" ��� ���ڿ��� ������ ����������, 
// =>  ���ڿ��� �� Ŭ���� �̸����δ� ��ü�� ����� ����.











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

	using CREATOR = Shape* (*)(); // �Լ� ������ Ÿ��
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
			p = ret->second(); // ret->second �� �ʿ� ��ϵ� �Լ�
		}

		return p;
	}
};





int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// ���忡 ��ǰ�� ����մϴ�.
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




