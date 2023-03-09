#define USING_GUI
#include "gui.h"  

#include <map>
#include <vector>

class Window;

std::map<int, Window*> this_map; 

class Window
{
	int handle;

	Window* parent = 0;		// 부모윈도우는 한개
	std::vector<Window*> v; // 자식윈도우는 여러개

public:

	void AddChild(Window* child)
	{
		v.push_back(child);

		child->parent = this;

		ec_add_child(this->handle, child->handle);
	}




	void Create(const std::string& title)
	{
		handle = ec_make_window(&handler, title);

		this_map[handle] = this;
	}

	static int handler(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN: self->LButtonDown(); break;
		case WM_KEYDOWN:
			self->KeyDown();   
			break;
		}
		return 0;
	}
	virtual void LButtonDown() {}
	virtual void KeyDown() {}
};

class MyWindow : public Window
{
public:
	void LButtonDown()
	{
		std::cout << "MyWindow LButton" << std::endl;
	}
};

class ImageView : public Window
{
public:
	void LButtonDown()
	{
		std::cout << "ImageView LButton" << std::endl;
	}
};

int main()
{
	MyWindow w;
	w.Create("A");

	ImageView view;
	view.Create("view");

	w.AddChild(&view); // 자식윈도우로 부착

	ec_process_message();
}
