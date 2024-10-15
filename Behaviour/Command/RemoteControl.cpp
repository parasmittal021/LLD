#include "Command.cpp";

class RemoteControl {
    Command *command;
    public:
    void setCommand(Command *command) {
        this->command = command;
    }
    void pressButton() {
        command->execute();
    }
};