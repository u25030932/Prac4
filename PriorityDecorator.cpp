#include "TaskDecorator.h"
#include <iostream>
#include <sstream>

PriorityDecorator::PriorityDecorator(ToDoItem* item, int priority) : TaskDecorator(item), priority(priority) {}

string PriorityDecorator::getDescription() const
{
	stringstream ss;
	ss << element->getDescription() << " [Priority: " << priority << "]" << endl;
	return ss.str();
}

int PriorityDecorator::getPriority() const
{
	return priority;
}

void PriorityDecorator::execute()
{
	cout << "Item executed with priority " << priority << endl;
	TaskDecorator::execute();
}
