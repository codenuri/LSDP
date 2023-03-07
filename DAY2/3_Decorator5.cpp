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
		printf("%s 쓰기\n", s.c_str() );
	}
};

int main()
{
	// C언어 단점 : 자원을 직접 관리한다는 점.
	FILE* f = fopen("a.txt", "wt");
	fclose(f);

	// C++은 생성자/소멸자로 자원관리가 되므로 편리합니다.
	FileStream fs("a.txt");
	fs.write("AAA");

	// fs 가 파괴될때 자동으로 파일 닫게 됩니다. 
	// 자동으로 자원 관리
}