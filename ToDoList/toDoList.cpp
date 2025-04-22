//
//  toDoList.cpp
//  ToDoList
//
//  Created by Marc Badyna on 4/22/25.
//

#include <iostream>
#include "toDoList.h"

ToDoList::ToDoList() : nextId(1) {}

void ToDoList::addTask() {
    std::string title, description, dueDate;
    
    std::cout << "Enter task title: ";
    std::getline(std::cin, title);
    
    std::cout << "Enter task description: ";
    std::getline(std::cin, description);
    
    std::cout << "Enter due date (e.g., 2025-04-25): ";
    std::getline(std::cin, dueDate);
    
    Task newTask(nextId, title, description, dueDate);
    tasks.push_back(newTask);
    ++nextId;
    
    std::cout << "Task added!\n";
}

void ToDoList::removeTask() {
    int id;
    std::cout << "Enter task ID to remove: ";
    std::cin >> id;
    std::cin.ignore();
    
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getId() == id) {
            tasks.erase(it);
            std::cout << "Task removed.\n";
            return;
        }
    }
    std::cout << "Task not found.\n";
}
