// ��� 2. ���ϴ� ���� �ٸ� Ŭ������
// => �������̽� ��� ��ü
// => �޸� �Ҵ���å�� �ٸ� �������� ��밡��

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