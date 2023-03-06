#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

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

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& s) : title(s) {}

	void append(MenuItem* p) { v.push_back(p); }

	// 핵심 : 팝업메뉴를 선택했을때 할일을 생각해 보세요(main참고)
	void command()
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->getTitle()
					<< std::endl;
			}

			std::cout << sz + 1 << ". 종료" << std::endl;

			std::cout << "메뉴를 선택하세요 >> ";
			int cmd;
			std::cin >> cmd;


			if (cmd == sz + 1)
				break;

			if (cmd < 1 || sz + 1 < cmd)
				continue;


			v[cmd - 1]->command();

		}



	}
};





int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);
	
	PopupMenu pm("오늘의 점심"); // 이번 단계에서 만들 클래스

	pm.append(&m1);
	pm.append(&m2);

	pm.command();	// 어떻게 동작해야 할지 생각해 보세요
					// 1. 김밥
					// 2. 라면
					// 3. 종료
					// 메뉴를 선택하세요 >>

}

