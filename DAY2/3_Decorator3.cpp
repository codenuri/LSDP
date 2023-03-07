#include <iostream>


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


class LeftMissile : public Component
{
	Component* ship;  

public:
	LeftMissile(Component* s) : ship(s) {}

	void fire()
	{
		ship->fire(); 
		std::cout << "Fire Left Missile" << std::endl;
	}
};  
class RightMissile : public Component
{
	Component* ship;

public:
	RightMissile(Component* s) : ship(s) {}

	void fire()
	{
		ship->fire();
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