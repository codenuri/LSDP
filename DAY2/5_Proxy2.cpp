#define USING_GUI
#include "cppmaster.h" 

// 서버를 대신 하는 대행자(Proxy) 를 만들어 봅시다.
// 장점
// 1. 1, 2라는 명령코드 보다는 함수이름이 쉽다
// 2. Calc 클래스 외에 다른 곳에서는 IPC 관련 코드를 알필요 없다.
// 3. 서버 접속과정을 독립되게 update 할수 있다

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





