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

// 위 Calc 클래스는 누가 만들게 될까요 ?
// 1. Server 만드는 사람
// 2. Client 만드는 사람

int main()
{
	// 아래 처럼 만들면 클라이언트와 Proxy 사이에 강한 결합이 됩니다.
	// 새로운 Proxy 가 배포 되면
	// 모든 Client 코드를 수정해야 합니다.
//	Calc* calc = new Calc;

	// 클라이언트는 Proxy 사용시 약한 결합을 사용해야 합니다.
	ICalc* calc = ? ? ;


	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}





