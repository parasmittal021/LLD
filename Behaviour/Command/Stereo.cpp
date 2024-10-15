#include "Device.cpp";
#include <iostream>
using namespace std;

class Stereo: public Device {
    public:
        void turnOn() {
            cout << "Stereo is on" << endl;
        }
        void turnOff() {
            cout << "Stereo is off" << endl;
        }
        void channelChange() {
            cout << "Stereo channel is changed" << endl;
        }
};