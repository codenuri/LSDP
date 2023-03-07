#define USING_GUI
#include "cppmaster.h" 

// RPC : Remote Procedure Call (다른 프로세스의 함수를 호출하는것)
//      java 의 RMI(Remote Method Invocation)

// 서버에 있는 모든 기능을 Proxy 도 동일한 이름으로 노출함을 보장하기
// 위해 인터페이스 설계

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





