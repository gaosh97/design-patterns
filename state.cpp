//����һ�����������ڲ�״̬�ı�ʱ�ı�������Ϊ,�Ӷ�ʹ���������ƺ��޸�������Ϊ��
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

//˯��״̬
class SleepingState : public State
{
public :
	void WriteProgram(Work* ptrWork)
	{
		std::cout << "��ǰʱ�䣺" << ptrWork->GetHour() << "�� �Ų�ס�ˣ�˯���ɣ�" << std::endl;
	}
};

//�°���Ϣ״̬
class RestState : public State
{
public:
	void WriteProgram(Work* ptrWork)
	{
		std::cout << "��ǰʱ�䣺" << ptrWork->GetHour() << "�� �°�ؼ��ˣ�" << std::endl;
	}
};

//������״̬
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
			std::cout << "��ǰʱ�䣺" << ptrWork->GetHour() << "�� �Ӱ�ߺ��ƣ������" << std::endl;
		}
		else
		{//����21�㣬ת����˯��״̬
			ptrWork->SetState(std::make_shared<SleepingState>());
			ptrWork->WriteProgram();
		}
	}
};

//���繤��״̬
class AfternoonState : public State
{
public:
	void WriteProgram(Work* ptrWork)
	{
		if (ptrWork->GetHour() < 17)
		{
			std::cout << "��ǰʱ�䣺" << ptrWork->GetHour() << "�� ����״̬����������Ŭ����" << std::endl;
		}
		else
		{//����17�㣬ת��������״̬
			ptrWork->SetState(std::make_shared<EveningState>());
			ptrWork->WriteProgram();
		}
	}
};

//���繤��״̬
class NoonState : public State
{
public:
	void WriteProgram(Work* ptrWork)
	{
		if (ptrWork->GetHour() < 13)
		{
			std::cout << "��ǰʱ�䣺" << ptrWork->GetHour() << "�� ���ˣ��緹�����������ݣ�" << std::endl;
		}
		else
		{//����13�㣬ת�����繤��״̬
			ptrWork->SetState(std::make_shared<AfternoonState>());
			ptrWork->WriteProgram();
		}
	}
};

//���繤��״̬��
class ForenoonState : public State
{
public:
	void WriteProgram(Work* ptrWork)
	{
		if (ptrWork->GetHour() < 12)
		{
			std::cout << "��ǰʱ�䣺" << ptrWork->GetHour() << "�� ���繤��������ٱ���" << std::endl;
		}
		else
		{//����12�㣬ת�����繤��״̬
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
