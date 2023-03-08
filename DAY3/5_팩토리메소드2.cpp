// 5_팩토리메소드
#include <iostream>

// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//--------------------------------------
class BaseDialog
{
public:
	void init()
	{
		IButton* btn = CreateButton();
		IEdit* edit = CreateEdit();

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
	// Template Method : 알고리즘(정책)의 결정(변경) 
	// Factory Method  : 객체의 종류를 결정
	// 객체를 만들기 위한 인터페이스를 만들고 사용하지만
	// 실제 어떤 객체를 만들지는 파생 클래스가 결정한다.
	// 객체의 종류를 파생 클래스가 결정하는 패턴.
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit() = 0;
};

class WinDialog : public BaseDialog
{
public:
	IButton* CreateButton() override  { return new WinButton; }
	IEdit*   CreateEdit()  override { return new WinEdit; }
};


class OSXDialog : public BaseDialog
{
public:
	IButton* CreateButton() override { return new OSXButton; }
	IEdit* CreateEdit()  override { return new OSXEdit; }
};

int main(int argc, char** argv)
{

}








