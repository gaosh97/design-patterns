//允许一个对象在其内部状态改变时改变它的行为,从而使对象看起来似乎修改了其行为。
//https://blog.csdn.net/DU_YULIN/article/details/120132521
#include <iostream>
#include <memory>

class Work;

class State
{
public:
	virtual void WriteProgram(Work* ptrWork) = 0;
};

class Work
{
private:
	std::shared_ptr<State> smartState;
	double hour;
	double finish;

public:
	Work();

	void SetHour(const double h)
	{
		hour = h;
	}

	double GetHour() const
	{
		return hour;
	}

	void SetFinish(bool bFinish)
	{
		finish = bFinish;
	}

	bool GetFinish() const
	{
		return finish;
	}

	void SetState(std::shared_ptr<State> pState)
	{
		smartState = pState;
	}

	std::shared_ptr<State> GetState() const
	{
		return smartState;
	}

	void WriteProgram()
	{
		smartState->WriteProgram(this);
	}
};

//睡眠状态
class SleepingState : public State
{
public :
	void WriteProgram(Work* ptrWork)
	{
		std::cout << "当前时间：" << ptrWork->GetHour() << "点 撑不住了，睡觉吧！" << std::endl;
	}
};

//下班休息状态
class RestState : public State
{
public:
	void WriteProgram(Work* ptrWork)
	{
		std::cout << "当前时间：" << ptrWork->GetHour() << "点 下班回家了！" << std::endl;
	}
};

//傍晚工作状态
class EveningState : public State
{
public:
	void WriteProgram(Work* ptrWork)
	{
		if (ptrWork->GetFinish())
		{
			ptrWork->SetState(std::make_shared<RestState>());
			ptrWork->WriteProgram();
			return;
		}

		if (ptrWork->GetHour() < 21)
		{
			std::cout << "当前时间：" << ptrWork->GetHour() << "点 加班吆，疲惫啊！" << std::endl;
		}
		else
		{//超过21点，转换到睡眠状态
			ptrWork->SetState(std::make_shared<SleepingState>());
			ptrWork->WriteProgram();
		}
	}
};

//下午工作状态
class AfternoonState : public State
{
public:
	void WriteProgram(Work* ptrWork)
	{
		if (ptrWork->GetHour() < 17)
		{
			std::cout << "当前时间：" << ptrWork->GetHour() << "点 下午状态还不错，继续努力！" << std::endl;
		}
		else
		{//超过17点，转换傍晚工作状态
			ptrWork->SetState(std::make_shared<EveningState>());
			ptrWork->WriteProgram();
		}
	}
};

//中午工作状态
class NoonState : public State
{
public:
	void WriteProgram(Work* ptrWork)
	{
		if (ptrWork->GetHour() < 13)
		{
			std::cout << "当前时间：" << ptrWork->GetHour() << "点 饿了，午饭，犯困，午休！" << std::endl;
		}
		else
		{//超过13点，转换下午工作状态
			ptrWork->SetState(std::make_shared<AfternoonState>());
			ptrWork->WriteProgram();
		}
	}
};

//上午工作状态类
class ForenoonState : public State
{
public:
	void WriteProgram(Work* ptrWork)
	{
		if (ptrWork->GetHour() < 12)
		{
			std::cout << "当前时间：" << ptrWork->GetHour() << "点 上午工作，精神百倍！" << std::endl;
		}
		else
		{//超过12点，转换中午工作状态
			ptrWork->SetState(std::make_shared<NoonState>());
			ptrWork->WriteProgram();
		}
	}
};

Work::Work() : hour(0), finish(false), smartState(std::make_shared<ForenoonState>()) {}

//int main()
//{
//	std::shared_ptr<Work> work = std::make_shared<Work>();
//
//	work->SetHour(9);
//	work->WriteProgram();
//
//	work->SetHour(10);
//	work->WriteProgram();
//
//	work->SetHour(12);
//	work->WriteProgram();
//
//	work->SetHour(13);
//	work->WriteProgram();
//
//	work->SetHour(14);
//	work->WriteProgram();
//
//	work->SetHour(17);
//	work->WriteProgram();
//
//	work->SetFinish(false);
//	work->SetFinish(true);
//	work->WriteProgram();
//
//	work->SetHour(19);
//	work->WriteProgram();
//
//	work->SetHour(22);
//	work->WriteProgram();
//
//	system("pause");
//	return 0;
//}
