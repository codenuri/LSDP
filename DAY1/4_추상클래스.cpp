// �߻� Ŭ���� : ���� ���� �Լ��� �Ѱ� �̻� �ִ� Ŭ����
// Ư¡ : ��ü�� ����� ����.
// �ǵ� : Ư�� ��� �Լ�(�޼ҵ�)�� �ݵ�� ������
//       �Ļ� Ŭ�������� �����ϴ� ��.
class Shape
{
public:
	virtual void Draw() = 0;  // ���� �����Լ�
							// pure virtual function
};

class Rect : public Shape
{
public:
	// Draw()�� �����θ� �������� ������ ���� �߻� Ŭ����!
	// Draw()�� �����θ� �����ϸ� �߻� Ŭ���� �ƴ�.
	virtual void Draw() {}
};

int main()
{
	Shape s; // error 
	Rect  r;
}

