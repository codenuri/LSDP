#include <iostream>

// å���� ��(����, chain of responsibility)

struct Handler
{
	Handler* next = nullptr;

	void Handle(int problem)
	{
		// 1. �ڽ��� ���� ó���� �õ�
		if (HandleRequest(problem) == true)
			return;

		// 2. ó���� ���� ��� ���� ���� ����� ���� ��ü�� ����
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

//	sh.Handle(7); // 7�� ���� �߻�.
//	sh.Handle(11);
	sh.Handle(12);
}