#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

// ��� �޴��� ������ ��� Ŭ����
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
		std::cout << getTitle() << " ���õ�" << std::endl;
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

			std::cout << sz + 1 << ". ����" << std::endl;

			std::cout << "�޴��� �����ϼ��� >> ";
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
	MenuItem m1("��ġ  ���", 11);
	MenuItem m2("�Ұ�� ���", 12);

	PopupMenu kimbam("����");

	kimbam.append(&m1);
	kimbam.append(&m2);


	MenuItem m3("���", 21);

	PopupMenu pm("������ ����");

	pm.append(&kimbam); 
	pm.append(&m3);

	pm.command();


}

