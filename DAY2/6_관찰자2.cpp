#include <iostream>
#include <vector>

struct IGraph
{
	virtual void update(int n) = 0;
	virtual ~IGraph() {}
};

// ������ ������ �⺻ ������ �����ϴ� ��� Ŭ������ ���� �մϴ�.
// ������ ���Ͽ����� "������ ���" �̶�� �ǹ̷� Subject��� �θ��ϴ�.
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
