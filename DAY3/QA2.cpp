struct Test
{
	inline static int data = 10;
	typedef int DWORD;
};
int  p = 0;

template<typename T>
typename T::DWORD foo(T a)
{
	// 아래 2줄 해석해 보세요
	Test::data  * p;  // *의 의미 : 곱하기
	Test::DWORD * p;  // *의 의미 : 포인터 연산자

	// "클래스이름::이름" 에서 "이름" 은?
	// 값 일수 있고, 타입 일수 있습니다.

	// dependant name : 템플릿 인자 T에 의존한 이름
	//					컴파일러는 기본적으로 값으로 해석
	T::data*  p; 
	typename T::DWORD* p;

	return 0;
}
int main()
{

}