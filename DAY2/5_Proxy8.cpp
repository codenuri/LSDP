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

// AddRef, Release 를 자동으로 해주는 스마트 포인터를 도입하면
// 편리해 집니다.
template<typename T> class sp
{
	T* obj;
public:
	sp(T* p = 0)        : obj(p) { if (obj != 0) obj->AddRef(); }
	sp(const sp& other)
		: obj(other.obj) {if (obj != 0) obj->AddRef();}

	~sp() { if (obj != 0) obj->Release(); }

	// 포인터와 유사하게 동작하기 위해서 -> 와 * 연산자 재정의
	T* operator->() { return obj; }
	T& operator* () { return *obj; }
};

int main()
{
	sp<ICalc> p1 = reload_proxy();
	sp<ICalc> p2 = p1;

	int n = p1->Add(1, 2); // p1.operator->()

	// 현재 스마트 포인터의 목표
	// => DLL 내부에서 delete 되는게 목표 이다.
	// => 우리가 만든 sp는 소멸자에서 Release 호출!!

//	std::shared_ptr<ICalc> p3(reload_proxy());
				// p3의 소멸자에서 "delete" 수행

	std::shared_ptr<ICalc> p3(reload_proxy(), 
								std::mem_fn(&ICalc::Release) );
	p3->AddRef();
}





