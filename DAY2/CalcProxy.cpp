#define USING_GUI
#include "cppmaster.h" 
#include "ICalc.h"
#include <atomic>

class Calc : public ICalc
{
	int server;

	std::atomic<int> cnt = 0; 
public:
	
	void AddRef()  { ++cnt; }
	void Release() { if (--cnt == 0) delete this; }

	~Calc() { std::cout << "~Calc" << std::endl; }




	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

extern "C" __declspec(dllexport)
ICalc * Create()
{
	return new Calc;
}

