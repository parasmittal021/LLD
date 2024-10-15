#include <iostream>
#include <vector>
#include "Task.cpp"
#include "Iterator.cpp"
#include "Collection.cpp"
#include "TaskIterator.cpp"
#include "TaskCollection.cpp"
using namespace std;

int main() {
    Task task1("Task 1");
    Task task2("Task 2");   
    Task task3("Task 3");
    vector<Task> tasks;
    tasks.push_back(task1);
    tasks.push_back(task2);
    tasks.push_back(task3);
    TaskCollection taskCollection(tasks);
    Iterator<Task>* taskIterator = taskCollection.createIterator();
    while(taskIterator->hasNext()) {
        Task task = taskIterator->next();
        cout << task.getTitle() << endl;
    }
    return 0;
}