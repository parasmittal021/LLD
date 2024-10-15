#pragma once
#include <string>
using namespace std;

class Task {
    string title;
    public:
        Task(string title) {
            this->title = title;
        }
        string getTitle() {
            return title;
        }
        void setTitle(string title) {
            this->title = title;
        }
        
};