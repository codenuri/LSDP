#define USING_GUI
#include "cppmaster.h" 
#include "ICalc.h"
#include <memory> // std::shared_ptr
#include <functional>

ICalc* reload_proxy()
{
	void* addr = ec_load_module("CalcProxy.dll");

	typedef ICalc* (*F)();

	F f = (F)ec_get_function_address(addr, "Create");

	ICalc* calc = f();

	return calc;
}

// AddRef, Release �� �ڵ����� ���ִ� ����Ʈ �����͸� �����ϸ�
// ���� ���ϴ�.
template<typename T> class sp
{
	T* obj;
public:
	sp(T* p = 0)        : obj(p) { if (obj != 0) obj->AddRef(); }
	sp(const sp& other)
		: obj(other.obj) {if (obj != 0) obj->AddRef();}

	~sp() { if (obj != 0) obj->Release(); }

	// �����Ϳ� �����ϰ� �����ϱ� ���ؼ� -> �� * ������ ������
	T* operator->() { return obj; }
	T& operator* () { return *obj; }
};

int main()
{
	sp<ICalc> p1 = reload_proxy();
	sp<ICalc> p2 = p1;

	int n = p1->Add(1, 2); // p1.operator->()

	// ���� ����Ʈ �������� ��ǥ
	// => DLL ���ο��� delete �Ǵ°� ��ǥ �̴�.
	// => �츮�� ���� sp�� �Ҹ��ڿ��� Release ȣ��!!

//	std::shared_ptr<ICalc> p3(reload_proxy());
				// p3�� �Ҹ��ڿ��� "delete" ����

	std::shared_ptr<ICalc> p3(reload_proxy(), 
								std::mem_fn(&ICalc::Release) );
	p3->AddRef();
}





