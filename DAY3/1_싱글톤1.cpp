#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.
//		   프로그램의 어디서든 해당 객체에
//		   동일한 방법으로 접근할수 있게 하는 것

// 단점 
// => 오직한개 있고, 어디서든 접근가능하면 ?
//    결국 "전역변수" 이다.
//    비판을 많이 받는 패턴!!

// 오직 한개의 객체를 어떻게 만들것인가 ?
// 1. static 지역변수로 - "meyer's singleton"
//		effective-c++ 책의 저자인 scott meyer 가 처음 제안 


class Cursor
{
	// 규칙 1. 생성자는 private 에
private:
	Cursor() {}

	// 규칙 2. 컴파일러가 복사 생성자와 대입연산자를 만들수 없게..
	// => C++11 함수 삭제 문법
//	Cursor(const Cursor&) = delete;
//	Cursor&  operator=(const Cursor&) = delete;

	// C++11이 지원되지 않는 환경이라면
	// => 복사 생성자를 private 영역에 선언만 제공
private:
	Cursor(const Cursor&);
	Cursor& operator=(const Cursor&);

	// 규칙 3. 오직 한개의 객체만 만들어서 반환하는
	//		  static 멤버 함수
public:
	static Cursor& getInstance()
	{
		static Cursor c;
		return c;
	}
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

	Cursor c3 = c1; // 복사 생성자 사용
					// 이 코드도 안되게 막아야 합니다.
					
//	Cursor c1, c2; // error
}








