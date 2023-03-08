#include <iostream>
#include <mutex>

// CRTP : Curiously Recurring Template Pattern
// => �̷��� ������� �Ļ� Ŭ������ �̸��� 
//    ��� Ŭ���� ���鶧 ����Ҽ� �ְ� �ϴ� ���
//    ������ �Ļ� Ŭ������ ���Ŭ���� ���ø� ���ڷ� �ڽ��� �̸�����

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
// Keyboard Ŭ������ ���� ����� �̱����� ����ϰ� �ʹ�.
class Keyboard : public Singleton< Keyboard >
{

};


int main()
{
	Keyboard& c1 = Keyboard::getInstance();

}








