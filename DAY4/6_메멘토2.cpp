// 8_메멘토 - 178
#include <iostream>
#include <vector>
#include <map>

class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

	// 저장할필요가 있는 데이타만 관리하는 타입
	struct MEMENTO
	{
		int penWidth;
		int penColor;
	};
	int token_number = 0;

	std::map<int, MEMENTO*> memento_map;

public:
	int Save()
	{
		MEMENTO* p = new MEMENTO;
		p->penColor = penColor;
		p->penWidth = penWidth;

		++token_number;
		memento_map[token_number] = p;

		return token_number;
	}

	void Restore(int key)
	{
		MEMENTO* p = memento_map[key];

		penColor = p->penColor;
		penWidth = p->penWidth;
	}


	void DrawLine(int x1, int y1, int x2, int y2)
	{
	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
};




int main()
{
	Graphics g;

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200); 

	int token = g.Save();	// 캡슐화를 위배 하지 않고
							// 객체의 상태를 저장/복구할수 있게 한다
							// "Memento" 패턴

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 처음에 그렸던 선과 동일하게 그리고 싶다.
	g.Restore(token);
}









