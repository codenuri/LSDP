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




