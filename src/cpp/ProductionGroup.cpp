#include "ProductionGroup.h"
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

ProductionGroup::ProductionGroup(const string &name, const string &description) : name(name), description(description)
{
    estimatedCost = 0.0f;
}

ProductionGroup::~ProductionGroup()
{
    for (ToDoItem *child : children)
    {
        delete child;
    }
    children.clear();
}

string ProductionGroup::getDescription() const
{
    return description;
}

string ProductionGroup::getStatus() const
{
    int total = children.size();
    int completed = 0;

    for (const ToDoItem *child : children)
    {
        if (child->getStatus() == "Finished")
        {
            completed++;
        }
    }
    ostringstream oss;
    oss << completed << "/" << total << " complete";
    return oss.str();
}

void ProductionGroup::execute()
{
    cout << "Executing for group: " << name << endl;
    for (ToDoItem *child : children)
    {
        child->execute();
    }
}

int ProductionGroup::getPriority() const
{
    if (children.empty())
    {
        return 0;
    }

    int maxPriority = children[0]->getPriority();
    for (size_t i = 0; i < children.size(); i++)
    {
        int childPriority = children[i]->getPriority();
        if (childPriority > maxPriority)
        {
            maxPriority = childPriority;
        }
    }
    return maxPriority;
}

float ProductionGroup::getEstimatedCost() const
{
    float total = estimatedCost;
    for (const ToDoItem *child : children)
    {
        total += child->getEstimatedCost();
    }
    return total;
}

ItemIterator *createIterator(const string &type)
{
    return nullptr; //To be done 
}

int ProductionGroup::getChildCount() const
{
    return children.size();
}

ToDoItem *ProductionGroup::getChildAt(int index) const
{
    return children.at(index);
}

void ProductionGroup::add(ToDoItem *item)
{
    if (item)
    {
        children.push_back(item);
    }
}

void ProductionGroup::remove(ToDoItem *item)
{
    auto it = find(children.begin(), children.end(), item);
    if (it != children.end())
    {
        children.erase(it);
    }
}