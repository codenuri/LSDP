#include <iostream>
#include <vector>

struct IGraph
{
	virtual void update(int n) = 0;
	virtual ~IGraph() {}
};

// 관찰자 패턴의 기본 로직을 제공하는 기반 클래스를 설계 합니다.
// 디자인 패턴에서는 "관찰의 대상" 이라는 의미로 Subject라고 부릅니다.
class Subject
{
	std::vector< IGraph* > v;
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}

	void notify(int n)
	{
		for (auto p : v)
			p->update(n);
	}
};

class Table : public Subject
{
	int data;
public:
	void edit()
	{
		while (1)
		{
			std::cout << "input data >> ";
			std::cin >> data;
			notify(data); 
		}
	}
};

class PieGraph : public IGraph
{
public:
	void update(int data) override
	{
		std::cout << "PieGraph : ";

		for (int i = 0; i < data; i++)
			std::cout << ")";

		std::cout << std::endl;
	}
};
class BarGraph : public IGraph
{
public:
	void update(int data) override
	{
		std::cout << "BarGraph : ";

		for (int i = 0; i < data; i++)
			std::cout << "+";

		std::cout << std::endl;
	}
};
int main()
{
	Table table;
	PieGraph pg; table.attach(&pg);
	BarGraph bg; table.attach(&bg);
	table.edit();
}
