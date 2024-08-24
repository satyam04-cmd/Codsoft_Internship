#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};


void addTask(vector<Task> &tasks);

void viewTasks(const vector<Task> &tasks);

void markTaskCompleted(vector<Task> &tasks) ;

void removeTask(vector<Task> &tasks);

int main() {
    vector<Task> tasks;
    int choice;

    do {
        
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        if (choice == 1)
        {
          addTask(tasks);
        } else if (choice == 2){
            viewTasks(tasks);
        } else if (choice == 3){
            markTaskCompleted(tasks);
        } else if (choice == 4){
            removeTask(tasks);
        } else if(choice == 5){
            cout << "Exiting..." << endl;
        } else{
            cout << "Invalid choice! Please try again." << endl;
        }
        
    } while (choice != 5);

    return 0;
}

void addTask(vector<Task> &tasks) {
    string description;
    cout << "Enter the task description: ";
    cin.ignore();  
    getline(cin, description);
    tasks.push_back(Task(description));
    cout << "Task added!" << endl;
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " [" 
                 << (tasks[i].isCompleted ? "Completed" : "Pending") << "]" << endl;
        }
    }
}

void markTaskCompleted(vector<Task> &tasks) {
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void removeTask(vector<Task> &tasks) {
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}