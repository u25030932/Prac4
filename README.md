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

## Debugging
```
sudo docker run -it docker_image bash
valgrind ./main
gdb ./main
```

## The team:

| Member | Name | Student Number|
|--------|------|---------------|
| 1 | Anchen Kruger | u25073703|
| 2 | Heinrich Klopper | u25030932 |
| 3 |   |   |

