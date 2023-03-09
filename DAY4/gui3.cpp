#define USING_GUI
#include "gui.h"  

#include <map>

class Window;

std::map<int, Window*> this_map; // ÇÙ½É !!

class Window
{
	int handle; 
	
public:
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
		case WM_LBUTTONDOWN: self->LButtonDown();break;
		case WM_KEYDOWN:     
			self->KeyDown();    // this->KeyDown()
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

int main()
{
	MyWindow w;
	w.Create("A");

	ec_process_message();
}