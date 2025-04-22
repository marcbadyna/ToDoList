//
//  task.cpp
//  ToDoList
//
//  Created by Marc Badyna on 4/22/25.
//

#include "task.h"
#include <string>

Task::Task(int id, std::string title, std::string description, std::string dueDate) : id(id), title(title), description(description), dueDate(dueDate), isCompleted(false) {}
