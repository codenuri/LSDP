// 6_�޴�1.cpp
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

// ��ü���� �ٽ� 1. �ʿ��� ���� Ÿ������ ���� �ض�

// "MenuItem" �̶�� Ÿ�� ����

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}

	std::string getTitle() { return title; }

	void command()
	{
		std::cout << getTitle() << " ���õ�" << std::endl;
		_getch();
	}
};

int main()
{
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);

	m1.command(); // ��� �޴� ����
}

