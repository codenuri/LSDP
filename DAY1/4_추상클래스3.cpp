#include <iostream>

// ���Ѱ���(tightly coupling)
// => �ϳ��� Ŭ������ �ٸ� Ŭ���� ���� Ŭ���� �̸��� ���� ���
// => ��ü �Ұ����� ������ ������


// ���Ѱ���(loosely coupling)
// => �ϳ��� Ŭ������ �ٸ� Ŭ���� ���� 
//    ��Ģ�� ���� Ŭ����(�������̽�) �̸��� ���
// 
// => ��ü ������ ������ ������

// �߻� Ŭ���� : ���Ѿ� �ϴ� ��Ģ(���������Լ�) + �ٸ� ���
// ���� ���̽� : ���Ѿ� �ϴ� ��Ģ(���������Լ�)�� �ִ� ���

// java, C# �� abstract, interface ��� ������ Ű���� ����


// ī�޶�� ��� ���̿� ���Ѿ� �ϴ� ��Ģ�� ���� ���� �մϴ�.
// ��Ģ : ��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ� �Ǿ�� �Ѵ�. ��� ���� ����
// ��Ģ : ��� ī�޶�� �Ʒ� �������̽��� ���� �ؾ� �Ѵ�. ��� ǥ��

#define interface struct 

//struct ICamera
interface ICamera
{
	virtual void take() = 0;
	virtual ~ICamera() {}   // ��� Ŭ���� �̹Ƿ�
							// ���� �Ҹ��ڷ�!
};



// ī�޶�� ������ ��Ģ�� �ִ�.
// ����ڴ� ��Ģ ��θ� ����ϸ� �ȴ�.
class People
{
public:
	void useCamera(ICamera* p) { p->take(); }
};

class Camera : public ICamera
{
public:
	void take() { std::cout << "Camera take" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "HDCamera take" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "UHDCamera take" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera hc;
	p.useCamera(&hc); 

	UHDCamera uhc;
	p.useCamera(&uhc); 
}




