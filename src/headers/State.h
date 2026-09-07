#ifndef STATE_H
#define STATE_H

#include "ToDoTask.h"
#include <string>
using namespace std;

class State {
public:
    virtual void start(ToDoTask* task);
    virtual void pause(ToDoTask* task);
    virtual void cancel(ToDoTask* task);
    virtual void complete(ToDoTask* task);
    virtual string getName() = 0;
    virtual ~State() = default;
};

class Cancelled : public State {
public:
    string getName() override;
};

class Finished : public State {
public:
    string getName() override;
};

class Paused : public State {
public:
    void start(ToDoTask* task) override;
    void pause(ToDoTask* task) override;
    void cancel(ToDoTask* task) override;
    void complete(ToDoTask* task) override;
    string getName() override;
};

class Planning : public State {
public:
    void start(ToDoTask* task) override;
    void pause(ToDoTask* task) override;
    void cancel(ToDoTask* task) override;
    void complete(ToDoTask* task) override;
    string getName() override;
};

class Progressing : public State {
public:
    void start(ToDoTask* task) override;
    void pause(ToDoTask* task) override;
    void cancel(ToDoTask* task) override;
    void complete(ToDoTask* task) override;
    string getName() override;
};

#endif
