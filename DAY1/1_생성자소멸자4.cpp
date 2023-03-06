// 9:50 분에 시작합니다.


// protected 생성자 의미
// => 자신은 객체를 만들수 없지만(추상적인 존재)
// => 파생 클래스는 객체를 만들수 있게 하겠다.(구체적인 존재)

// abstract <=> concrete    디자인 패턴에서 사용되는 용어


class Animal
{
protected:
	Animal() {}
};

class Dog : public Animal
{
public:
//	Dog() : Animal() {} <<== 컴파일러가 이렇게 생성
};

int main()
{
	// 다음중 에러를 모두 고르세요..
	Animal	a; // error
	Dog     d; // ok
}



