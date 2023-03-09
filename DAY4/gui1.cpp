// gui1.cpp
#define USING_GUI
#include "gui.h"  // gui.h 파일 만드세요
				  // git   DAY4 폴더에서 cppmaster.h 내용복사해 오세요

int handler(int hwnd, int msg, int a, int b)
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
int main()
{
	int h1 = ec_make_window(&handler, "A");
	int h2 = ec_make_window(&handler, "B");

	ec_add_child(h1, h2); // h2를 h1의 자식윈도우로 부착 

	ec_process_message();

}