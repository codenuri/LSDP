// 8_�޸��� - 178
#include <iostream>
#include <vector>
#include <map>

class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

	// �������ʿ䰡 �ִ� ����Ÿ�� �����ϴ� Ÿ��
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

	int token = g.Save();	// ĸ��ȭ�� ���� ���� �ʰ�
							// ��ü�� ���¸� ����/�����Ҽ� �ְ� �Ѵ�
							// "Memento" ����

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// ó���� �׷ȴ� ���� �����ϰ� �׸��� �ʹ�.
	g.Restore(token);
}









