#define USING_GUI
#include "cppmaster.h" 


#include "ICalc.h"

ICalc* reload_proxy()
{
	void* addr = ec_load_module("CalcProxy.dll");

	typedef ICalc* (*F)(); 

	F f = (F)ec_get_function_address(addr, "Create");

	ICalc* calc = f(); 

	return calc;
}


int main()
{
	ICalc* calc = reload_proxy();
					// �� ���� DLL ���ο��� "new Calc"�ϰԵ˴ϴ�.
					// ����Ŀ��� �ݵ�� "delete" �ؾ� �մϴ�.
	calc->

//	delete calc; // ?? ���� �ڵ��ΰ��� ?
				 // ������� ���ο��� �Ҵ��� �ڿ���
				 // ������� ���ο��� ���� �ϴ� ���� ���� ���� �ڵ��Դϴ�





}





