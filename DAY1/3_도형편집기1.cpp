#include <iostream>
#include <vector>

// �Ŀ�����Ʈ ���� ���α׷��� ����� ���ô�.
// �ٽ� 1. ��� ������ Ÿ��ȭ �ϸ� ���ϴ�.

// �ٽ� 2. ��� ������ ������ ��� Ŭ������ �ִٸ�
//        ��� ������ �ϳ��� �����̳ʿ� �����Ҽ� �ִ�.

class Shape
{
public:
	virtual ~Shape() {}
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
//	std::vector<Rect*> v;
	std::vector<Shape*> v;
}






