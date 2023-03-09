// 6_Mediator - 중재자 패턴 
#include <iostream>

class CheckBox
{
	bool state;
public:
	CheckBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	virtual void ChangeState() {}
};

class RadioBox
{
	bool state;
public:
	RadioBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	virtual void ChangeState() {}
};

int main()
{
}



