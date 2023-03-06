// 추상 클래스 : 순수 가상 함수가 한개 이상 있는 클래스
// 특징 : 객체를 만들수 없다.
// 의도 : 특정 멤버 함수(메소드)를 반드시 만들라고
//       파생 클래스에게 지시하는 것.
class Shape
{
public:
	virtual void Draw() = 0;  // 순수 가상함수
							// pure virtual function
};

class Rect : public Shape
{
public:
	// Draw()의 구현부를 제공하지 않으면 역시 추상 클래스!
	// Draw()의 구현부를 제공하면 추상 클래스 아님.
	virtual void Draw() {}
};

int main()
{
	Shape s; // error 
	Rect  r;
}

