//
//  toDoList.h
//  ToDoList
//
//  Created by Marc Badyna on 4/22/25.
//

#include <vector>
#include "task.h"

class ToDoList {
private:
    std::vector<Task> tasks;
    int nextId;
public:
    ToDoList();
    void addTask();
    void removeTask();
    void updateTask();
    void markTaskComplete();
    void displayAllTasks();
    void saveToFile();
    void loadFromFile();
}
