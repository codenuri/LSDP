#include <iostream>

class SpaceShip // ���� ���༱
{
public:
	void fire() { std::cout << "Fire Missile" << std::endl; }
};

// ������ ����� ����� �߰�
// => Ŭ������ �ƴ� ��ü�� ��� �߰�
class LeftMissile  
{
	SpaceShip* ship; // �ٽ�. ������ �Ǵ� ���� ���..

public:
	LeftMissile(SpaceShip* s) : ship(s) {}

	void fire()
	{
		ship->fire(); // ������ ���� �ϴ� ��ü�� ��� ���

		// ���ο� ����� �߰�
		std::cout << "Fire Left Missile" << std::endl;

	}
};

int main()
{
	SpaceShip ss;
	ss.fire();

	LeftMissile lm(&ss); // lm �� ss ��ü�� ����� �߰��ϴ� ��ü
	lm.fire();			// ss�� ��� �����, �߰��� ��ɼ���.
}