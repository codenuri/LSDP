#include <iostream>

// �̱��� : ���� �Ѱ��� ��ü�� �����ϴ� ��.
//		   ���α׷��� ��𼭵� �ش� ��ü��
//		   ������ ������� �����Ҽ� �ְ� �ϴ� ��

// ���� 
// => �����Ѱ� �ְ�, ��𼭵� ���ٰ����ϸ� ?
//    �ᱹ "��������" �̴�.
//    ������ ���� �޴� ����!!

// ���� �Ѱ��� ��ü�� ��� ������ΰ� ?
// 1. static ���������� - "meyer's singleton"
//		effective-c++ å�� ������ scott meyer �� ó�� ���� 


class Cursor
{
	// ��Ģ 1. �����ڴ� private ��
private:
	Cursor() {}

	// ��Ģ 2. �����Ϸ��� ���� �����ڿ� ���Կ����ڸ� ����� ����..
	// => C++11 �Լ� ���� ����
//	Cursor(const Cursor&) = delete;
//	Cursor&  operator=(const Cursor&) = delete;

	// C++11�� �������� �ʴ� ȯ���̶��
	// => ���� �����ڸ� private ������ ���� ����
private:
	Cursor(const Cursor&);
	Cursor& operator=(const Cursor&);

	// ��Ģ 3. ���� �Ѱ��� ��ü�� ���� ��ȯ�ϴ�
	//		  static ��� �Լ�
public:
	static Cursor& getInstance()
	{
		static Cursor c;
		return c;
	}
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

	Cursor c3 = c1; // ���� ������ ���
					// �� �ڵ嵵 �ȵǰ� ���ƾ� �մϴ�.
					
//	Cursor c1, c2; // error
}








