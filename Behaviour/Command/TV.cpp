#include "Device.cpp";
#include <iostream>
using namespace std;

class TV: public Device {
    public:
        void turnOn() {
            cout << "TV is on" << endl;
        }
        void turnOff() {
            cout << "TV is off" << endl;
        }
        void channelChange() {
            cout << "TV channel is changed" << endl;
        }
};