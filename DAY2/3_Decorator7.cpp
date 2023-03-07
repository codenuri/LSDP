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
		printf("%s 쓰기\n", s.c_str());
	}
};

int main()
{
	// 파일에 쓸때 암호화 하는 기능이 필요 합니다.
	// => 가장 좋은 설계를 찾아 봅시다.

	// 1. 파일에 쓰기전에 사용자가 데이타를 암호화 하자.
	// => 자주 해야 하면 불편하다.

	// 2. FileStream 에 writeEncrypt()메소드를 제공하자
	// => Network, Pipe 에도 필요하다.

	// 3. Stream 에 Encrypt()메소드를 제공하자
	// => 새로운 요구사항이 생길때마다 기존 코드를 수정하면 OCP위반

	// 4. Decorator 를 사용하자.


	FileStream fs("a.txt");
	fs.write("AAA");

	EncryptDecorator es(&fs);
	es.write("AAA"); // 1. 암호화 하는 기능 추가
					 // 2. fs.write(암호화된 데이타전달)

	ZipDecorator zs(&es);
	zs.write("AAA"); // 1. 압축기능 수행
					 // 2. es.write(압축된 데이타)
}