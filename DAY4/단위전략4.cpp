template<typename T, typename Alloc> class vector
{
	Alloc ax; // 메모리 할당기 객체
public:
	void resize(int size)
	{
		T* p = ax.allocate(size);

		ax.deallocate(p);
	}
};
// 메모리 할당기는 반드시 allocate, deallocate가 있어야 한다.
class MyAlloc
{
public:
	inline int* allocate(int size) { return new int[size]; }
	inline void deallocate(int* p) { return delete[] p; }
};

int main()
{
	vector<int, MyAlloc> v;
}