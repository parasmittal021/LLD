#include <iostream>
#include<vector>
using namespace std;

class Subscriber {
    public:
    virtual void update(float temperature) = 0;
    virtual ~Subscriber() {}
};

class Publisher {
    public:
    virtual void setTemperature(float temperature) = 0;
    virtual void addSubscriber(Subscriber* subscriber) = 0;
    virtual void removeSubscriber(Subscriber* subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~Publisher() {}
};

class WeatherStation: public Publisher {
    private:
        vector<Subscriber*> subscribers;
        float temperature;
    public:
    void setTemperature(float temperature) {
        this->temperature = temperature;
        notifySubscribers();
    }
    void addSubscriber(Subscriber* subscriber){
        subscribers.push_back(subscriber);
    }
    void removeSubscriber(Subscriber* subscriber){
        const auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if(it!=subscribers.end()) {
            subscribers.erase(it);
        }
    }
    void notifySubscribers() {
        for(auto subscriber: subscribers) {
            subscriber->update(temperature);
        }
    }
};

class PhoneDisplay: public Subscriber {
    private:
        float temperature;
    public:
    void update(float temperature) {
        this->temperature = temperature;
        cout << "Phone Display: " << temperature << endl;
    }
};

int main() {
    Publisher* weatherStation = new WeatherStation();
    Subscriber* phoneDisplay = new PhoneDisplay();

    weatherStation->addSubscriber(phoneDisplay);

    weatherStation->setTemperature(30.0);

    delete weatherStation;
    delete phoneDisplay;


    return 0;
}