struct Test
{
	inline static int data = 10;
	typedef int DWORD;
};
int  p = 0;

template<typename T>
typename T::DWORD foo(T a)
{
	// �Ʒ� 2�� �ؼ��� ������
	Test::data  * p;  // *�� �ǹ� : ���ϱ�
	Test::DWORD * p;  // *�� �ǹ� : ������ ������

	// "Ŭ�����̸�::�̸�" ���� "�̸�" ��?
	// �� �ϼ� �ְ�, Ÿ�� �ϼ� �ֽ��ϴ�.

	// dependant name : ���ø� ���� T�� ������ �̸�
	//					�����Ϸ��� �⺻������ ������ �ؼ�
	T::data*  p; 
	typename T::DWORD* p;

	return 0;
}
int main()
{

}