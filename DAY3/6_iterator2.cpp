#include <iostream>


int main()
{
	slist<int> s = { 1,2,3,4,5 }; // ��� ��Ұ� ������ �޸�
	vector<int> v = { 1,2,3,4,5 }; // ��� ��Ұ� ���ӵ� �޸�

	// iterator ����
	// ���հ�ü�� ���� ������ �������� �ʰ�
	// ������ ������� ��� ��Ҹ� ���������� �����ϰ� �Ѵ�.
	
	siterator p1 = s.GetEnumerator();
	viterator p2 = v.GetEnumerator();

	do 
	{
		int n = p1->GetObject();
	} while (p1->MoveNext());
}