
#include <iostream>
#include <string>
#include "../headers/ToDoItem.h"
#include "../headers/ToDoTask.h"
#include "../headers/ProductionGroup.h"
#include "../headers/TaskDecorator.h"
// #include "PriorityDecorator.h"
// #include "CostAdjustmentDecorator.h"
#include "../headers/ItemIterator.h"
#include "../headers/State.h"

using namespace std;


void printAll(ToDoItem* root, const string& type, const string& label) {
    ItemIterator* it = root->createIterator(type);
    cout << "--- " << label << " ---" << endl;
    if (it == nullptr) {
        cout << "  [createIterator(\"" << type << "\") returned nullptr — check the factory's"
             << " type dispatch in ProductionGroup/ToDoTask/TaskDecorator]" << endl << endl;
        return;
    }
    while (!it->isDone()) {
        ToDoItem* item = it->currentItem();
        if (item == nullptr) {
            cout << "  [currentItem() returned nullptr while not done — stopping early]" << endl;
            break;
        }
        cout << "  " << item->getDescription() << " | status: " << item->getStatus() << " | priority: " << item->getPriority()
            << " | cost: " << item->getEstimatedCost() << endl;
        it->next();
    }
    delete it;
    cout << endl;
}

int main() {

    //Scenario 1: Morning production meeting
    cout << "Scenario 1: Morning Production Meeting" << endl << endl;

    ProductionGroup* shootDay = new ProductionGroup("Feature Film Shoot", "Day 14 of principal photography");

    ProductionGroup* scene14 = new ProductionGroup("Scene 14 - Rooftop Chase", "Exterior rooftop, night shoot");
    ToDoTask* cameraSetup = new ToDoTask("Camera setup", "Rig main and B-camera on rooftop", new Planning(), 3, "2026-09-08");
    cameraSetup->setEstimatedCost(450.0f);
    ToDoTask* stuntRehearsal = new ToDoTask("Stunt rehearsal", "Rehearse rooftop jump with stunt coordinator", new Planning(), 4, "2026-09-08");
    stuntRehearsal->setEstimatedCost(1200.0f);
    scene14->add(cameraSetup);
    scene14->add(stuntRehearsal);

    ProductionGroup* soundDept = new ProductionGroup("Sound Department", "Audio capture for Scene 14");
    ToDoTask* boomCheck = new ToDoTask("Boom mic check", "Test boom levels against rooftop wind noise", new Planning(), 2, "2026-09-08");
    boomCheck->setEstimatedCost(80.0f);
    soundDept->add(boomCheck);

    ToDoTask* catering = new ToDoTask("Catering setup", "Set up crew catering tent", new Planning(), 1, "2026-09-08");
    catering->setEstimatedCost(300.0f);

    shootDay->add(scene14);
    shootDay->add(soundDept);
    shootDay->add(catering);

    printAll(shootDay, "standard", "Full day sheet (standard traversal)");
    printAll(shootDay, "cost", "Budget review (highest cost first)");

    cout << "Interleaving two independent iterators" << endl;
    ItemIterator* standardIt = shootDay->createIterator("standard");
    ItemIterator* costIt     = shootDay->createIterator("cost");
    if (standardIt == nullptr || costIt == nullptr) {
        cout << "  [one of the iterators was nullptr — skipping interleave demo]" << endl << endl;
        delete standardIt;
        delete costIt;
    } else {
        for (int step = 0; step < 2 && !standardIt->isDone() && !costIt->isDone(); ++step) {
            cout << "  standard @ " << standardIt->currentItem()->getDescription() << endl;
            cout << "  cost     @ " << costIt->currentItem()->getDescription() << endl;
            standardIt->next();
            costIt->next();
        }
        cout << endl;

        ///structural change 1
        ToDoTask* weatherContingency = new ToDoTask(
            "Weather delay contingency", "Tarp and reschedule buffer for rooftop shot", new Planning(), 3, "2026-09-08");
        weatherContingency->setEstimatedCost(150.0f);
        cout << "[Structural change] Adding a late task to Scene 14 while 'standardIt' is still open..." << endl;
        scene14->add(weatherContingency);

        cout << "Does the already-open standard iterator ever reach the new task? ";
        bool foundInOldIterator = false;
        while (!standardIt->isDone()) {
            if (standardIt->currentItem() == weatherContingency) foundInOldIterator = true;
            standardIt->next();
        }
        cout << (foundInOldIterator ? "yes (policy violated!)" : "no (snapshot policy honoured)") << endl << endl;
        delete standardIt;
        delete costIt;

        printAll(shootDay, "standard", "Full day sheet AFTER the late addition (fresh iterator)");
    }


    //Scenario 2: A stunt task runs into a scheduling problem
    cout << "Scenario 2: A Stunt Task Runs Into a Scheduling Problem" << endl << endl;

    cout << "[Lifecycle] Starting stunt rehearsal..." << endl;
    stuntRehearsal->start();
    stuntRehearsal->execute();
    cout << endl;

    cout << "[Decoration] Safety officer flags this as urgent priority..." << endl;
    ToDoItem* urgentStunt = new PriorityDecorator(stuntRehearsal, 5);
    cout << "  " << urgentStunt->getDescription() << " | priority now: " << urgentStunt->getPriority() << endl;
    urgentStunt->execute();
    cout << endl;

    cout << "[Decoration] Extra rigging equipment adds cost on top of the priority flag (stacked decorators)..." << endl;
    ToDoItem* urgentStuntWithCost = new CostAdjustmentDecorator(urgentStunt, 350.0f);
    cout << "  " << urgentStuntWithCost->getDescription()
         << " | total estimated cost now: " << urgentStuntWithCost->getEstimatedCost() << endl << endl;

    cout << "[Lifecycle] Weather rolls in — pausing the task..." << endl;
    stuntRehearsal->pause();

    cout << "[Lifecycle] Attempting to complete a paused task (invalid transition — must resume first)..." << endl;
    stuntRehearsal->complete();

    cout << "[Lifecycle] Weather clears — resuming..." << endl;
    stuntRehearsal->start();

    cout << "[Lifecycle] Completing..." << endl;
    stuntRehearsal->complete();
    cout << endl;

    // Structural change 2: moving an item between groups.
    cout << "[Structural change] Rescheduling: moving the stunt task out of Scene 14..." << endl;
    ProductionGroup* rescheduled = new ProductionGroup("Rescheduled Items", "Tasks bumped from original call sheet");
    scene14->remove(stuntRehearsal);
    rescheduled->add(urgentStuntWithCost);
    shootDay->add(rescheduled);

    printAll(shootDay, "standard", "Full day sheet AFTER the reschedule (fresh iterator reflects the move)");

    delete shootDay;

    return 0;
}
