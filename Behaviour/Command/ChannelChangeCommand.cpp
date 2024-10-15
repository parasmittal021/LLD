#include "Command.cpp";
#include "Device.cpp";

class ChannelChangeCommand : public Command {    
    Device *device;
    public:
    ChannelChangeCommand(Device *device) {
        this->device = device;
    }
    void execute() {
        device->channelChange();
    }
};
