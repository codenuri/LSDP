#define USING_GUI
#include "cppmaster.h" 

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

// �� Calc Ŭ������ ���� ����� �ɱ�� ?
// 1. Server ����� ���
// 2. Client ����� ���

int main()
{
	// �Ʒ� ó�� ����� Ŭ���̾�Ʈ�� Proxy ���̿� ���� ������ �˴ϴ�.
	// ���ο� Proxy �� ���� �Ǹ�
	// ��� Client �ڵ带 �����ؾ� �մϴ�.
//	Calc* calc = new Calc;

	// Ŭ���̾�Ʈ�� Proxy ���� ���� ������ ����ؾ� �մϴ�.
	ICalc* calc = ? ? ;


	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}





