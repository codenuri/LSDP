// 6_Bridge1 - 90 page
#include <iostream>

// 모든 MP3 플레이어의 인터페이스
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
// => 구체(concrete, IPod)에 의존하지 말고 추상(IMP3)에 의존해라!

class People
{
public:
	void Use(IMP3* p)
	{
		p->Play();
		p->Stop();

		// 사용자가 "1분 미리듣기" 기능을 요구한다.
		// => IMP3를 변경해야 하는 문제가 된다.
		// => 인터페이스를 수정하는 것은 힘들다
		// => "인터페이스 불편의 법칙"
	}
};


int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


