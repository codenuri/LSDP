// 9:50 �п� �����մϴ�.


// protected ������ �ǹ�
// => �ڽ��� ��ü�� ����� ������(�߻����� ����)
// => �Ļ� Ŭ������ ��ü�� ����� �ְ� �ϰڴ�.(��ü���� ����)

// abstract <=> concrete    ������ ���Ͽ��� ���Ǵ� ���


class Animal
{
protected:
	Animal() {}
};

class Dog : public Animal
{
public:
//	Dog() : Animal() {} <<== �����Ϸ��� �̷��� ����
};

int main()
{
	// ������ ������ ��� ������..
	Animal	a; // error
	Dog     d; // ok
}



