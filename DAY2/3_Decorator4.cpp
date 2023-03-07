#include <iostream>

// Composite 와 Decorator 패턴은
// => 클래스 다이어그램이 거의 동일 합니다.

// 모두 재귀적 포함을 사용하는 기술입이다.
// => A는 B를 포함 하지만 A 자신도 포함한다.












// 우주선과 기능추가 클래스 들은 공통의 기반 클래스가 있으면
// 중첩해서 기능을 추가할수 있다.
// => 포장지는 사물을 포장하지만 
//    포장된 사물을 다시 포장할수 있다

struct Component
{
	virtual void fire() = 0;
	virtual ~Component() {}
};


class SpaceShip : public Component
{
public:
	void fire() { std::cout << "Fire Missile" << std::endl; }
};
// SpaceShip : 우주선 클래스
// LeftMissile, RightMissile : 우주선에 기능을 추가하는 객체
//							   (Decorator 라고 합니다.)

// Decorator 들은  공통된 특징이 많이 있을수 있습니다.
// 기반 클래스로 제공하면 편리합니다.
class IDecorator : public Component
{
	Component* ship;
public:
	IDecorator(Component* s) : ship(s) {}

	void fire() { ship->fire(); }
};

// 모든 Decorator는 IDecorator에서 파생 받으면 공통의 기능을 
// 물려 받게 됩니다.
class LeftMissile : public IDecorator
{
public:
	LeftMissile(Component* s) : IDecorator(s) {}

	void fire()
	{
		IDecorator::fire();
		std::cout << "Fire Left Missile" << std::endl;
	}
};
class RightMissile : public IDecorator
{
	Component* ship;

public:
	RightMissile(Component* s) : IDecorator(s) {}

	void fire()
	{
		IDecorator::fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};
int main()
{
	SpaceShip ss;
	ss.fire();

	LeftMissile lm(&ss);
	lm.fire();

	//	RightMissile rm(&ss);
	RightMissile rm(&lm); // ??
	rm.fire();
}