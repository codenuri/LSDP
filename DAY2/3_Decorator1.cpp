#include <iostream>

class SpaceShip // 우주 비행선
{
public:
	void fire()	{ std::cout << "Fire Missile" << std::endl; }
};
// 클래스에 기능을 추가해 봅시다.
// 상속을 사용한 기능의 추가
// => 클래스에 기능을 추가하는 것
// => 객체에 기능을 추가하는 것이 아니다(아래 main주석 참고)

class LeftMissile : public SpaceShip
{
public:
	void fire()
	{
		SpaceShip::fire(); // 기존 기능 수행
		std::cout << "Fire Left Missile" << std::endl;

	}
};

int main()
{
	SpaceShip ss;
	ss.fire();

	LeftMissile lm; // ss 라는 이미 존재하는 객체에 기능을 
					// 추가한 것이 아니라
					// 기능이 추가된 새로운 객체를 생성한것
					// 즉, 새로운 우주선이 나타난 것
	lm.fire();
}