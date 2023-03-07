// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h" 
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// 클라이언트 제작자는 Proxy 의 클래스 이름을 알지도 못하고
// 알아도 안됩니다.
// DLL 내부에서  Proxy 객체를 만드는 약속된 함수를 제공합니다.
extern "C" __declspec(dllexport)
ICalc* Create()
{
	return new Calc;
}

// CalcProxy.cpp 를 DLL로 빌드 하는 법
// 
// cl CalcProxy.cpp /LD     => /LD 가 dll 로 빌드하는 옵션
