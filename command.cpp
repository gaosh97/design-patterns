//对发送者和接收者完全解耦，发送者与接收者之间没有直接引用关系
// 发送请求的对象只需要知道如何发送请求，而不必知道如何完成请求

#include <vector>
#include <string>
#include <iostream>
class Command
{
public:
	virtual void Execute() = 0;

};

class ConcreteCommand1 : public Command
{
	std::string arg;
public:
	ConcreteCommand1(const std::string& a) : arg(a)
	{

	}
	void Execute() override
	{
		std::cout << "#1 process " << arg << std::endl;
	}
};

class ConcreteCommand2 : public Command
{
	std::string arg;
public:
	ConcreteCommand2(const std::string& a) : arg(a)
	{

	}
	void Execute() override
	{
		std::cout << "#2 process " << arg << std::endl;
	}
};

class MacroCommand : public Command
{
	std::vector<Command*> commands;
public:
	void AddCommand(Command* c)
	{
		commands.emplace_back(c);
	}
	void Execute() override
	{
		for (const auto& c : commands)
		{
			c->Execute();
		}
	}
};

int main()
{
	ConcreteCommand1 command1("Arg ###");
	ConcreteCommand2 command2("Arg ###");

	MacroCommand macro;
	macro.AddCommand(&command1);
	macro.AddCommand(&command2);

	macro.Execute();
}