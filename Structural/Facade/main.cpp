#include <iostream>
using namespace std;

class Screen {
    public:
    void on() {
        cout<<"Screen on"<<endl;
    }
    void off() {
        cout<<"Screen off"<<endl;
    }
};

class SoundSystem {
    int vol;
    public:
    void on() {
        cout<<"SoundSystem on"<<endl;
    }
    void off() {
        cout<<"SoundSystem off"<<endl;
    }
    void setVolume(int vol) {
        this->vol = vol;
    }
};

class DVDPlayer {
    public:
    void on() {
        cout<<"DVDPlayer on"<<endl;
    }
    void off() {
        cout<<"DVDPlayer off"<<endl;
    }
    void play() {
        cout<<"DVDPlayer play"<<endl;
    }
    void stop() {
        cout<<"DVDPlayer stop"<<endl;
    }
};

class HomeThreatre {
    Screen screen;
    DVDPlayer dvd;
    SoundSystem soundSystem;
    public:
    HomeThreatre(Screen& screen, DVDPlayer& dvd, SoundSystem& soundSystem){
        this->screen = screen;
        this->dvd = dvd;
        this->soundSystem=soundSystem;
    }
    
    void watchMovie() {
        cout<<"Movie start playing"<<endl;
        screen.on();
        dvd.on();
        soundSystem.on();
        soundSystem.setVolume(20);
        dvd.play();
    }
    void stopMovie(){
        cout<<"Movie stops"<<endl;
        screen.off();
        dvd.off();
        soundSystem.off();
        soundSystem.setVolume(0);
        dvd.stop();
    }
};

int main() {
    Screen screen;
    DVDPlayer dvd;
    SoundSystem soundSystem;
    HomeThreatre homeThreatre(screen, dvd, soundSystem);
    homeThreatre.watchMovie();
    cout<<endl;
    homeThreatre.stopMovie();
    return 0;
}