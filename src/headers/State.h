#ifndef STATE_H
#define STATE_H

#include <string>
using namespace std;

class ToDoTask;

class State {
public:
    virtual void start(ToDoTask* task) = 0;
    virtual void pause(ToDoTask* task) = 0;
    virtual void cancel(ToDoTask* task) = 0;
    virtual void complete(ToDoTask* task) = 0;
    virtual string getName() = 0;
    virtual ~State() = default;
};

class Cancelled : public State {
public:
    void start(ToDoTask* task) override;
    void pause(ToDoTask* task) override;
    void cancel(ToDoTask* task) override;
    void complete(ToDoTask* task) override;
    string getName() override;
};

class Finished : public State {
public:
    void start(ToDoTask* task) override;
    void pause(ToDoTask* task) override;
    void cancel(ToDoTask* task) override;
    void complete(ToDoTask* task) override;
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
