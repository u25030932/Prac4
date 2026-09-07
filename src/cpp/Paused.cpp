#include "../headers/State.h"
#include <iostream>

void Paused::start(ToDoTask* task)
{
	cout << getName() << " Task " << task->getName() << " started";
	task->setState(new Progressing());
}

void Paused::pause(ToDoTask* task)
{
	cout << getName() << " Task " << task->getName() << " paused; no effect";
}

void Paused::cancel(ToDoTask* task)
{
	cout << getName() << " Task " << task->getName() << " cancelled";
	task->setState(new Cancelled());
}

void Paused::complete(ToDoTask* task)
{
	cout << getName() << " Task " << task->getName() << " completed";
	task->setState(new Finished());
}

const string name = "Paused";

string Paused::getName()
{
	return name;
}
