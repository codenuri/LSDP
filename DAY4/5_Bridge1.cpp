// 6_Bridge1 - 90 page
#include <iostream>

// ��� MP3 �÷��̾��� �������̽�
struct IMP3
{
	virtual void Play() = 0;
	virtual void Stop() = 0;
	virtual ~IMP3() {}
};

class IPod : public IMP3
{
public:
	void Play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void Stop() { std::cout << "Stop" << std::endl; }
};

// DIP ( Dependency Inversion Principle)
// => ��ü(concrete, IPod)�� �������� ���� �߻�(IMP3)�� �����ض�!

class People
{
public:
	void Use(IMP3* p)
	{
		p->Play();
		p->Stop();

		// ����ڰ� "1�� �̸����" ����� �䱸�Ѵ�.
		// => IMP3�� �����ؾ� �ϴ� ������ �ȴ�.
		// => �������̽��� �����ϴ� ���� �����
		// => "�������̽� ������ ��Ģ"
	}
};


int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


