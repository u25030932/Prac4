#include "../headers/State.h"
#include <iostream>

void State::start(ToDoTask* task)
{
	cout << "Invalid operation" << endl;
}

void State::pause(ToDoTask* task)
{
	start(task);
}

void State::cancel(ToDoTask* task)
{
	start(task);
}

void State::complete(ToDoTask* task)
{
	start(task);
}

