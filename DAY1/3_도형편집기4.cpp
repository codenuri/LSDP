#include <iostream>
#include <vector>

// �ٽ� 5. OCP 
// ��� Ȯ�忡 ���� �ְ�(Open, ���ο� Ŭ������ �߰��Ǿ)
// �ڵ� �������� ���� �־��(Close, ���� �ڵ�� ������� �ʵ���)
// �ϴ� ��Ģ(Principle)
// Open-Close Principle(���� ����� ��Ģ)

// 5�� ���� ��Ģ : SRP, OCP, LSP, ISP, DIP => SOLID

// �������� OCP �� �����ϴ� ���� �ڵ� ��Ÿ��


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

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
class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw Triangle" << std::endl; }
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
				p->draw(); // ������(Polymorphism)
					// => ������ ǥ������ ��Ȳ�� ���� �ٸ���
					// �����ϴ� ��

			// ��ü���� ����� 3�� Ư¡ : ĸ��ȭ, ���, ������
		}
	}
}






