#ifndef TODOTASK_H
#define TODOTASK_H

#include "ToDoItem.h"
#include "State.h"
#include <string>
using namespace std;

class ToDoTask : public ToDoItem
{
private:
    string name;
    string description;
    State *state;
    int priority;
    string dueDate;

public:
    ToDoTask(const string &name, const string &decription, int priority = 0, const string &dueDate = "");
    ~ToDoTask() = default;

    string getDescription() const override;
    string getStatus() const override;
    void execute() override;
    int getPriority() const override;
    float getEstimatedCost() const override;
    ItemIterator* createIterator(const string& type) override;

    void start();
    void pause();
    void complete();
    void cancel();
    void setState(State* newState);

    void setPriority(int newPriority);
    void setDueDate(const string& dueDate);

    const string& getName() const;
    State* getState() const;
}

#endif