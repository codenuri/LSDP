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

	// append ���� MenuItem �� �ʿ� ����
	// popupmenu ���� �ʿ� �մϴ�.
	// ������ ���ϰ� ����ϱ� ���ؼ�
	// ��� Ŭ�������� �����ϱ⵵ �մϴ�
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
	BaseMenu* getSubMenu(int idx)
	{
		return v[idx];
	}
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("�ػ� ����");
	PopupMenu* pm2 = new PopupMenu("���� ����");

	root->append(pm1);
	root->append(pm2);

	pm1->append(new MenuItem("HD", 11));
	pm1->append(new MenuItem("FHD", 12));

	// �Ʒ� �ڵ带 ������ ���ô�.
	// 1. root �޴��� ���� �޴� ���
	BaseMenu* p = root->getSubMenu(1);

	// 2. �Ʒ� �ڵ带 ������ ���ô�.
	// => �Ʒ� �ڵ带 �����ϴ°� ������� ? ���� ���� �ʴ°� �������?
	// => ���� �Ϸ��� ��� �ؾ� �ұ�� ?
	root->getSubMenu(1)->append(new MenuItem("Black", 24));
	root->getSubMenu(0)->append(new MenuItem("UHD",   14));

	// �Ʒ� �ڵ�� MenuItem ��ü�� ���� append �ϹǷ� ���� �߻�
	root->getSubMenu(0)->getSubMenu(0)->append(new MenuItem("UHD", 14));

	// ���� �����Ϸ��� ??
	root->command();
}


