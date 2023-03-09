// 방법 2. 변하는 것을 다른 클래스로
// => 인터페이스 기반 교체
// => 메모리 할당정책을 다른 곳에서도 사용가능

struct IAlloc
{
	virtual void* alloc(int size) = 0;
	virtual void free(void*) = 0;
	virtual ~IAlloc() {}
};
template<typename T> class vector
{
	IAlloc* palloc = 0;
public:
	void set_alloc(IAlloc* p) { palloc = p; }

	void resize(int size)
	{
		T* buff = palloc->alloc(size);
		palloc->free(buff);
	}
};