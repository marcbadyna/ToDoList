//
//  toDoList.cpp
//  ToDoList
//
//  Created by Marc Badyna on 4/22/25.
//

#include <iostream>
#include "toDoList.h"
#include <fstream>

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

void ToDoList::updateTask() {
    int id;
    std::cout << "Enter task ID to update: ";
    std::cin >> id;
    std::cin.ignore();
    
    for (Task& task : tasks) {
        if (task.getId() == id) {
            std::string title, description, dueDate;
            
            std::cout << "New title: ";
            std::getline(std::cin, title);
            std::cout << "New description: ";
            std::getline(std::cin, description);
            std::cout << "New due date: ";
            std::getline(std::cin, dueDate);
            
            task.editTask(title, description, dueDate);
            std::cout << "Task updated.\n";
            return;
        }
    }
    std::cout << "Task not found.\n";
}

void ToDoList::markTaskComplete() {
    int id;
    std::cout << "Enter task ID to mark as complete: ";
    std::cin >> id;
    std::cin.ignore();
    
    for (Task& task : tasks) {
        if (task.getId() == id) {
            task.markComplete();
            std::cout << "Task marked as complete.\n";
            return;
        }
    }
    std::cout << "Task not found.\n";
}

void ToDoList::displayAllTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks to display.\n";
        return;
    }
    
    for (const Task& task : tasks) {
        task.displayTask();
    }
}

void ToDoList::saveToFile() const {
    std::ofstream outFile("tasks.txt");
    
    for (const Task& task : tasks) {
        outFile << task.getId() << "\n"
                << task.getTitle() << "\n"
                << task.getDescription() << "\n"
                << task.getDueDate() << "\n"
        << task.isTaskCompleted() << "\n";
    }
    outFile.close();
    std::cout << "Tasks saved to file.\n";
}

void ToDoList::loadFromFile() {
    std::ifstream inFile("tasks.txt");
    
    tasks.clear();
    nextId = 1;
    
    int id;std::string title, description, dueDate;
    bool isCompleted;
    
    while (inFile >> id) {
        inFile.ignore();
        std::getline(inFile, title);
        std::getline(inFile, description);
        std::getline(inFile, dueDate);
        inFile >> isCompleted;
        inFile.ignore();
        
        Task task(id, title, description, dueDate);
        if (isCompleted) task.markComplete();
        
        tasks.push_back(task);
        if (id >= nextId) nextId = id + 1;
    }
    
    inFile.close();
    std::cout << "Tasks loaded from file.\n";
}
