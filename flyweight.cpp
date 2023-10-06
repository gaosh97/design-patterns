//在资源有限的情况下，对创建大量对象行为的一种约束。
//通过初始化已有的对象，达到与创建对象一样的效果。
#include <string>
#include <map>
class Font
{
private:
	std::string key;

public:
	Font(const std::string& key)
	{

	}
};

class FontFactory
{
private:
	std::map<std::string, Font*> fontPool;

public:
	Font* GetFont(const std::string& key)
	{
		std::map<std::string, Font*>::iterator item = fontPool.find(key);
		if (item != fontPool.end())
		{
			return fontPool[key];
		}
		else
		{
			Font* font = new Font(key);
			fontPool[key] = font;
			return font;
		}
	}
};