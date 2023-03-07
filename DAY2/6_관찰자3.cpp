#include <iostream>
#include <vector>

class Subject;	// class ���漱��. ������ ������ ���
				// ������ Ÿ�� ������ ���� ����.

struct IGraph
{
	virtual void update(int n) = 0;
	virtual ~IGraph() {}

	// �׷����鵵 �ڽ��� � Table�� ����Ǿ����� �˾ƾ��Ѵ�.
	Subject* psubject = 0;
};



class Subject
{
	std::vector< IGraph* > v;
public:

	void attach(IGraph* p) 
	{ 
		v.push_back(p); 

		p->psubject = this;
	}

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

	int color[10] = { 1,2,3,4,5,6,7,8,9,10 };
public:
	int* getColor() { return color; }

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
		// ���� Table�� �ٲ���ٴ� ����� �˾����Ƿ�
		// Table�� �����ؼ� ����� ����Ÿ�� �о� �´�.

		// psubject : Subject*
		// getColor : Table�� ��� �Լ�
//		int* color = psubject->getColor();  // error

		// MFC, QT ��� ������ ������ �θ� ����ϴµ�..
		// �̶� �� �� �κп��� ĳ������ ���� �մϴ�.
		Table* table = static_cast<Table*>(psubject);

		int* color = table->getColor();


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
