// 5_���丮�޼ҵ�
#include <iostream>

// ��� ������ ��Ʈ���� ������ ��� Ŭ���� �ʿ�
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
// �Ʒ� Ŭ������ ���� Ÿ���� �̸��� �����ϴ� Ŭ���� �Դϴ�.
// �������ϵ� ����, ��ü�� �������� �����Ƿ� ����ð� ������� �����ϴ�.
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








