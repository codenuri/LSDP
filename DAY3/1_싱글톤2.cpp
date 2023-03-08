#include <iostream>


// ���� �Ѱ��� ��ü�� static ��� ����Ÿ�� ���� ���

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








