#ifndef TODOITEM_H
#define TODOITEM_H

#include <string>
//#include "ItemIterator.h" //not implemented at time of creation but will be incorporated later
using namespace std;

class ItemIterator;

class ToDoItem
{
public:
    virtual const string& getDescription() const = 0;
    virtual const string& getStatus() const = 0;
    virtual void execute() = 0;
    virtual int getPriority() const = 0;
    virtual float getEstimatedCost() const;
    virtual ItemIterator *createIterator(const string &type) = 0;

    virtual ~ToDoItem() = default;

protected:
    float estimatedCost = 0.0f;
};

#endif
