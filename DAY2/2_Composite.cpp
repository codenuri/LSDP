#include <iostream>
#include <vector>
#include <string>

// 아래 main이 실행될수 있도록, File, Folder 를 완성해 보세요

// => 메뉴와 거의 동일한 코드가 됩니다.
// => 메뉴 참고해서 만들어 보세요
// 
// File 과 Folder의 공통의기반 클래스
class Component
{
	std::string name;
public:
	Component(const std::string& s)	: name(s){}

	// File 과 Folder는 모두 크기를 구할수 있습니다.
	virtual int getSize() = 0;
};

class File : public Component
{
	int size; // 파일은 자신만의 크기가 있습니다.
public:
	File(const std::string& name, int s)
		: Component(name), size(s) {}

	int getSize() override { return size; }
};

class Folder : public Component
{ 
	std::vector<Component*> v;
public:
	Folder(const std::string& name) : Component(name) {}

	void addItem(Component* c) { v.push_back(c); }

	int getSize() override
	{
		int sz = 0;

		for (auto p : v)
			sz += p->getSize();

		return sz;
	}
};



int main()
{
	Folder* root = new Folder("ROOT");
	Folder* fo1  = new Folder("A");
	Folder* fo2  = new Folder("B");
	
	root->addItem(fo1);
	root->addItem(fo2);

	File* f1 = new File("a.txt", 10);
	File* f2 = new File("b.txt", 20);

	fo1->addItem(f1);
	root->addItem(f2);

	// 파일은 자신만의 크기는 있습니다.
	// 폴더는 자신만의 크기는 없지만 크기를 구할수 있습니다.
	std::cout << f2->getSize() << std::endl; // 20
	std::cout << fo1->getSize() << std::endl; // 10
	std::cout << root->getSize() << std::endl; // 30
}

