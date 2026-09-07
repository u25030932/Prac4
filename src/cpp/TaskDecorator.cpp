#include "TaskDecorator.h"

TaskDecorator::TaskDecorator(ToDoItem* item) : element(item) 
{
	if (!item)
		throw "item cannot be null";
}

string TaskDecorator::getStatus() const
{
	return element->getStatus();
}

void TaskDecorator::execute()
{
	element->execute();
}

ItemIterator* TaskDecorator::createIterator(string type)
{
	return element->createIterator(type);
}

int TaskDecorator::getPriority() const
{
	return element->getPriority();
}

float TaskDecorator::getEstimatedCost() const
{
	return element->getEstimatedCost();
}

TaskDecorator::~TaskDecorator()
{
	delete element;
}
