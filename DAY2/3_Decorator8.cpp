#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>


struct Stream
{
	virtual void write(const std::string&) = 0;
	virtual ~Stream() {}
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

class EncryptDecorator : public Stream
{
	Stream* stream; // �ܺο� �ִ� ��Ʈ����ü(����, ��Ʈ��ũ)
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	void write(const std::string& s)
	{
		auto s2 = s + " ��ȣȭ ��";

		stream->write(s2);
	}
};
class ZipDecorator : public Stream
{
	Stream* stream; // �ܺο� �ִ� ��Ʈ����ü(����, ��Ʈ��ũ)
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void write(const std::string& s)
	{
		auto s2 = s + " ���� ��";

		stream->write(s2);
	}
};


int main()
{
	FileStream fs("a.txt");
	fs.write("AAA");

	EncryptDecorator es(&fs);
	es.write("AAA"); 

	ZipDecorator zs(&es);
	zs.write("AAA"); 
}
// C# ���

// �����				Decorator
// 
// FileStream		XMLStream
// NetworkStream	GZipStream
// PipeStream		EncryptStream
//					HtmlStream