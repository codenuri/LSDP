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
// Ŭ���� ����� : Ŭ���� �������̽� ����
// ��ü   ����� : ��ü �������̽� ����

class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() override
	{
		TextView::show();
	}
};

class ObjectAdapter :  public Shape
{
	TextView* view; // �ٽ� : ������ �Ǵ� ����
public:
	ObjectAdapter(TextView* p) : view(p) {}

	void draw() override
	{
		view->show();
	}
};

int main()
{
	std::vector<Shape*> v;
	
	Text t("ABC"); // �̹� �������̽��� ����� Ÿ���� ��ü

	TextView tv("ABC"); // TextView : Ŭ����
						// tv       : ��ü

//	v.push_back(&tv); // error
						// tv�� �������� ��ü ����� �ʿ�

	v.push_back(new ObjectAdapter(&tv)) ;

	v[0]->draw();
}

// ���                 : Ŭ������ ����߰�, Ŭ������ �������̽� ����
// ����(�����ͶǴ� ������) : ��ü��  ����߰�,  ��ü��  �������̽� ����

// Decorator : �Լ� �̸� ����(write), write�� ��� �߰�
// Adapter   : �Լ� �̸� ����(show => draw )





