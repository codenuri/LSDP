#include <iostream>
using namespace std;

struct ISharedMemory
{
	virtual void* Alloc() = 0;
	virtual void Free() = 0;
};

class Win32SharedMemory : public ISharedMemory
{
public:
	virtual void* Alloc() {}
	virtual void Free() {}
};
class LinuxSharedMemory : public ISharedMemory
{
public:
	virtual void* Alloc() {}
	virtual void Free() {}
};

// 사용자는 아래 추상 계층을 사용하도록 합니다.
class SharedMemory
{
	ISharedMemory* impl;
public:
	SharedMemory(ISharedMemory* p = 0) : impl(p)
	{
		if (impl == 0)
			impl = new LinuxSharedMemory;
	}

	void* Alloc() { return impl->Alloc(); }
	void Free() { impl->Free(); }
};
	 
//-----------------------
class Stack : public SharedMemory {};
class Tree : public SharedMemory {};



