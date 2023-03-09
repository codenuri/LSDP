#include <iostream>

// 책임의 고리(전가, chain of responsibility)

struct Handler
{
	Handler* next = nullptr;

	void Handle(int problem)
	{
		// 1. 자신이 먼저 처리를 시도
		if (HandleRequest(problem) == true)
			return;

		// 2. 처리를 못한 경우 고리에 따라 연결된 다음 객체에 전달
		if (next != 0)
			next->Handle(problem);
	}

	virtual bool HandleRequest(int problem) = 0;
};

class SevenHandler : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "start SevenHandler" << std::endl;

		if (problem == 7)
		{
			std::cout << "resolve by SevenHandler\n";
			return true;
		}
		return false;
	}
};
class OddHandler : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "start OddHandler" << std::endl;

		if (problem % 2 == 1)
		{
			std::cout << "resolve by OddHandler\n";
			return true;
		}
		return false;
	}
};

class EvenHandler : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "start EvenHandler" << std::endl;

		if (problem % 2 == 0)
		{
			std::cout << "resolve by EvenHandler\n";
			return true;
		}
		return false;
	}
};
int main()
{
	SevenHandler sh;
	OddHandler   oh;
	EvenHandler  eh;

	oh.next = &eh;
	sh.next = &oh;

	// seven => odd => even

//	sh.Handle(7); // 7번 문제 발생.
//	sh.Handle(11);
	sh.Handle(12);
}