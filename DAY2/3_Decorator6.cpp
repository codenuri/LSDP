#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// ��� ������ Stream �� �Լ� �̸��� ����ϴ� �������̽�

struct Stream
{
	virtual void write(const std::string&) = 0;
	virtual ~Stream() {}

	// �׿ܿ� read, isOpen, flush ���� IO ���� �Լ���...
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
		printf("%s ����\n", s.c_str());
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