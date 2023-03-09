// 2_Builder
#include <iostream>
#include <string>

// �౸���� ĳ���͸� ������ ���ô�.
// ����, ������, �Źߵ��� �����Ҽ� �ֽ��ϴ�.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}��� ����



// ������ ��ü�� �� �κ��� ����� �Լ��� �������̽��� �и�
struct IBuilder
{
	virtual Hat makeHat() = 0;
	virtual Uniform makeUniform() = 0;
	virtual Shoes   makeShoes() = 0;
	virtual ~IBuilder() {}
};

class Director
{
	IBuilder* pbuilder = 0;
public:
	void setBuilder(IBuilder* p) { pbuilder = p; }

	Character construct()
	{
		// ��� ĳ���ʹ� ����� ������ ����
		// "������ �������� ��ü�� �����ϴµ�, �� ������ ����� �ٸ����"
		Character c;
		c = c + pbuilder->makeHat();
		c = c + pbuilder->makeUniform();
		c = c + pbuilder->makeShoes();
		return c;
	}
};
// ������ ����
class Korean : public IBuilder
{
public:
	Hat makeHat()         override { return "��"; }
	Uniform makeUniform() override { return "�Ѻ�"; }
	Shoes makeShoes()     override { return "¤��"; }
};
class American : public IBuilder
{
public:
	Hat makeHat()         override { return "�߱�����"; }
	Uniform makeUniform() override { return "�纹"; }
	Shoes makeShoes()     override { return "����"; }
};

int main()
{
	Korean k;
	American a;

	Director d;
	d.setBuilder(&k); // ������ �����ϸ� �ٸ� ������ ������ �˴ϴ�.
	
	Character c = d.construct();
	std::cout << c << std::endl;

}