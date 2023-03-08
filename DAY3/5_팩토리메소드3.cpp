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
// 아래 클래스는 단지 타입의 이름만 보관하는 클래스 입니다.
// 성능저하도 없고, 객체도 생성하지 않으므로 실행시간 오버헤드 없습니다.
struct WinControl
{
	using Button = WinButton;  // typedef WinButton Button
	using Edit = WinEdit;
};
struct OSXControl
{
	using Button = OSXButton;  
	using Edit = OSXEdit;
};

template<typename T>
class Dialog
{
public:
	void init()
	{
		IButton* btn = new T::Button;
		IEdit* edit  = new T::Edit;

		btn->Draw();
		edit->Draw();
	}
};

int main(int argc, char** argv)
{
	Dialog<OSXControl> dlg;
}








