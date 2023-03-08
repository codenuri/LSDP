#include <iostream>
#include <mutex>

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
		mtx.lock();
		
		if (instance == 0)
			instance = new Cursor;

		mtx.unlock();

		return *instance;
	}
};
Cursor* Cursor::instance = 0;
std::mutex Cursor::mtx;




int main()
{
	Cursor& c1 = Cursor::getInstance();

}








