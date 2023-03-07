#define USING_GUI
#include "cppmaster.h" 

// RPC : Remote Procedure Call (�ٸ� ���μ����� �Լ��� ȣ���ϴ°�)
//      java �� RMI(Remote Method Invocation)

// ������ �ִ� ��� ����� Proxy �� ������ �̸����� �������� �����ϱ�
// ���� �������̽� ����

struct ICalc
{
	virtual int Add(int, int) = 0;
	virtual int Sub(int, int) = 0;
	virtual ~ICalc() {}
};

class Calc : public ICalc
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





