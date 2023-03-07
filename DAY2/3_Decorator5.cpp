#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class FileStream
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
		printf("%s ����\n", s.c_str() );
	}
};

int main()
{
	// C��� ���� : �ڿ��� ���� �����Ѵٴ� ��.
	FILE* f = fopen("a.txt", "wt");
	fclose(f);

	// C++�� ������/�Ҹ��ڷ� �ڿ������� �ǹǷ� ���մϴ�.
	FileStream fs("a.txt");
	fs.write("AAA");

	// fs �� �ı��ɶ� �ڵ����� ���� �ݰ� �˴ϴ�. 
	// �ڵ����� �ڿ� ����
}