#include <iostream>
#include <mutex>

// �׻� �ڿ������� ������/�Ҹ��ڿ� �����ؾ� �մϴ�.
// lock/unlock �� ������/�Ҹ��ڷ� ����
template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};

// �Լ� �ȿ��� ���� �߻���
// ���������� �����ϰ� �ĵ�(�Ҹ���)�ȴٴ� ������ �ֽ��ϴ�.
// �׷��� �ڿ� ������ �����ϰ� �Ҽ� �ֽ��ϴ�.
// => ���� Ǯ��(stack unwinding) �̶�� �����Դϴ�.



class Cursor
{
private:
	Cursor() {}
private:
	Cursor(const Cursor&);
	Cursor& operator=(const Cursor&);


	static Cursor* instance;
	static std::mutex mtx;
public:
	static Cursor& getInstance()
	{
		{
			std::lock_guard<std::mutex> g(mtx); // ǥ�ؿ� ����
			//		lock_guard<std::mutex> g(mtx);
			//		mtx.lock();

			if (instance == 0)
				instance = new Cursor;

			//		mtx.unlock();
		}
		return *instance;
	}
};
Cursor* Cursor::instance = 0;
std::mutex Cursor::mtx;




int main()
{
	Cursor& c1 = Cursor::getInstance();

}








