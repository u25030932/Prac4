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
    ToDoTask(const string &name, const string &description, State *state, int priority = 0, const string &dueDate = "");
    ~ToDoTask();

    const string& getStatus() const override;
    void execute() override;
    ItemIterator* createIterator(const string& type) override;

    void start();
    void pause();
    void complete();
    void cancel();

    const string& getName() const;
    const string& getDescription() const override;
    const State* getState() const;
    void setState(State* state);
    int getPriority() const override;
    const string& getDueDate() const;
};

#endif
