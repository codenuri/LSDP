#include <iostream>
#include <vector>
#include <stack>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

struct ICommand
{
	virtual void execute() = 0;
	virtual bool canUndo() { return false; }
	virtual void undo() {}

	virtual ~ICommand() {}
};

class AddCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(CreateShape()); };

	bool canUndo() override { return true; }

	void undo() override
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}

	virtual Shape* CreateShape() = 0;
};


class AddRectCommand : public AddCommand
{
public:
	AddRectCommand(std::vector<Shape*>& v) : AddCommand(v) {}

	Shape* CreateShape() override { return new Rect; }
};

class AddCircleCommand : public AddCommand
{
public:
	using AddCommand::AddCommand; 

	Shape* CreateShape() override { return new Circle; }
};





class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override
	{
		for (auto p : v)
			p->draw();
	};
	bool canUndo() override { return true; }

	void undo() override
	{
		system("cls");
	}
};

//------------------------------------

// 여러개 명령을 묶어서 한개의 명령으로 만드는 매크로 명령
class MacroCommand : public ICommand // Composite 패턴
{
	std::vector<ICommand*> v;
public:
	void addCommand(ICommand* p) { v.push_back(p); }

	void execute()
	{
		for (auto p : v)
			p->execute();
	}
};

int main()
{
	std::vector<Shape*> v;

	std::stack<ICommand*> cmd_stack;

	ICommand* pcmd = 0;


	MacroCommand* mc1 = new MacroCommand;
	mc1->addCommand(new AddRectCommand(v));
	mc1->addCommand(new AddCircleCommand(v));
	mc1->addCommand(new DrawCommand(v));

	mc1->execute(); // 저장된 3개의 명령을 한번에 실행.


	MacroCommand* mc2 = new MacroCommand;
	mc2->addCommand(new AddRectCommand(v));

	mc2->addCommand( mc1 );



	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			pcmd = new AddRectCommand(v);
			pcmd->execute();
			cmd_stack.push(pcmd);
		}

		else if (cmd == 2)
		{
			pcmd = new AddCircleCommand(v);
			pcmd->execute();
			cmd_stack.push(pcmd);
		}

		else if (cmd == 9)
		{
			pcmd = new DrawCommand(v);
			pcmd->execute();
			cmd_stack.push(pcmd);
		}

		else if (cmd == 8)
		{
			if (!cmd_stack.empty())
			{
				pcmd = cmd_stack.top();

				cmd_stack.pop();

				if (pcmd->canUndo() == true)
				{
					pcmd->undo();
				}

				delete pcmd;
			}
		}
	}
}




