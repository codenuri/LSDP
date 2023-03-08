#include <iostream>
#include <mutex>

// CRTP : Curiously Recurring Template Pattern
// => 미래에 만들어질 파생 클래스의 이름을 
//    기반 클래스 만들때 사용할수 있게 하는 기술
//    원리는 파생 클래스가 기반클래스 템플릿 인자로 자신의 이름전달

template<typename T>
class Singleton
{
protected:
	Singleton() {}
private:
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);

	static T* instance;			//<<===
	static std::mutex mtx;	
public:
	static T& getInstance()		//<<===
	{
		std::lock_guard<std::mutex> g(mtx); 

		if (instance == 0)
			instance = new T;	// <<==

		return *instance;
	}
};

template<typename T> T* Singleton<T>::instance = 0;
template<typename T> std::mutex Singleton<T>::mtx;

//----------------------
// Keyboard 클래스도 힙에 만드는 싱글톤을 사용하고 싶다.
class Keyboard : public Singleton< Keyboard >
{

};


int main()
{
	Keyboard& c1 = Keyboard::getInstance();

}








