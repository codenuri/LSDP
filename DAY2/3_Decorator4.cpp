#include <iostream>

// Composite �� Decorator ������
// => Ŭ���� ���̾�׷��� ���� ���� �մϴ�.

// ��� ����� ������ ����ϴ� ������̴�.
// => A�� B�� ���� ������ A �ڽŵ� �����Ѵ�.












// ���ּ��� ����߰� Ŭ���� ���� ������ ��� Ŭ������ ������
// ��ø�ؼ� ����� �߰��Ҽ� �ִ�.
// => �������� �繰�� ���������� 
//    ����� �繰�� �ٽ� �����Ҽ� �ִ�

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
// SpaceShip : ���ּ� Ŭ����
// LeftMissile, RightMissile : ���ּ��� ����� �߰��ϴ� ��ü
//							   (Decorator ��� �մϴ�.)

// Decorator ����  ����� Ư¡�� ���� ������ �ֽ��ϴ�.
// ��� Ŭ������ �����ϸ� ���մϴ�.
class IDecorator : public Component
{
	Component* ship;
public:
	IDecorator(Component* s) : ship(s) {}

	void fire() { ship->fire(); }
};

// ��� Decorator�� IDecorator���� �Ļ� ������ ������ ����� 
// ���� �ް� �˴ϴ�.
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