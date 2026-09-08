#include "ToDoTask.h"
#include "State.h"
#include <iostream>

ToDoTask::ToDoTask(const string &name, 
		const string &description, 
		State* state,
		int priority, 
		const string &dueDate) : 
			name(name), 
			description(description), 
			state(state),
			priority(priority), 
			dueDate(dueDate)
{
	if (!state)
		throw "state cannot be null";
}

string ToDoTask::getName() const
{
	return name;
}

string ToDoTask::getDescription() const 
{
	return description;
}

const State* ToDoTask::getState() const
{
	return state;
}

int ToDoTask::getPriority() const 
{
	return priority;
}

string ToDoTask::getDueDate() const
{
	return dueDate;
}

void ToDoTask::execute() 
{
	cout << "Task " << name << " is due " << dueDate << endl;
}

string ToDoTask::getStatus() const 
{
	return state->getName();
}

void ToDoTask::start()
{
	state->start(this);
}

void ToDoTask::pause()
{
	state->pause(this);
}

void ToDoTask::complete()
{
	state->complete(this);
}

void ToDoTask::cancel()
{
	state->cancel(this);
}

void ToDoTask::setState(State* state)
{
	delete this->state;
	if (!state)
		throw "state cannot be null";
	else
		this->state = state;
}

ItemIterator* ToDoTask::createIterator(string type)
{
	return NULL; // implement this
}

ToDoTask::~ToDoTask()
{
	delete state;
}



