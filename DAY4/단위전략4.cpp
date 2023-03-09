template<typename T, typename Alloc> class vector
{
	Alloc ax; // �޸� �Ҵ�� ��ü
public:
	void resize(int size)
	{
		T* p = ax.allocate(size);

		ax.deallocate(p);
	}
};
// �޸� �Ҵ��� �ݵ�� allocate, deallocate�� �־�� �Ѵ�.
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