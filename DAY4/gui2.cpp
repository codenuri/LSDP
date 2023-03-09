#define USING_GUI
#include "gui.h"  




class Window
{
	int handle; // 윈도우 번호
public:
	void Create(const std::string& title)
	{
		handle = ec_make_window(&handler, title);
	}

	// 핵심 1. ec_make_window 의 1번째 인자는 반드시 인자가
	//        4개인 함수만 전달 가능합니다
	// 
	// 2. 아래 함수에서 static 을 빼면 this가 추가되어서 인자가
	//    5개가 됩니다. 그래서 static

	// 일반함수 : Window private 접근 안됨
	// static멤버 : private 접근 가능.
	static int handler(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN:
			std::cout << "LBUTTON " << hwnd << std::endl;
			break;

		case WM_KEYDOWN:
			std::cout << "KEYDOWN " << hwnd << std::endl;
			break;
		}
		return 0;
	}
};

int main()
{
	Window w;
	w.Create("A");

	ec_process_message();
}