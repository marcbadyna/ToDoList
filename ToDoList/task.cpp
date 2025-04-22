//
//  task.cpp
//  ToDoList
//
//  Created by Marc Badyna on 4/22/25.
//

#include <iostream>
#include "task.h"
#include <string>

Task::Task(int id, std::string title, std::string description, std::string dueDate) : id(id), title(title), description(description), dueDate(dueDate), isCompleted(false) {}

void Task::markComplete() {
    isCompleted = true;
}

void Task::editTask(std::string newTitle, std::string newDescription, std::string newDueDate) {
    title = newTitle;
    description = newDescription;
    dueDate = newDueDate;
}

void Task::displayTask() const {
    std::cout << "Task ID: " << id << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Due Date: " << dueDate << std::endl;
    std::cout << "Status: " << (isCompleted ? "Completed" : "Incomplete") << std::endl;
    std::cout << std::endl;
}

int Task::getId() const {
    return id;
}

std::string Task::getTitle() const {
    return title;
}

std::string Task::getDescription() const {
    return description;
}

std::string Task::getDueDate() const {
    return dueDate;
}

bool Task::isTaskCompleted() const {
    return isCompleted;
}
