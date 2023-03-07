#include <iostream>

class SpaceShip // 우주 비행선
{
public:
	void fire() { std::cout << "Fire Missile" << std::endl; }
};

// 포함을 사용한 기능의 추가
// => 클래스가 아닌 객체에 기능 추가
class LeftMissile  
{
	SpaceShip* ship; // 핵심. 포인터 또는 참조 멤버..

public:
	LeftMissile(SpaceShip* s) : ship(s) {}

	void fire()
	{
		ship->fire(); // 기존에 존재 하는 객체의 기능 사용

		// 새로운 기능을 추가
		std::cout << "Fire Left Missile" << std::endl;

	}
};

int main()
{
	SpaceShip ss;
	ss.fire();

	LeftMissile lm(&ss); // lm 은 ss 객체에 기능을 추가하는 객체
	lm.fire();			// ss의 기능 사용후, 추가된 기능수행.
}