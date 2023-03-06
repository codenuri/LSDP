#include <iostream>
#include <string>
#include <conio.h>


// 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 가상함수로 - Edit2번, 상속을 통한 변경

// 2. 변하는 것을 다른 클래스로 - 변해야 하므로 교체 가능해야한다.
//							인터페이스 기반 설계

struct IValidator
{
	virtual bool validate(const std::string&, char) = 0;

	virtual bool isComplete(const std::string&) 
	{
		return true;
	}
	virtual ~IValidator() {}
};

// 주민번호 : 881 1    확인


class Edit
{
	std::string data;
	//---------------
	IValidator* pval = nullptr;
public:

	void setValidator(IValidator* p) { pval = p; }
	//--------------------------------------------



	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13 && (pval == nullptr || pval->isComplete(data))  ) break;

			if ( pval == nullptr || pval->validate(data, c) ) 
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

// 이제 다양한 Validation 정책을 만들어서 제공합니다.
class LimitDigitValidator : public IValidator
{
	int limit;
public:
	LimitDigitValidator(int n) : limit(n) {}

	bool validate(const std::string& s, char c) override 
	{
		return s.size() < limit && isdigit(c);
	}

	bool isComplete(const std::string& s) override 
	{
		return s.size() == limit;
	}

};

int main()
{
	Edit edit;

	LimitDigitValidator v(5);
	edit.setValidator(&v);

	while (1)
	{
		std::string s = edit.getData();
		std::cout << s << std::endl;
	}
}
