#include <iostream>
#include <string>
#include <map>


class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	inline static std::map<std::string, Image*> image_map;

	static Image* Create(const std::string& url)
	{
		Image* img = 0;

		auto ret = image_map.find(url); // image_map.contain(url)
		
		if (ret == image_map.end())
		{
			img = new Image(url);
			image_map[url] = img;
		}
		else
		{
			img = ret->second;
		}
		return img;
	}
};

//std::map<std::string, Image*> Image::image_map;



int main()
{
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

}



