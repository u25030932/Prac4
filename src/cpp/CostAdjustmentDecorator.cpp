#include "TaskDecorator.h"
#include <sstream>

CostAdjustmentDecorator::CostAdjustmentDecorator(ToDoItem* item, float amount) : TaskDecorator(item), adjustmentAmount(amount) {}

string CostAdjustmentDecorator::getDescription() const
{
	stringstream ss;
	ss << element->getDescription() << endl;
	ss << "Adjusted by: R" << adjustmentAmount << endl;
	return ss.str();
}

float CostAdjustmentDecorator::getEstimatedCost() const
{
	return element->getEstimatedCost() + adjustmentAmount;
}
