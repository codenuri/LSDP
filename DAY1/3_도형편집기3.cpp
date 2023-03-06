#include <iostream>
#include <vector>


// �ٽ� 3. ��� �Ļ�Ŭ����(����)�� ������ Ư¡�� �ݵ��
//        ��� Ŭ�������� �־�� �Ѵ�(������ ������ �ƴ� ������ ����)
//        �׷���, ��� Ŭ���� �����ͷ� �����Ҷ� �ش� Ư¡�� ���
//        �Ҽ� �ִ�.

// �ٽ� 4. ��� Ŭ���� ��� �Լ��� �Ļ� Ŭ������ ������ �ϴ°���
//        �ݵ�� �����Լ��� ���� �Ǿ�� �Ѵ�.

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	// �Ʒ� �Լ��� �������� �ұ�� ? ���� ����� ? => �������ʿ����
	void set_color(int c) { color = c; }

	// �Ʒ� �Լ��� �����̾�� �մϴ�.
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






