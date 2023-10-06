//����Դ���޵�����£��Դ�������������Ϊ��һ��Լ����
//ͨ����ʼ�����еĶ��󣬴ﵽ�봴������һ����Ч����
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