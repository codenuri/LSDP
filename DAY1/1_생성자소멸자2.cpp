#include <iostream>

// �Ʒ� �ڵ忡�� ������ ã�� ������

class Base
{
public:
	Base(int a) { }
	~Base() {  }
};

class Derived : public Base
{
public:
	// �ٽ� Base�� ����Ʈ �����ڰ� ���ٴ� ��
						// �����Ϸ��� ������ �ڵ�.
//	Derived() {}       // Derived() : Base() {}
//	Derived(int a) { } // Derived(int a) : Base(){ }


	// ��� Ŭ������ ����Ʈ �����ڰ� ���ٸ�
	// �Ļ� Ŭ�������� �ݵ�� ��������� �ٸ� ������ ȣ���ؾ��մϴ�.
	Derived()      : Base(0) {}       
	Derived(int a) : Base(a) {} 

	~Derived() {  }
};

int main()
{

}









