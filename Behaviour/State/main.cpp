#include <iostream>
using namespace std;

class TrafficLightState {
    public:
        virtual void handle() = 0;
    virtual ~TrafficLightState() {}
};

class RedLightState: public TrafficLightState {
    public:
        void handle() {
            cout << "Red Light" << endl;
        }
};  

class YellowLightState: public TrafficLightState {
    public:
        void handle() {
            cout << "Yellow Light" << endl;
        }
};

class GreenLightState: public TrafficLightState {
    public:
        void handle() {
            cout << "Green Light" << endl;
        }
};

class TrafficLight {
    public:
        TrafficLightState* state;

        void setState(TrafficLightState* state) {
            this->state = state; 
        }

        void display() {
            state->handle();
        }
};

int main() {
    TrafficLight trafficLight;
    RedLightState redLightState;
    YellowLightState yellowLightState;
    GreenLightState greenLightState;

    trafficLight.setState(&redLightState);
    trafficLight.display();

    trafficLight.setState(&yellowLightState);
    trafficLight.display();

    trafficLight.setState(&greenLightState);
    trafficLight.display();
}