class Animal {};
class Dog : public Animal {};

// LSP : Liskov Substitution Principle
// => ��� Ŭ������ ���Ǵ� ���� �Ļ� Ŭ������ ��ü �Ҽ��־���Ѵ�.

void foo(Animal* p) {}

foo(Dog��ü); // <== �̷��� �Ҽ� �־�� �Ѵ�.!!

//-----------------------
class list
{
public:
	void push_back() {}
	void push_front() {}
};
class stack : public list
{
	void push_front() { throw 1 }; // <== LSP ����!
};

void goo(list* p) { p->push_front(); }

goo(stack ��ü);
//==========================================
// �Ʒ� �������̽��� ���� �������̽� �ϱ�� ?
// ISP ( Interface Surrogate Principle )
// => �������̽��� ��� ���� �и�
// SRP 
// => Ŭ������ �Ѱ��� å�Ӹ�
struct IMP3
{
	virtual void Play() = 0;
	virtual void UploadSNS() = 0;
	virtual void VoiceRecord() = 0;
};
// SOLID : SRP, OCP, LSP, ISP, DIP(��ü�� �������� ����,�߻�����)