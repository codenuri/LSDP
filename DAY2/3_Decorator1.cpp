#include <iostream>

class SpaceShip // ���� ���༱
{
public:
	void fire()	{ std::cout << "Fire Missile" << std::endl; }
};
// Ŭ������ ����� �߰��� ���ô�.
// ����� ����� ����� �߰�
// => Ŭ������ ����� �߰��ϴ� ��
// => ��ü�� ����� �߰��ϴ� ���� �ƴϴ�(�Ʒ� main�ּ� ����)

class LeftMissile : public SpaceShip
{
public:
	void fire()
	{
		SpaceShip::fire(); // ���� ��� ����
		std::cout << "Fire Left Missile" << std::endl;

	}
};

int main()
{
	SpaceShip ss;
	ss.fire();

	LeftMissile lm; // ss ��� �̹� �����ϴ� ��ü�� ����� 
					// �߰��� ���� �ƴ϶�
					// ����� �߰��� ���ο� ��ü�� �����Ѱ�
					// ��, ���ο� ���ּ��� ��Ÿ�� ��
	lm.fire();
}