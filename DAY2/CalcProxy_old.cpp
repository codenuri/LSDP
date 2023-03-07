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

// Ŭ���̾�Ʈ �����ڴ� Proxy �� Ŭ���� �̸��� ������ ���ϰ�
// �˾Ƶ� �ȵ˴ϴ�.
// DLL ���ο���  Proxy ��ü�� ����� ��ӵ� �Լ��� �����մϴ�.
extern "C" __declspec(dllexport)
ICalc* Create()
{
	return new Calc;
}

// CalcProxy.cpp �� DLL�� ���� �ϴ� ��
// 
// cl CalcProxy.cpp /LD     => /LD �� dll �� �����ϴ� �ɼ�
