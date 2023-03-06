// 6_메뉴1.cpp
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

// 객체지향 핵심 1. 필요한 것을 타입으로 설계 해라

// "MenuItem" 이라는 타입 설계

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}

	std::string getTitle() { return title; }

	void command()
	{
		std::cout << getTitle() << " 선택됨" << std::endl;
		_getch();
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	m1.command(); // 김밥 메뉴 선택
}

