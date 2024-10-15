
#include <string>
#include <iostream>
using namespace std;

enum PlaneStatus {LANDING, TAKEOFF};

class IPlane {
    protected:
        string id;
    public:
        string getId() {
            return id;
        }
        virtual void takeoff() = 0;
        virtual void landing() = 0;
        virtual ~IPlane() {}
};

class AirTrafficController {
    public:
        virtual void notify(IPlane* p, PlaneStatus type) = 0;
        virtual ~AirTrafficController() {}
};



class ControlTower : public AirTrafficController {
    bool runwayFree = true;
    public:
        void notify(IPlane* p, PlaneStatus type ) {
            if(type == LANDING){
                if(isRunwayFree()) {
                    setIsRunwayFree(false);
                    cout<<"Runway is free and plane "<<p->getId()<<" is landing"<<endl;
                } else {
                    cout<<"Runway is occupied" << endl;
                }
            } else {
                if(isRunwayFree()) {
                    setIsRunwayFree(false);
                    cout<<"Runway is free and plane "<<p->getId()<<" is takingoff"<<endl;
                } else {
                    cout<<"Runway is occupied" << endl;
                }
            }
        }
        bool isRunwayFree() {
            return runwayFree;
        } 
        void setIsRunwayFree(bool val) {
            runwayFree = val;
        }  
};


class Plane: public IPlane {
    AirTrafficController* controlTower;
    public:
        Plane(string id, AirTrafficController* controlTower) {
            this->id = id;
            this->controlTower = controlTower;
        }
        void takeoff() {
            cout<<"Plane with id "<<id<<" is trying for take off"<<endl;
            controlTower->notify(this, PlaneStatus::TAKEOFF);
        }
        void landing() {
            cout<<"Plane with id "<<id<<" is trying for landing"<<endl;
            controlTower->notify(this, PlaneStatus::LANDING);
        }
};

int main() {
    AirTrafficController* ac = new ControlTower();
    IPlane* p1 = new Plane("123", ac);
    p1->takeoff();
    p1->landing();
    return 0;
}
