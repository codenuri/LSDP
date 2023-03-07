#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.
// TextView 기능 : 문자열을 보관했다가 화면에 이쁘게 출력하는 기능을제공
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
// 클래스 어답터 : 클래스 인터페이스 변경
// 객체   어답터 : 객체 인터페이스 변경

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
	TextView* view; // 핵심 : 포인터 또는 참조
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
	
	Text t("ABC"); // 이미 인터페이스가 변경된 타입의 객체

	TextView tv("ABC"); // TextView : 클래스
						// tv       : 객체

//	v.push_back(&tv); // error
						// tv를 넣으려면 객체 어답터 필요

	v.push_back(new ObjectAdapter(&tv)) ;

	v[0]->draw();
}

// 상속                 : 클래스에 기능추가, 클래스의 인터페이스 변경
// 포함(포인터또는 참조로) : 객체에  기능추가,  객체의  인터페이스 변경

// Decorator : 함수 이름 유지(write), write에 기능 추가
// Adapter   : 함수 이름 변경(show => draw )





