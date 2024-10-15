#include <vector>
#include "Task.cpp"
#include "Iterator.cpp"
#include "Collection.cpp"
#include "TaskIterator.cpp"
using namespace std;

class TaskCollection : public Collection<Task> {
    vector<Task> tasks;
    public:
        TaskCollection(vector<Task> tasks) {
            this->tasks = tasks;
        }
        Iterator<Task>* createIterator() {
            return new TaskIterator<Task>(tasks);
        }
        ~TaskCollection() {}
};