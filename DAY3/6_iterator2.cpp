#include <iostream>


int main()
{
	slist<int> s = { 1,2,3,4,5 }; // 모든 요소가 떨어진 메모리
	vector<int> v = { 1,2,3,4,5 }; // 모든 요소가 연속된 메모리

	// iterator 패턴
	// 복합객체의 내부 구조를 노출하지 않고도
	// 동일한 방법으로 모든 요소를 순차적으로 접근하게 한다.
	
	siterator p1 = s.GetEnumerator();
	viterator p2 = v.GetEnumerator();

	do 
	{
		int n = p1->GetObject();
	} while (p1->MoveNext());
}