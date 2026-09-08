# ⚡ TaskForge

> Hierarchical Work Processing System for Film Production

[![C++](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Docker](https://img.shields.io/badge/docker-ready-blue.svg)](https://www.docker.com/)
[![Patterns](https://img.shields.io/badge/patterns-Composite%20%7C%20State%20%7C%20Decorator%20%7C%20Iterator-orange.svg)]()

---

## 📋 Table of Contents

- [Overview](#overview)
- [Pattern Implementation](#pattern-implementation)
- [Build & Run](#build--run)
- [Runtime Scenarios](#runtime-scenarios) //to do Kai and Anchen
- [Debugging](#debugging)
- [Team](#team)

---

## 📋 Overview

**TaskForge** is a work-processing system designed for film production pipelines. It manages hierarchical tasks where groups can contain both individual tasks and nested groups, allowing for complex production workflows to be modelled and executed.

### Key Technologies

| Component | Technology |
|-----------|------------|
| Language | C++11 |
| Build System | Makefile |
| Container | Docker |
| Debugging | GDB, Valgrind |
| Patterns | Composite, State, Decorator, Iterator |

---

## 🎯 Pattern Implementation

### 🏗️ Composite Pattern

| Participant | Class | Role |
|-------------|-------|------|
| Component | `ToDoItem` | Abstract base class for all items |
| Leaf | `ToDoTask` | Individual work item |
| Composite | `ProductionGroup` | Container for tasks and groups |

**Key Features:**
- Recursive part-whole hierarchy
- Uniform treatment of individual tasks and groups
- Child management (add/remove/getChildCount/getChildAt)


## Build & Run
```
sudo docker build -t docker_image .
sudo docker run docker_image
```

### 🔄 State Pattern

| Participant | Class | Role |
|-------------|-------|------|
| Context | `ToDoTask` | Maintains current state |
| State Interface | `State` | Abstract base for all states |
| Concrete States | `Planning`, `Progressing`, `Paused`, `Cancelled`, `Finished` | Lifecycle stages |

**State Transitions:**


**Invalid Transitions:**
- Cannot pause from Planning
- Cannot complete from Paused
- Cannot modify from Cancelled or Finished (terminal states)

### 🎨 Decorator Pattern

| Participant | Class | Role |
|-------------|-------|------|
| Component | `ToDoItem` | Interface for decorated objects |
| Decorator | `TaskDecorator` | Abstract decorator base |
| Concrete Decorators | `PriorityDecorator`, `CostAdjustmentDecorator` | Add runtime responsibilities |

### 🔍 Iterator Pattern

| Participant | Class | Role |
|-------------|-------|------|
| Aggregate (factory method) | `ToDoItem::createIterator(type)` | Hands back the right concrete iterator without exposing internal storage |
| Iterator | `ItemIterator` | Abstract base defining `next()` / `isDone()` / `currentItem()` |
| Concrete Iterator | `StandardTraversalIterator` | Depth-first traversal of the entire structure, in call-sheet order |
| Concrete Iterator | `EstimatedCostIterator` | Same structure, ordered by estimated cost — highest first |


## Debugging
```
sudo docker run -it docker_image bash
valgrind ./main
gdb ./main
```

## 🎬 Runtime Scenarios

### Scenario 1 — Morning Production Meeting
Traverses the full shoot-day hierarchy two ways — structural order and cost order — proving both iterators coexist independently. A late task is added to Scene 14 mid-traversal; an already-open iterator is shown *not* to see it (snapshot policy), while a fresh iterator afterward does.

### Scenario 2 — Stunt Task Scheduling Problem
Follows one task through its full lifecycle, including an invalid transition (completing while paused). It's wrapped in two stacked decorators (priority, then cost) and used only through the base `ToDoItem` interface. It's later moved between groups — the decorated object, not the raw task, is what gets relocated, preserving single ownership.

## The team:

| Member | Name | Student Number|
|--------|------|---------------|
| 1 | Anchen Kruger | u25073703|
| 2 | Heinrich Klopper | u25030932 |
| 3 | Kai Fynn  | u25106725 |
