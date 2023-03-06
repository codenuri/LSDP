#include <iostream>
#include <string>
#include <conio.h>

// validation ��å�� ��ü �����ؾ� �Ѵ�.

class Edit
{
	std::string data;
public:
	// ���뼺�� �������� �и�
	// => ������ ���� �ڵ� ������ ���ϴ� �κ��� ã�Ƽ�
	// => �����Լ��� �и� �Ѵ�

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

			if ( validate(c) ) // ���� ��ȿ�� Ȯ���� �����Լ��� ����
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

// ����ڴ� Edit �Ļ� Ŭ������ �����ؼ� ��å������ ���ؼ� 
// �����Լ�������
// => "template method" ����.
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
