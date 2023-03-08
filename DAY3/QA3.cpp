#include <iostream>
#include <vector>
#include <list>

/*
void print(std::vector<int>& v)
{
	int n = v.front();
	std::cout << n << std::endl;
}
*/
/*
template<typename T>
void print(std::vector<T>& v)
{
	T n = v.front();

	std::cout << n << std::endl;
}
*/
template<typename T>
void print(T& v)
{
	// ? 채워 보세요, auto 사용하지 말고..

	// T : list<double>

	typename T::value_type n = v.front();

	auto n2 = v.front();

	std::cout << n << std::endl;
}

int main()
{
//	std::vector<int> v = { 1,2,3 };
//	std::vector<double> v = { 1,2,3 };
	std::list<double> v = { 1,2,3 };

	print(v);
}

/*
// STL 의 설계원리(컨테이너가 가진 요소의 타입을 알려주고 있다.)
template<typename T> class list
{
public:
	typedef T value_type; // 요소의 타입을 value 타입으로!!
};

list<int> s;
list<double> s;

std::list<int>::value_type n; // n은 int 타입
*/