#include <iostream>
#include <string>
#include <conio.h>

// validation 정책은 교체 가능해야 한다.

class Edit
{
	std::string data;
public:
	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부의 변하는 부분을 찾아서
	// => 가상함수로 분리 한다

	virtual bool validate(char c)
	{
		return true;
	}

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13) break;

			if ( validate(c) ) // 값의 유효성 확인은 가상함수에 위임
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

// 사용자는 Edit 파생 클래스를 설계해서 정책변경을 위해서 
// 가상함수재정의
// => "template method" 패턴.
class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit edit;
	NumEdit edit;
//	AddressEdit e2;

	while (1)
	{
		std::string s = edit.getData();
		std::cout << s << std::endl;
	}
}
