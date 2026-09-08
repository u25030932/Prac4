#ifndef PRODUCTIONGROUP_H
#define PRODUCTIONGROUP_H

#include "ToDoItem.h"
#include <vector>
#include <string>
using namespace std;

class ProductionGroup : public ToDoItem
{
private:
    string name;
    string description;
    vector<ToDoItem *> children;

public:
    ProductionGroup(const string &name, const string &description);
    ~ProductionGroup();

    string getDescription() const override;
    string getStatus() const override;
    void execute() override;
    int getPriority() const override;
    float getEstimatedCost() const override;
    ItemIterator *createIterator(string type) override;

    int getChildCount() const override;
    ToDoItem *getChildAt(int index) const override;

    void add(ToDoItem *item);
    void remove(ToDoItem *item);

private:
    int calculateAggregatePriority() const;
    string calculateStatusSummary() const;
};

#endif
