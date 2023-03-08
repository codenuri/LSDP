class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

class Rect
{
	int n1 = 0; // C++11 부터 초기화 가능합니다.
	int n2 = { 0 }; // C++11 부터 {} 초기화 기능 추가.

//	Point p1(0,0);	// error
	Point p2{ 0,0 };// ok
public:
};

int main()
{

}