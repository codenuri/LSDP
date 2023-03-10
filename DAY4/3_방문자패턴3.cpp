#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 



// list    : 모든 요소가 동일 타입이고 선형 형태로만 보관.
// root 메뉴: 각 요소의 타입이 다르고, tree 형태로 보관하고 있는 복합객체

// 방문자의 인터페이스
// root 메뉴가 보관하는 요소는 "2가지 종류 타입의 객체" 이다. 

class MenuItem;
class PopupMenu;

struct IMenuVisitor
{
	virtual void visit(MenuItem* m) = 0;
	virtual void visit(PopupMenu* pm) = 0;
	virtual ~IMenuVisitor() {}
};

// 모든 메뉴를 방문자를 accept 해야한다 - 인터페이스
struct IAccept
{
	virtual void accept(IMenuVisitor* v) = 0;
	virtual ~IAccept() {}
};







class BaseMenu : public IAccept
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	void set_title(const std::string& s) { title = s; }


	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command() override
	{
		std::cout << get_title() << " 메뉴가 선택됨" << std::endl;
		_getch();
	}

	void accept(IMenuVisitor* v) override
	{
		// 자기 자신을 방문자에 전달하면 됩니다.
		v->visit(this);
	}
};





class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command() override
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			std::cout << sz + 1 << ". 종료" << std::endl;

			int cmd;
			std::cout << "메뉴를 선택하세요 >> ";
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1)
				break;

			v[cmd - 1]->command(); 
		}

	}

	void accept(IMenuVisitor* visitor) override
	{
		// 자기 자신을 방문자에 전달하고
		visitor->visit(this);

		// 자신이 가지고 있는 하위메뉴에 방문자를 방문 시킵니다.
		for (auto p : v)
		{
			p->accept(visitor);
		}
	}
};

// 메뉴에 대한 연산을 수행하는 방문자
class PopupMenuTitleChangeVisitor : public IMenuVisitor
{
public:
	void visit(MenuItem* m)   {}
	void visit(PopupMenu* pm) 
	{
		std::string s = pm->get_title();

		s = "[ " + s + " ]";

		pm->set_title(s);
	}
};




int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	root->add_menu(pm2);


	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));


	// 모든 메뉴를 방문해서 PopupMenu 인 경우만 타이틀을 수정하는 방문자
	PopupMenuTitleChangeVisitor pmv;

	root->accept(&pmv);



	root->command();

}




