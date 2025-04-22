//
//  task.h
//  ToDoList
//
//  Created by Marc Badyna on 4/22/25.
//

class Task {
private:
    int id;
    string title;
    string description;
    string dueDate;
    bool isCompleted;
    
public:
    Task(int id, string title, string description, string dueDate);
    void markComplete();
    void editTask(string newTitle, string newDescription, string newDueDate);
    void displayTask();
}
