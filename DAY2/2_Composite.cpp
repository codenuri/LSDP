#include <iostream>
#include <vector>
#include <string>

// �Ʒ� main�� ����ɼ� �ֵ���, File, Folder �� �ϼ��� ������

// => �޴��� ���� ������ �ڵ尡 �˴ϴ�.
// => �޴� �����ؼ� ����� ������
// 
// File �� Folder�� �����Ǳ�� Ŭ����
class Component
{
	std::string name;
public:
	Component(const std::string& s)	: name(s){}

	// File �� Folder�� ��� ũ�⸦ ���Ҽ� �ֽ��ϴ�.
	virtual int getSize() = 0;
};

class File : public Component
{
	int size; // ������ �ڽŸ��� ũ�Ⱑ �ֽ��ϴ�.
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

	// ������ �ڽŸ��� ũ��� �ֽ��ϴ�.
	// ������ �ڽŸ��� ũ��� ������ ũ�⸦ ���Ҽ� �ֽ��ϴ�.
	std::cout << f2->getSize() << std::endl; // 20
	std::cout << fo1->getSize() << std::endl; // 10
	std::cout << root->getSize() << std::endl; // 30
}

