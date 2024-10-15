#include "Device.cpp"
#include "Stereo.cpp"
#include "TV.cpp"
#include "Command.cpp";
#include "RemoteControl.cpp";
#include "ChannelChangeCommand.cpp";
#include "TurnOnCommand.cpp";
#include "TurnOffCommand.h"


int main() {
    Device* stereo = new Stereo();
    Device* tv = new TV();
    Command* turnOnStereo = new TurnOnCommand(stereo);
    Command* turnOffStereo = new TurnOffCommand(stereo);
    Command* turnOnTV = new TurnOnCommand(tv);
    Command* turnOffTV = new TurnOffCommand(tv);
    Command* channelChangeStereo = new ChannelChangeCommand(stereo);
    Command* channelChangeTV = new ChannelChangeCommand(tv);
    RemoteControl* remoteControl = new RemoteControl();
    remoteControl->setCommand(turnOnStereo);    
    remoteControl->pressButton();

    return 0;
}