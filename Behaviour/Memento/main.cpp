#include<vector>
#include<string>
#include <iostream>
using namespace std;

class Memento {
    string state = "";
    public:
        Memento(string state) {
            this->state = state;
        }
        string getState() {
            return state;
        }  
};   

class History {
    vector<Memento> mementos;
    public:
        void save(Memento memento) {
            mementos.push_back(memento);
        }
    
        Memento getMemento(int index) {
            return mementos[index];
        }
};

class TextEditor {
    string content= "";
    public:
        void type(string val) {
            content+=val;
        }
        Memento save() {
           Memento memento(content);
            return memento;
        }
    
        string getContent() {
            return content;
        }
    
        void restore(Memento m){
            content = m.getState();
        }
};

int main() {
    History history;
    TextEditor textEditor;
    
    textEditor.type("Hello, ");
    Memento m1 = textEditor.save();
    history.save(m1);
    
    textEditor.type("world");
    Memento m2 = textEditor.save();
    history.save(m2);
    
    cout<<textEditor.getContent()<<endl;
    
    Memento m3 = history.getMemento(0);
    textEditor.restore(m3);
    
    cout<<textEditor.getContent()<<endl;
    return 0;
}