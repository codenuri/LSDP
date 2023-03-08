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

// 메뉴를 선택하면 어떤 기능을 수행해야 합니다.
// C언어 : 함수로 설계. 해당 기능만 수행가능
// C++  : 객체로 설계, 해당 기능 + 추가 작업(undo) 가능
//		 그리고 스택에 보관도 가능.

struct ICommand
{
	virtual void execute() = 0;
	virtual bool canUndo() { return false; }
	virtual void undo() {}

	virtual ~ICommand() {}
};

class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v; // 실행/취소에 필요한 데이타
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Rect); };

	bool canUndo() override { return true; }
	
	void undo() override 
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
};

class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v; 
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Circle); };

	bool canUndo() override { return true; }

	void undo() override
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
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

int main()
{
	std::vector<Shape*> v;

	std::stack<ICommand*> cmd_stack; // undo를 위해 모든 명령보관

	ICommand* pcmd = 0;

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

				delete pcmd; // redo 도 지원하려면 파괴 하지말고
							 // redo_stack.push(pcmd)
			}
		}
	}
}




