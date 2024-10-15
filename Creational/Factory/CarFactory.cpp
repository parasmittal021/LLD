#include <iostream>
using namespace std;

enum CarType {
    SEDAN,
    SUV,
    SPORTS
};

class Car {
    public:
    virtual void specifications() = 0;
    virtual ~Car() {}
};


class Sedan : public Car {
    public:
    void specifications() {
        cout << "Sedan" << endl;
    }
};

class Suv : public Car {
    public:
    void specifications() {
        cout << "SUV" << endl;
    }
};

class Sports : public Car {
    public:
    void specifications() {
        cout << "Sports" << endl;
    }
};

class CarFactory {
    public:
    static Car* createCar(CarType carType){
        switch(carType) {
            case CarType::SEDAN:
                return new Sedan();
            case CarType::SUV:
                return new Suv();
            case CarType::SPORTS:
                return new Sports();
            default:
                return nullptr;   
        }
    }
};