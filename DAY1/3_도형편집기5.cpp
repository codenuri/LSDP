#include <iostream>
#include <vector>

// �ٽ� 6. �����丵 �о��� ������ ��� �Դϴ� �ǹ̸� ������ ������

// "Replace Conditional With Polymorphism"
// => if(switch) �� �����Լ��� �����ϸ� Ȯ�强�� ���ٴ��ǹ�


// �ٽ� 7. ���������� �̶� ?
// => ���� ���Ǵ� �ڵ� ���Ͽ� �̸��� �ο� �Ѱ�
// => 1994�� �Ⱓ�� "������ ����"�̶� å����..
// => 23���� ������ ���� (���� 1���»����� ����)
// 
// �ٽ� 8. prototype - �ߺ��� �Ǵ� ��ü�� �����
//					  ���纻���� ��ü���� �����ϴ� ����
//					  clone() �����Լ�.



class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw Shape" << std::endl; }


	// �ڽ��� ���纻�� ����� �ִ� �����Լ��� 
	// ���� �θ� ���Ǵ� ��� �Դϴ�
	virtual Shape* clone()
	{
		return new Shape(*this); // ���� �����ڷ� �ڽ��� ����
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
			std::cout << "���° ������ ���� �ұ�� ?";

			int k;
			std::cin >> k;

			// k��° ���� ������ ������ ������ �����ؼ�
			// v�� �߰��մϴ�.
			// ��� �ؾ� �ұ�� ? k��° ������ ���� ��� �˱�� ?

			// C��� �������� ����
			// => OCP�� �������� ���� Ȯ�强 ���� �ڵ�
			/*
			if (k ��° �������� == Rect)
				v.push_back(new Rect);
			else if (k ��° �������� == Circle)
				v.push_back(new Circle);
			*/

			// OCP�� �����Ϸ���
			// k��° ������ �������� ���ʿ� ����
			v.push_back(v[k]->clone()); // ������!!!
		}
	}
}






