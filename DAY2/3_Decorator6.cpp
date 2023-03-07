#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// 모든 종류의 Stream 의 함수 이름을 약속하는 인터페이스

struct Stream
{
	virtual void write(const std::string&) = 0;
	virtual ~Stream() {}

	// 그외에 read, isOpen, flush 등의 IO 관련 함수들...
};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void write(const std::string& s)
	{
		printf("%s 쓰기\n", s.c_str());
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("AAA");

	NetworkStream ns("127.0.0.1", 400);
	ns.write("AAA");

	PipeStream ps("pipename");
	ps.write("AAA");
}