#include <iostream>
using namespace std;

class Approver {
    protected:
        Approver* next;
    public: 
        void setNext(Approver* next) {
            this->next = next;
        }
        virtual void processRequest(int amount) = 0;
        virtual ~Approver() {}
};

class Manager: public Approver {
    public:
    void processRequest(int amount) {
        if(amount < 1000) {
            cout << "Manager can approve " << amount << endl;
        } else if(next) {
            next->processRequest(amount);
        } else {
            cout<<"Request can't be approved" << endl;
        }
    }
};

class Director: public Approver {
    public:
    void processRequest(int amount) {
        if(amount < 5000) {
            cout << "Director can approve " << amount << endl;
        } else if(next) {
            next->processRequest(amount);
        } else {
            cout<<"Request can't be approved" << endl;
        }
    }
};

class VP: public Approver {
    public:
    void processRequest(int amount) {
        if(amount < 10000) {
            cout << "VP can approve " << amount << endl;
        } else if(next) {
            next->processRequest(amount);
        } else {
            cout<<"Request can't be approved" << endl;
        }
    }
};

class CEO: public Approver {
    public:
    void processRequest(int amount) {
        if(amount < 50000) {
            cout << "CEO can approve " << amount << endl;
        } else if(next) {
            next->processRequest(amount);
        } else {
            cout<<"Request can't be approved" << endl;
        }
    }
};

int main() {
    Approver* manager = new Manager();  
    Approver* director = new Director();
    Approver* vp = new VP();    
    Approver* ceo = new CEO();

    manager->setNext(director);
    director->setNext(vp);
    vp->setNext(ceo);
    
    manager->processRequest(52000);

    delete manager;
    delete director;
    delete vp;
    delete ceo;
    return 0;
}