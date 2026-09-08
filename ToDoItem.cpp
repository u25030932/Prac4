#include "ToDoItem.h"

float ToDoItem::getEstimatedCost() const
{
	return estimatedCost;
}

void ToDoItem::setEstimatedCost(float cost) {
    estimatedCost = cost;
}
