#include "Menu.h"

void Menu::displayMenu()
{
    while (true)
    {
        cout << "1. Add Task\n";
        cout << "2. Display All Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Edit Task\n";
        cout << "5. Sort by Date\n";
        cout << "6. Save to File\n";
        cout << "7. Load from File\n";
        cout << "8. Exit\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string task;
            int day, month, year;
            cout << "Enter task: ";
            cin.ignore();
            getline(cin, task);
            cout << "Enter date (day month year): ";
            cin >> day >> month >> year;
            Task newTask(task, day, month, year);
            todoList.addTask(newTask);
            break;
        }
        case 2:
        {
            todoList.displayAll();
            break;
        }
        case 3:
        {
            int index;
            cout << "Enter index to delete: ";
            cin >> index;
            todoList.deleteTask(index);
            break;
        }
        case 4:
        {
            int index, day, month, year;
            string task;
            cout << "Enter index to edit: ";
            cin >> index;
            cout << "Enter new task: ";
            cin.ignore();
            getline(cin, task);
            cout << "Enter new date (day month year): ";
            cin >> day >> month >> year;
            todoList.editTask(index, task, day, month, year);
            break;
        }
        case 5:
        {
            todoList.sortByDate();
            break;
        }
        case 6:
        {
            string filename;
            cout << "Enter filename to save: ";
            cin >> filename;
            todoList.saveToFile(filename);
            break;
        }
        case 7:
        {
            string filename;
            cout << "Enter filename to load: ";
            cin >> filename;
            todoList.loadFromFile(filename);
            break;
        }
        case 8:
        {
            return;
        }
        default:
        {
            cout << "Invalid choice. Please select again.\n";
            break;
        }
        }
    }
}
