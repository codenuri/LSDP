#include <iostream>
#include <vector>

class Subject;	// class 전방선언. 완전한 선언이 없어도
				// 포인터 타입 변수는 생성 가능.

struct IGraph
{
	virtual void update(int n) = 0;
	virtual ~IGraph() {}

	// 그래프들도 자신이 어떤 Table과 연결되었는지 알아야한다.
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
		// 이제 Table이 바뀌었다는 사실을 알았으므로
		// Table에 접근해서 변경된 데이타를 읽어 온다.

		// psubject : Subject*
		// getColor : Table의 멤버 함수
//		int* color = psubject->getColor();  // error

		// MFC, QT 등에서 관찰자 패턴을 널리 사용하는데..
		// 이때 꼭 이 부분에서 캐스팅이 등장 합니다.
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
