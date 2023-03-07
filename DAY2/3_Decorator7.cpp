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

int main()
{
	// ���Ͽ� ���� ��ȣȭ �ϴ� ����� �ʿ� �մϴ�.
	// => ���� ���� ���踦 ã�� ���ô�.

	// 1. ���Ͽ� �������� ����ڰ� ����Ÿ�� ��ȣȭ ����.
	// => ���� �ؾ� �ϸ� �����ϴ�.

	// 2. FileStream �� writeEncrypt()�޼ҵ带 ��������
	// => Network, Pipe ���� �ʿ��ϴ�.

	// 3. Stream �� Encrypt()�޼ҵ带 ��������
	// => ���ο� �䱸������ ���涧���� ���� �ڵ带 �����ϸ� OCP����

	// 4. Decorator �� �������.


	FileStream fs("a.txt");
	fs.write("AAA");

	EncryptDecorator es(&fs);
	es.write("AAA"); // 1. ��ȣȭ �ϴ� ��� �߰�
					 // 2. fs.write(��ȣȭ�� ����Ÿ����)

	ZipDecorator zs(&es);
	zs.write("AAA"); // 1. ������ ����
					 // 2. es.write(����� ����Ÿ)
}