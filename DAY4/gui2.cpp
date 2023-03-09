#define USING_GUI
#include "gui.h"  




class Window
{
	int handle; // ������ ��ȣ
public:
	void Create(const std::string& title)
	{
		handle = ec_make_window(&handler, title);
	}

	// �ٽ� 1. ec_make_window �� 1��° ���ڴ� �ݵ�� ���ڰ�
	//        4���� �Լ��� ���� �����մϴ�
	// 
	// 2. �Ʒ� �Լ����� static �� ���� this�� �߰��Ǿ ���ڰ�
	//    5���� �˴ϴ�. �׷��� static

	// �Ϲ��Լ� : Window private ���� �ȵ�
	// static��� : private ���� ����.
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