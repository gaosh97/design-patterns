//在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态
//https://zhuanlan.zhihu.com/p/636062329
#include <iostream>
#include <string>
#include <vector>


class Memento
{
public:
	Memento(const std::string& state) : _state(state)
	{

	}

	std::string GetState() const
	{
		return _state;
	}
private:
	std::string _state;
};

class Originator
{
public:
	Originator() :_state("")
	{

	}
	void SetState(const std::string& state)
	{
		_state = state;
	}

	Memento SaveStateToMemento()
	{
		return Memento(_state);
	}

	void RestoreStateFromMemento(const Memento& memento)
	{
		_state = memento.GetState();
	}

	std::string GetState() const
	{
		return _state;
	}
private:
	std::string _state;
};

class Caretaker
{
public:
	void AddMemento(const Memento& memento)
	{
		_mementos.emplace_back(memento);
	}
	Memento GetMemento(int index) const
	{
		return _mementos[index];
	}
private:
	std::vector<Memento> _mementos;
};

//int main()
//{
//	Originator originator;
//	Caretaker caretaker;
//
//	originator.SetState("State #1");
//	originator.SetState("State #2");
//	caretaker.AddMemento(originator.SaveStateToMemento());
//
//	originator.SetState("State #3");
//	caretaker.AddMemento(originator.SaveStateToMemento());
//
//	originator.SetState("State #4");
//
//	std::cout << "Current state: " << originator.GetState() << std::endl;
//
//	originator.RestoreStateFromMemento(caretaker.GetMemento(0));
//	std::cout << "First saved state: " << originator.GetState() << std::endl;
//
//	originator.RestoreStateFromMemento(caretaker.GetMemento(1));
//	std::cout << "Second saved state: " << originator.GetState() << std::endl;
//
//	return 0;
//}