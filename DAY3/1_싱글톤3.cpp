#include <iostream>


// ���� �Ѱ��� ��ü�� ���� ����� ��.

class Cursor
{
private:
	Cursor(){}
private:
	Cursor(const Cursor&);
	Cursor& operator=(const Cursor&);


	static Cursor* instance;
public:
	static Cursor& getInstance()
	{
		if (instance == 0)
			instance = new Cursor;

		return *instance;
	}
};
Cursor* Cursor::instance = 0;


int main()
{
	//	Cursor& c1 = Cursor::getInstance();

}








