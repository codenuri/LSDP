#include <iostream>

// 2. 변하는 것을 가상함수로!

class Charater
{
	int gold;
	int item;
public:
	void run()    { doRun();  }
	void attack() { doAttack(); }

	virtual void doRun() 
	{
		std::cout << "run" << std::endl;
	}
	virtual void doAttack()
	{
		std::cout << "attack" << std::endl;
	}
};
// 아이템을 획득했을때 동작의 변경
class StarItem : public Charater
{
public:
	void doRun() override 
	{
		std::cout << "fast run" << std::endl;
	}
	void doAttack() override
	{
		std::cout << "power attack" << std::endl;
	}
};

int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	p = new StarItem; // 기존 캐릭터의 동작 변경이 아니라
					  // 동작이 변경된 새로운 캐릭터
					  // 우리가 필요한것은
					  // 동일한 객체인데, 멤버 함수만 변경되어야한다.
					//                 멤버 데이타(상태)는 유지
	p->run();
	p->attack();
}



