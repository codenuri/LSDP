#define USING_GUI
#include "cppmaster.h" 

// ������ ��� �ϴ� ������(Proxy) �� ����� ���ô�.
// ����
// 1. 1, 2��� ����ڵ� ���ٴ� �Լ��̸��� ����
// 2. Calc Ŭ���� �ܿ� �ٸ� �������� IPC ���� �ڵ带 ���ʿ� ����.
// 3. ���� ���Ӱ����� �����ǰ� update �Ҽ� �ִ�

class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{  
	Calc* calc = new Calc;

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}





