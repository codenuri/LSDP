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

// 도형편집기 시스템에서 문자열을 다루는 클래스가 필요 합니다.
// 
// 기존에 존재하던 "TextView" 의 인터페이스(함수이름) 을 변경해서
// 도형편집기가 요구하는 조건을 만족하도록 해봅시다.
// Adapter : 기존 클래스의 인터페이스를 변경해서
//          클라이언트가 요구하는 인터페이스를 제공하는 패턴
//			인터페이스의 불일치를 해결하는 패턴.

class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	// show 함수이름을 draw 로 변경한것!
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







