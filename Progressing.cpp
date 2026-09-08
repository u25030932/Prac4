#include "State.h"
#include <iostream>

void Progressing::start(ToDoTask* task)
{
	cout << getName() << " Task " << task->getName() << " started";
}

void Progressing::pause(ToDoTask* task)
{
	cout << getName() << " Task " << task->getName() << " paused";
	task->setState(new Paused());
}

void Progressing::cancel(ToDoTask* task)
{
	cout << getName() << " Task " << task->getName() << " cancelled";
	task->setState(new Cancelled());
}

void Progressing::complete(ToDoTask* task)
{
	cout << getName() << " Task " << task->getName() << " finished";
	task->setState(new Finished());
}

const string name = "Progressing";

string Progressing::getName()
{
	return name;
}
