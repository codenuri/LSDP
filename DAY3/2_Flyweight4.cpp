#include <iostream>

int main()
{
	// char �迭 vs char ������
	char s1[] = "ABCD";
//	char* s2 = "ABCD"; // C ok, C++����
//	*s2 = 'X'; // C���� runtime error

//	const char* s2 = "ABCD"; // C++�� �̷��� �ؾ�..
//	*s2 = 'A'; // ������ ����.. const char* �̹Ƿ�


	const char* p1 = "hello";
	const char* p2 = "hello";

	printf("%p, %p\n", p1, p2);
}