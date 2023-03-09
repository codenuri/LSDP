// 2_Builder
#include <iostream>
#include <string>

// 축구게임 캐릭터를 생각해 봅시다.
// 모자, 유니폼, 신발등을 변경할수 있습니다.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}라고 가정



// 복잡한 객체의 각 부분을 만드는 함수를 인터페이스로 분리
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
		// 모든 캐릭터는 만드는 공정이 동일
		// "동일한 공정으로 객체를 생성하는데, 각 공정의 결과는 다른경우"
		Character c;
		c = c + pbuilder->makeHat();
		c = c + pbuilder->makeUniform();
		c = c + pbuilder->makeShoes();
		return c;
	}
};
// 국가별 빌더
class Korean : public IBuilder
{
public:
	Hat makeHat()         override { return "갓"; }
	Uniform makeUniform() override { return "한복"; }
	Shoes makeShoes()     override { return "짚신"; }
};
class American : public IBuilder
{
public:
	Hat makeHat()         override { return "야구모자"; }
	Uniform makeUniform() override { return "양복"; }
	Shoes makeShoes()     override { return "구두"; }
};

int main()
{
	Korean k;
	American a;

	Director d;
	d.setBuilder(&k); // 국가를 변경하면 다른 빌더를 넣으면 됩니다.
	
	Character c = d.construct();
	std::cout << c << std::endl;

}