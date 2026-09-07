#include "../headers/State.h"
#include <iostream>

void Planning::start(ToDoTask* task)
{
	cout << getName() << " Task " << task->getName() << " started";
	task->setState(new Progressing());
}

void Planning::pause(ToDoTask* task)
{
	cout << getName() << " Task " << task->getName() << " paused";
	task->setState(new Paused());
}

void Planning::cancel(ToDoTask* task)
{
	cout << getName() << " Task " << task->getName() << " cancelled";
	task->setState(new Cancelled());
}

void Planning::complete(ToDoTask* task)
{
	cout << getName() << " Task " << task->getName() << " completed";
	task->setState(new Finished());
}

const string name = "Planning";

const string& Planning::getName()
{
	return name;
}
