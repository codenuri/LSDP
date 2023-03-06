#include <iostream>
#include <string>
#include <conio.h>


// ���ϴ� ���� �и��ϴ� 2���� ���
// 1. ���ϴ� ���� �����Լ��� - Edit2��, ����� ���� ����

// 2. ���ϴ� ���� �ٸ� Ŭ������ - ���ؾ� �ϹǷ� ��ü �����ؾ��Ѵ�.
//							�������̽� ��� ����

struct IValidator
{
	virtual bool validate(const std::string&, char) = 0;

	virtual bool isComplete(const std::string&) 
	{
		return true;
	}
	virtual ~IValidator() {}
};

// �ֹι�ȣ : 881 1    Ȯ��


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

// ���� �پ��� Validation ��å�� ���� �����մϴ�.
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
