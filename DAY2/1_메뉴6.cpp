#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

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
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->append(pm1);
	root->append(pm2);


	pm1->append(new MenuItem("HD", 11));
	pm1->append(new MenuItem("FHD", 12));
	pm1->append(new MenuItem("UHD", 13));
	pm1->append(new MenuItem("8K", 14));

	pm2->append(new MenuItem("Red",   21));
	pm2->append(new MenuItem("Green", 22));
	pm2->append(new MenuItem("Blue",  23));

	// 이제 시작하려면 ??
	root->command();
}


