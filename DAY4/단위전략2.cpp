// 방법 1. 변하는 것을 가상함수로
// => 메모리 할당 변경하려면 파생 클래스 만들어라
// => 다양한 컨테이너가 이방식을 사용할때
//    메모리 할당 정책을 재사용할수 없다.
template<typename T> class vector
{
public:
	void resize(int size)
	{
		T* buff = alloc(size);
		free(buff);
	}
	virtual T* alloc(int sz) { return new T[sz]; }
	virtual void free(T* p) { delete[] p; }
};