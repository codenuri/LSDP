
template<typename T> class Generic1 {};
template<int N>      class Generic2 {};

template< template<typename> class C > class Generic3 {};

int main()
{
//	Generic1      g1; // error. Generic1 은 타입이 아닌 템플릿
	Generic1<int> g2;
	Generic2<100> g3;

	Generic3<Generic1<int>> g4; // error. Generic1<int> 는타입
	Generic3<Generic1> g4;      // ok Generic1 은 템플릿
}