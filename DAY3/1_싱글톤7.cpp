#include <iostream>

#define MAKE_SINGLETON(classname)						\
private:												\
	classname() {}										\
	classname(const classname&) = delete;				\
	classname&  operator=(const classname&) = delete;	\
public:													\
	static classname& getInstance()						\
	{													\
		static classname c;								\
		return c;										\
	}


class Cursor
{
	MAKE_SINGLETON(Cursor)
};

int main()
{
	Cursor& c1 = Cursor::getInstance();

}








