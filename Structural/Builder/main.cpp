#include <iostream>
using namespace std;

class Workshop {
    public:
        virtual void work() = 0;
        virtual ~Workshop() {}
};

class Produce : public Workshop{
        public:
            void work() {
                cout<<"Produced"<<endl;
            }
};

class Assemble : public Workshop {
        public:
            void work() {
                cout<<"Assembled"<<endl;
            }
};

class Vehicle {
    protected:
        Workshop* produce;
        Workshop* assemble;
    
    public:
        Vehicle(Workshop* produce, Workshop* assemble) {
            this->produce = produce;
            this->assemble = assemble;
        }
        virtual void manufacture() = 0;
};

class Car : public Vehicle {
    public:
        Car(Workshop* produce, Workshop* assemble) : Vehicle(produce, assemble) {
            
        }
        void manufacture() {
            cout<<"Car manufacturing starts"<<endl;
            cout<<"Car ";
            produce->work();
            cout<<"Car ";
            assemble->work();
        }
    
};


int main() {
    Workshop* produce = new Produce();
    Workshop* assemble = new Assemble();
    Car c(produce, assemble);
    c.manufacture();
    return 0;
}




