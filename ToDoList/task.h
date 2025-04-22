//
//  task.h
//  ToDoList
//
//  Created by Marc Badyna on 4/22/25.
//

#ifndef task_h
#define task_h
#include <string>

class Task {
private:
    int id;
    std::string title;
    std::string description;
    std::string dueDate;
    bool isCompleted;
    
public:
    Task(int id, std::string title, std::string description, std::string dueDate);
    void markComplete();
    void editTask(std::string newTitle, std::string newDescription, std::string newDueDate);
    void displayTask() const;
    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    std::string getDueDate() const;
    bool isTaskCompleted() const;
};

#endif
