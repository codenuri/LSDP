#include <iostream>
#include <string>
#include <vector>

// �Ʒ� Ŭ������ �̹� �־��ٰ� ������ ���ô�.
// TextView ��� : ���ڿ��� �����ߴٰ� ȭ�鿡 �̻ڰ� ����ϴ� ���������
class TextView
{
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};

//---------------------------------------------

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

// ���������� �ý��ۿ��� ���ڿ��� �ٷ�� Ŭ������ �ʿ� �մϴ�.
// 
// ������ �����ϴ� "TextView" �� �������̽�(�Լ��̸�) �� �����ؼ�
// ���������Ⱑ �䱸�ϴ� ������ �����ϵ��� �غ��ô�.
// Adapter : ���� Ŭ������ �������̽��� �����ؼ�
//          Ŭ���̾�Ʈ�� �䱸�ϴ� �������̽��� �����ϴ� ����
//			�������̽��� ����ġ�� �ذ��ϴ� ����.

class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	// show �Լ��̸��� draw �� �����Ѱ�!
	void draw() override
	{
		TextView::show();
	}
};

int main()
{
	std::vector<Shape*> v;

//	v.push_back(new TextView("AAA")); // error
	v.push_back(new Text("AAA")); // ok

	v[0]->draw();
}







