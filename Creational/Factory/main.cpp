

#include "CarFactory.cpp"

int main()  {
    Car *car =CarFactory::createCar(CarType::SEDAN);
    if(car!=nullptr) {
        car->specifications();
    }
    delete car;
    return 0;
}

