#include <iostream>
#include <vector>

// �ٽ� 9. template method ����
// => ��� Ŭ������ ������ ���� �˰����� ���� �޼ҵ� ����(public)
// => �޼ҵ� ���ο� ���ؾ� �ϴ� �κ��� �����Լ��� �и�.(protected,private)
// => �Ļ� Ŭ������ ���ؾ� �ϴ� �κи� ������ �Ҽ� �ְ� �ȴ�.

// => ���� �θ� ����ϴ� ����.

class unimplemented {};

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	// �����Լ� : �Ļ� Ŭ������ ������ ���� ������ ������ �����شٴ°�
	// 
	//���������Լ� : �Ļ� Ŭ������ �ݵ�� ������ �Ѵٴ� ��

protected:
	virtual void draw_imp() = 0;

public:
	// ��� 1. ���������Լ� : �Ļ�Ŭ������ �ݵ�� ������ �ض�.
//	virtual Shape* clone() = 0; 

	// ��� 2. 
	// ������ ���ϰ� ��뵵 ���ϸ� ok
	// ������ ���ϰ� ��뵵 �ϸ�  ����
	// ������ �ϰ�   ���  �ϸ�  ok
	virtual Shape* clone() 
	{
		throw unimplemented();
	}

	// ��� 3. get_area() ȣ��� -1 ������ ������ ���Ҽ� ����
	//        Ÿ���̶�� �������!
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

	// ������ȯ�� ��Ģ : �����Լ� �����ǽ� ��ȯ Ÿ�� ���氡���մϴ�.
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
			std::cout << "���° ������ ���� �ұ�� ?";

			int k;
			std::cin >> k;


			v.push_back(v[k]->clone());
		}
	}
}






