#include <iostream>

// ��� 1. Item ���¿� ���� ���� �б�

// => ��� �����Լ��� �б⹮ �ʿ��ϴ�.
// => ���ο� Item �� �����ϸ� ��� �Լ��� �ڵ尡 �߰� �Ǿ�� �Ѵ�.
// => OCP ����
class Charater
{
	int gold;
	int item;
public:
	void run() 
	{
		if ( item == 1)
			std::cout << "run" << std::endl; 

		else if ( item == 2 )
			std::cout << "fast run" << std::endl;
	}
	void attack() { std::cout << "attack" << std::endl; }
};



int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();
}



