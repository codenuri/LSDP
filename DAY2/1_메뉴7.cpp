#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

class bad_operation {};

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s) {}

	virtual ~BaseMenu() {}

	std::string getTitle() { return title; }

	virtual void command() = 0;

	// append 등은 MenuItem 은 필요 없고
	// popupmenu 에만 필요 합니다.
	// 하지만 편리하게 사용하기 위해서
	// 기반 클래스에서 제공하기도 합니다
	virtual void append(BaseMenu* p)
	{
		throw bad_operation();
	}
	virtual BaseMenu* getSubMenu(int idx)
	{
		throw bad_operation();
	}

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
	BaseMenu* getSubMenu(int idx)
	{
		return v[idx];
	}
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->append(pm1);
	root->append(pm2);

	pm1->append(new MenuItem("HD", 11));
	pm1->append(new MenuItem("FHD", 12));

	// 아래 코드를 생각해 봅시다.
	// 1. root 메뉴의 하위 메뉴 얻기
	BaseMenu* p = root->getSubMenu(1);

	// 2. 아래 코드를 생각해 봅시다.
	// => 아래 코드를 지원하는게 좋을까요 ? 지원 하지 않는게 좋을까요?
	// => 지원 하려면 어떻게 해야 할까요 ?
	root->getSubMenu(1)->append(new MenuItem("Black", 24));
	root->getSubMenu(0)->append(new MenuItem("UHD",   14));

	// 아래 코드는 MenuItem 객체에 대해 append 하므로 예외 발생
	root->getSubMenu(0)->getSubMenu(0)->append(new MenuItem("UHD", 14));

	// 이제 시작하려면 ??
	root->command();
}


