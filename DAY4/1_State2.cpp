#include <iostream>

// 방법 1. Item 상태에 따른 조건 분기

// => 모든 동작함수에 분기문 필요하다.
// => 새로운 Item 이 등장하면 모든 함수에 코드가 추가 되어야 한다.
// => OCP 위반
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



