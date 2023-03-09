#include <iostream>

// �����ۿ� ���� ����Ǿ�� �ϴ� ��� ��� �Լ���
// �������̽��� ���
struct IAction
{
	virtual void doRun() = 0;
	virtual void doAttack() = 0;
	virtual ~IAction() {}

	// �׿ܿ� slide(), jump(), fly()��... ĳ������ ��� ��������
};


class Charater
{
	int gold;
	int item;
	IAction* paction = 0;
public:
	void setAction(IAction* p) { paction = p; }

	void run()    { paction->doRun();}
	void attack() { paction->doAttack(); }
};
// �� ĳ������ �� ������ �����ϴ� Ŭ������ ����
class NoItem : public IAction
{
public:
	void doRun()    override { std::cout << "run" << std::endl; }
	void doAttack() override { std::cout << "attack" << std::endl; }
};
class RedItem : public IAction
{
public:
	void doRun()    override { std::cout << "fast run" << std::endl; }
	void doAttack() override { std::cout << "attack" << std::endl; }
};
class StarItem : public IAction
{
public:
	void doRun()    override { std::cout << "fast run" << std::endl; }
	void doAttack() override { std::cout << "power attack" << std::endl; }
};
int main()
{
	NoItem ni;
	StarItem si;
	RedItem ri;
	Charater* p = new Charater;
	p->setAction(&ni);
	p->run();
	p->attack();

	p->setAction(&si); // �̼��� ��ġ p�� �ٸ� Ŭ����ó�� ����˴ϴ�.
	p->run();			// ��� ������ ����ǹǷ�
	p->attack();

}

// ������ ���Ͽ��� ���ϴ� ���� �������̽� ������� ��ü�ϴ�
// (Ŭ���� Diagram �� ������) ������ 3�� �Դϴ�.
// strategy : ��ü�� ����ϴ� �˰����� ��ü
// 
// state    : ��ü�� ���¿� ���� ��� ������ ��ü
// 
// builder  : ������ ��ü�� ����� ������ �����ѵ� 
//			  �� ������ ����� �ٸ��� ���



