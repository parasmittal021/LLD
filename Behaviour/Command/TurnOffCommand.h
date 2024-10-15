#include "Command.cpp";
#include "Device.cpp";

class TurnOffCommand : public Command {
    Device *device;
    public:
    TurnOffCommand(Device *device) {
        this->device = device;
    }
    void execute() {
        device->turnOn();
    }
};