// 6_관찰자1
#include <iostream>
#include <vector>

// 모든 그래프들의 공통의 인터페이스
struct IGraph
{
	virtual void update(int n) = 0;
	virtual ~IGraph() {}
};

// 관찰의 대상
class Table
{
	int data;
	std::vector< IGraph* > v;
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}

	void notify(int n)
	{
		// 등록된 모든 Graph에 통보
		for (auto p : v)
			p->update(n); 
	}
	void edit()
	{
		while (1)
		{
			std::cout << "input data >> ";
			std::cin >> data;
			notify(data); // data가 수정되었으므로
						  // 모든 관찰자에게 알려준다.
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
