// 8_�޸��� - 178
#include <iostream>


// ȭ�鿡 �׸��� �׸��� ����ϴ� Ŭ����
class Graphics
{
	// ���鰡���� �׸��� �Լ��� �����մϴ�.
};

int main()
{
	Graphics g;
	g.DrawLine(0, 0, 100, 100);

	// ���� �����̳� �β� ���� �����ϰ� �ͽ��ϴ�.

	// ��� 1. �Լ��� ���ڷ� ���� - windows gdi+
	g.DrawLine(0, 0, 100, 100, red, 10);
	g.DrawLine(0, 0, 100, 100, blue, 20);

	// ��� 2. Graphics ��ü�� �Ӽ��� �����ϵ��� ���� ���� - IOS
	g.SetStrokeColor(red);
	g.SetStrokeLineWidth(20);

	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 100, 100);


}









