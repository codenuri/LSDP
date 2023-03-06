#include <iostream>
#include <vector>

// �ٽ� 9. template method ����
// => ��� Ŭ������ ������ ���� �˰����� ���� �޼ҵ� ����(public)
// => �޼ҵ� ���ο� ���ؾ� �ϴ� �κ��� �����Լ��� �и�.(protected,private)
// => �Ļ� Ŭ������ ���ؾ� �ϴ� �κи� ������ �Ҽ� �ְ� �ȴ�.

// => ���� �θ� ����ϴ� ����.

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }


	// ���뼺�� �������� �и�
	// => ������ ���� �ڵ� ���ο� ���� ���ؾ� �ϴ� �ڵ��
	//    �и��Ǿ�� �Ѵ�.
	// => ���ϴ� ���� �����Լ��� �и�

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
			std::cout << "���° ������ ���� �ұ�� ?";

			int k;
			std::cin >> k;

		
			v.push_back(v[k]->clone());
		}
	}
}






