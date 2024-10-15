#include "Command.cpp";
#include "Device.cpp";

class TurnOnCommand : public Command {
    Device *device;
    public:
    TurnOnCommand(Device *device) {
        this->device = device;
    }
    void execute() {
        device->turnOn();
    }
};