#include <iostream>

// 아이템에 따라 변경되어야 하는 모든 멤버 함수를
// 인터페이스로 약속
struct IAction
{
	virtual void doRun() = 0;
	virtual void doAttack() = 0;
	virtual ~IAction() {}

	// 그외에 slide(), jump(), fly()등... 캐릭터의 모든 동작정의
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
// 이 캐릭터의 각 동작을 정의하는 클래스들 설계
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

	p->setAction(&si); // 이순간 마치 p가 다른 클래스처럼 변경됩니다.
	p->run();			// 모든 동작이 변경되므로
	p->attack();

}

// 디자인 패턴에서 변하는 것을 인터페이스 기반으로 교체하는
// (클래스 Diagram 이 동일한) 패턴은 3개 입니다.
// strategy : 객체가 사용하는 알고리즘의 교체
// 
// state    : 객체의 상태에 따라 모든 동작을 교체
// 
// builder  : 복잡한 객체를 만드는 공정은 동일한데 
//			  각 공정의 결과가 다를때 사용



