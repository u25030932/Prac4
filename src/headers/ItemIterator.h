#ifndef ITEMITERATOR_H
#define ITEMITERATOR_H

#include "ToDoItem.h"

#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class ItemIterator{
    protected:
        ToDoItem* current;
    public:
        virtual void next()=0 ;
        virtual bool isDone()=0 ;
        virtual ToDoItem* currentItem()=0 ;
        virtual ~ItemIterator();

};

class StandardTraversalIterator: public ItemIterator{
    private:
        stack<ToDoItem*> pending;///TODO add this member
    public:
        StandardTraversalIterator(ToDoItem* i);
        void next() override;
        bool isDone() override;
        ToDoItem* currentItem() override;
};

class EstimatedCostIterator: public ItemIterator{
    private:
        vector<ToDoItem*> items; /// add to UML
        int index;///add to UML
        void collect(ToDoItem* item); ///add to UML
        static float getHighestCost(ToDoItem* a, ToDoItem* b); ///add to UML
    public:
        EstimatedCostIterator(ToDoItem* i); ///ToDO: update the UML to have this constructor
        void next() override;
        bool isDone() override;
        ToDoItem* currentItem() override;
};

#endif
