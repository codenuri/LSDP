#include <iostream>
#include <mutex>

// 항상 자원관리는 생성자/소멸자에 의존해야 합니다.
// lock/unlock 도 생성자/소멸자로 관리
template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};

// 함수 안에서 예외 발생시
// 지역변수는 안전하게 파되(소멸자)된다는 보장이 있습니다.
// 그래서 자원 관리를 안전하게 할수 있습니다.
// => 스택 풀기(stack unwinding) 이라는 개념입니다.



class Cursor
{
private:
	Cursor() {}
private:
	Cursor(const Cursor&);
	Cursor& operator=(const Cursor&);


	static Cursor* instance;
	static std::mutex mtx;
public:
	static Cursor& getInstance()
	{
		{
			std::lock_guard<std::mutex> g(mtx); // 표준에 있음
			//		lock_guard<std::mutex> g(mtx);
			//		mtx.lock();

			if (instance == 0)
				instance = new Cursor;

			//		mtx.unlock();
		}
		return *instance;
	}
};
Cursor* Cursor::instance = 0;
std::mutex Cursor::mtx;




int main()
{
	Cursor& c1 = Cursor::getInstance();

}








