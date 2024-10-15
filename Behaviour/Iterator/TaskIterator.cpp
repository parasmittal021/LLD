#pragma once
#include <vector>
#include "Task.cpp"
#include "Iterator.cpp"
using namespace std;
template <typename T>

class TaskIterator : public Iterator<T> {
    vector<T> tasks;
    int position;
    public:
        TaskIterator(vector<T> tasks) {
            this->tasks = tasks;
            position = 0;
        }
        bool hasNext() {
            return position < tasks.size();
        }
        T next() {
            return tasks[position++];
        }
        ~TaskIterator() {}
};