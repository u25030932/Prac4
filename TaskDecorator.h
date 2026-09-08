#ifndef TASK_DECORATOR_H
#define TASK_DECORATOR_H

#include "ToDoItem.h"

class TaskDecorator : public ToDoItem
{
	protected:
		ToDoItem* element;
	public:
		TaskDecorator(ToDoItem*);
		string getStatus() const override;
		void execute() override;
		ItemIterator* createIterator(string type) override;
		int getPriority() const override;
		float getEstimatedCost() const override;
		~TaskDecorator() override;
};

class PriorityDecorator : public TaskDecorator
{
	private:
		int priority;
	public:
		PriorityDecorator(ToDoItem*, int);
		string getDescription() const override;
		int getPriority() const override;
		void execute() override;
};

class CostAdjustmentDecorator : public TaskDecorator
{
	private:
		float adjustmentAmount;
	public:
		CostAdjustmentDecorator(ToDoItem*, float);
		string getDescription() const override;
		float getEstimatedCost() const override;
};

#endif
