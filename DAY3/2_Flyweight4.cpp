#include <iostream>

int main()
{
	// char 배열 vs char 포인터
	char s1[] = "ABCD";
//	char* s2 = "ABCD"; // C ok, C++에러
//	*s2 = 'X'; // C언어는 runtime error

//	const char* s2 = "ABCD"; // C++은 이렇게 해야..
//	*s2 = 'A'; // 컴파일 에러.. const char* 이므로


	const char* p1 = "hello";
	const char* p2 = "hello";

	printf("%p, %p\n", p1, p2);
}