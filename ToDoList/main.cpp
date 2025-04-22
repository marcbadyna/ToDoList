//
//  main.cpp
//  ToDoList
//
//  Created by Marc Badyna on 4/22/25.
//

#include <iostream>
#include "toDoList.h"

int main() {
    ToDoList todo;
    todo.loadFromFile();
    
    int choice;
    
    do {
        std::cout << "\n===== TO-DO LIST MENU =====\n";
                std::cout << "1. Add Task\n";
                std::cout << "2. View Tasks\n";
                std::cout << "3. Edit Task\n";
                std::cout << "4. Delete Task\n";
                std::cout << "5. Mark Task as Completed\n";
                std::cout << "6. Exit\n";
                std::cout << "Enter your choice: ";

                std::cin >> choice;
                std::cin.ignore();
        
        switch (choice) {
            case 1:
                todo.addTask();
                break;
            case 2:
                todo.displayAllTasks();
            case 3:
                todo.updateTask();
            case 4:
                todo.removeTask();
            case 5:
                todo.markTaskComplete();
            case 6:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
    
    todo.saveToFile();
    std::cout << "Goodbye!\n";
    
    return 0;
}
