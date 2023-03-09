// ��� 1. ���ϴ� ���� �����Լ���
// => �޸� �Ҵ� �����Ϸ��� �Ļ� Ŭ���� ������
// => �پ��� �����̳ʰ� �̹���� ����Ҷ�
//    �޸� �Ҵ� ��å�� �����Ҽ� ����.
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