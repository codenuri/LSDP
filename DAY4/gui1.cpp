// gui1.cpp
#define USING_GUI
#include "gui.h"  // gui.h ���� ���弼��
				  // git   DAY4 �������� cppmaster.h ���뺹���� ������

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

	ec_add_child(h1, h2); // h2�� h1�� �ڽ�������� ���� 

	ec_process_message();

}