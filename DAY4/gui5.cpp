#define USING_GUI
#include "gui.h"  

#include <map>
#include <vector>

class Window;

std::map<int, Window*> this_map;

class Window
{
	int handle;

	Window* parent = 0;		
	std::vector<Window*> v; 

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
		case WM_LBUTTONDOWN: self->HandleLButtonDown(); break;
		case WM_KEYDOWN:
			self->KeyDown();   
				break;
		}
		return 0;
	}
	// 아래 함수가 책임의 고리 패턴의 핵심입니다.
	void HandleLButtonDown()
	{
		if (this->LButtonDown() == true)
			return;

		if (parent != 0)
			parent->HandleLButtonDown();
	}

	virtual bool LButtonDown() { return false; }
	virtual void KeyDown() {}
};




class MyWindow : public Window
{
public:
	bool LButtonDown()
	{
		std::cout << "MyWindow LButton" << std::endl;

		return true;
	}
};

class ImageView : public Window
{
public:

	bool LButtonDown()
	{
		std::cout << "ImageView LButton" << std::endl;
		
		//return true; // 이벤트 처리 종료
		return false;  // 부모윈도우에게도 발생된 이벤트를 전달해 달라.
	}

};

int main()
{
	MyWindow w;
	w.Create("A");

	ImageView view;
	view.Create("view");

	w.AddChild(&view); 

	ec_process_message();
}

// 위와 같이 이벤트를 부모윈도우에 보내는 것을

// IOS : responder chain
// WPF(C#) : bubbling event 라고 합니다.

// 그 외에도
// MFC의 메뉴 처리 (Command routing) 이 책임의 고리 패턴입니다.