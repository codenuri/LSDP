#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

// 모든 메뉴의 공통의 기반 클래스
class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s) {}

	virtual ~BaseMenu() {}

	std::string getTitle() { return title; }


	virtual void command() = 0;
};




class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& s, int n)
		: BaseMenu(s), id(n) {}



	void command()
	{
		std::cout << getTitle() << " 선택됨" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}


	void append(BaseMenu* p) { v.push_back(p); }

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
	MenuItem m1("참치  김밥", 11);
	MenuItem m2("소고기 김밥", 12);

	PopupMenu kimbam("김밥류");

	kimbam.append(&m1);
	kimbam.append(&m2);


	MenuItem m3("라면", 21);

	PopupMenu pm("오늘의 점심");

	pm.append(&kimbam); 
	pm.append(&m3);

	pm.command();


}

