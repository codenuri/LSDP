#include <iostream>


// 오직 한개의 객체를 static 멤버 데이타로 만든 경우

class Cursor
{
private:
	Cursor() 
	{
		std::cout << "Cursor()" << std::endl;
	}

	static Cursor instance;
private:
	Cursor(const Cursor&);
	Cursor& operator=(const Cursor&);

public:
	static Cursor& getInstance()
	{
		return instance;
	}
};
Cursor Cursor::instance;


int main()
{
//	Cursor& c1 = Cursor::getInstance();

}








