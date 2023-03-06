#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}

	std::string getTitle() { return title; }

	void command()
	{
		std::cout << getTitle() << " ¼±ÅÃµÊ" << std::endl;
		_getch();
	}
};

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& s) : title(s) {}

	void append(MenuItem* p) { v.push_back(p); }

	void command()
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->getTitle()
					<< std::endl;
			}

			std::cout << sz + 1 << ". Á¾·á" << std::endl;

			std::cout << "¸Þ´º¸¦ ¼±ÅÃÇÏ¼¼¿ä >> ";
			int cmd;
			std::cin >> cmd;


			if (cmd == sz + 1)
				break;

			if (cmd < 1 || sz + 1 < cmd)
				continue;


			v[cmd - 1]->command();

		}



	}
};





int main()
{
	MenuItem m1("ÂüÄ¡  ±è¹ä", 11);
	MenuItem m2("¼Ò°í±â ±è¹ä", 12);

	PopupMenu kimbam("±è¹ä·ù");

	kimbam.append(&m1);
	kimbam.append(&m2);


	MenuItem m3("¶ó¸é", 21);

	PopupMenu pm("¿À´ÃÀÇ Á¡½É"); 

	pm.append(&kimbam); // ÇÙ½É.. ÆË¾÷¿¡ ´Ù½Ã ÆË¾÷ ºÎÂø
						// ÇöÀç´Â ¾ÈµÊ.. ÇØ°áÃ¥Àº ´ÙÀ½¿¹Á¦.
	pm.append(&m3);

	pm.command();


}

