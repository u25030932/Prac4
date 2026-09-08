#ifndef TODOITEM_H
#define TODOITEM_H

#include <string>
//#include "ItemIterator.h" //not implemented at time of creation but will be incorporated later
using namespace std;

class ItemIterator;

class ToDoItem
{
public:
    virtual string getDescription() const = 0;
    virtual string getStatus() const = 0;
    virtual void execute() = 0;
    virtual int getPriority() const = 0;
    virtual float getEstimatedCost() const;
    virtual ItemIterator *createIterator(string type) = 0;
    void setEstimatedCost(float cost);
    virtual int getChildCount() const { return 0; }
    virtual ToDoItem *getChildAt(int index) const { return nullptr; }

    virtual ~ToDoItem() = default;

protected:
    float estimatedCost = 0.0f;
};

#endif
