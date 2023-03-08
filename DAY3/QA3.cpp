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
	// ? ä�� ������, auto ������� ����..

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
// STL �� �������(�����̳ʰ� ���� ����� Ÿ���� �˷��ְ� �ִ�.)
template<typename T> class list
{
public:
	typedef T value_type; // ����� Ÿ���� value Ÿ������!!
};

list<int> s;
list<double> s;

std::list<int>::value_type n; // n�� int Ÿ��
*/