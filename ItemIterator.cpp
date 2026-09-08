#include "ItemIterator.h"

ItemIterator::~ItemIterator() {}

StandardTraversalIterator::StandardTraversalIterator(ToDoItem* i) {
    if (i != nullptr)
        pending.push(i);

    next();
}

void StandardTraversalIterator::next() {
    if (pending.empty()) {
        current = nullptr;
        return;
    }

    current = pending.top();
    pending.pop();

    ///children get pushed in reverse order
    int count = current->getChildCount();
    for (int idx = count - 1; idx >= 0; --idx)
        pending.push(current->getChildAt(idx));
}

bool StandardTraversalIterator::isDone() {
    return current == nullptr;
}

ToDoItem* StandardTraversalIterator::currentItem() {
    return current;
}

float EstimatedCostIterator:: getHighestCost(ToDoItem* a, ToDoItem* b){
    return a->getEstimatedCost() > b->getEstimatedCost();
}

EstimatedCostIterator::EstimatedCostIterator(ToDoItem* i) {
    index = 0;
    collect(i);

    sort(items.begin(), items.end(), getHighestCost);
    current = items.empty() ? nullptr : items[0];
}

void EstimatedCostIterator::collect(ToDoItem* item) {
    if (!item) return;

    items.push_back(item);
    int count = item->getChildCount();
    for (int idx = 0; idx < count; ++idx) {
        collect(item->getChildAt(idx));///recursive call to add elements to the list
    }
}

void EstimatedCostIterator::next() {
    ++index;
    current = (index < items.size()) ? items[index] : nullptr;
}

bool EstimatedCostIterator::isDone() {
    return current == nullptr;
}

ToDoItem* EstimatedCostIterator::currentItem() {
    return current;
}
