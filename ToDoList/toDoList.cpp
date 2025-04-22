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
