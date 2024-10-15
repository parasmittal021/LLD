#include<string>
#include<ctime>
#include<mutex>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

enum VehicleType {
    MOTORCYCLE,
    CAR,
    TRUCK
};

class Vehicle {
    protected:
        string licensePlate;
        VehicleType vehicleType;
    public:
        Vehicle(string licensePlate, VehicleType vehicleType) {
            this->licensePlate = licensePlate;
            this->vehicleType = vehicleType;
        }
        string getLicensePlate() {
            return licensePlate;
        }
        VehicleType getVehicleType() {
            return vehicleType;
        }
};

class Car : public Vehicle {
    public:
        Car(string licensePlate): Vehicle(licensePlate, VehicleType::CAR){
            
        }
};

class MotorCycle : public Vehicle {
    public:
        MotorCycle(string licensePlate) : Vehicle(licensePlate, VehicleType::MOTORCYCLE){
            
        }
};

class Truck : public Vehicle {
    public:
        Truck(string licensePlate) : Vehicle(licensePlate, VehicleType::TRUCK){
            
        }
};

class Ticket {
    private:
        string licensePlate;
        int floor;
        time_t entryTime;
        string ticketId;
    public:
        Ticket(string licensePlate, int floor, time_t entryTime) {
            this->licensePlate = licensePlate;
            this->floor = floor;
            this->entryTime = time(0);
            this->ticketId = this->licensePlate + to_string(entryTime);
        }
        
        int getFloor() {
            return floor;
        }
        
        time_t getEntryTime() {
            return entryTime;
        }
    
};

class Payment {
    public:
        static int calculate(time_t entryTime, time_t endTime, VehicleType vehicleType) {
            int time_diff = (endTime - entryTime)+1;
            switch(vehicleType) {
                case VehicleType::MOTORCYCLE:
                        return time_diff*10;
                case VehicleType::CAR:
                        return time_diff*20;  
                case VehicleType::TRUCK:
                        return time_diff*30;
                default:
                    return time_diff*10;
            }
        }
};

class ParkingSpot {
    private:
        VehicleType spotType;
        string licensePlate;
        Vehicle* currentVehicle;
        int spotNumber;
    public:
        ParkingSpot(VehicleType spotType, int spotNumber) {
            this->spotType = spotType;
            this->spotNumber = spotNumber;
            currentVehicle = nullptr;
        }
        
        bool isAvailable() {
            return currentVehicle == nullptr;
        }
    
        bool canFitVehicle(Vehicle* vehicle) {
            if(spotType == vehicle->getVehicleType()) {
                return true;
            }
            return false;
        }
        void removeVehicle() {
            currentVehicle = nullptr;
        }
        void parkVehicle(Vehicle* vehicle) {
            currentVehicle = vehicle;
        }
    
        int getSpotNumber() {
            return spotNumber;
        }
    
        Vehicle* getCurrentVehicle() {
            return currentVehicle;
        }
    
};

class ParkingFloor {
    private:
        vector<ParkingSpot*> carParking;
        vector<ParkingSpot*> truckParking;
        vector<ParkingSpot*> motorCycleParking;
        mutex floorMutex;
    public:
        ParkingFloor(int motorCycleSpot, int carSpot, int truckSpot) {
            int spotNumber = 0;
            for(int i = 0; i<motorCycleSpot; i++){
                motorCycleParking.push_back(new ParkingSpot(VehicleType::MOTORCYCLE, spotNumber++));
            }
            for(int i = 0; i<carSpot; i++){
                carParking.push_back(new ParkingSpot(VehicleType::CAR, spotNumber++));
            }
            for(int i = 0; i<truckSpot; i++) {
                truckParking.push_back(new ParkingSpot(VehicleType::TRUCK, spotNumber++));
            }
        }
        
        int parkVehicle(Vehicle* vehicle) {
            lock_guard<mutex> lock(floorMutex);
            int spotNumber = -1;
            VehicleType vehicleType = vehicle->getVehicleType();
            vector<ParkingSpot*> spots;
            switch(vehicleType) {
                case VehicleType::MOTORCYCLE:
                        spots = motorCycleParking;
                        break;
                case VehicleType::CAR:
                        spots = carParking;
                        break;  
                case VehicleType::TRUCK:
                        spots = truckParking;
                        break;
                default:
                    spots = motorCycleParking;
                        break;
            }
            for(auto spot: spots) {
                if(spot->isAvailable() && spot->canFitVehicle(vehicle)){
                    spot->parkVehicle(vehicle);
                    return spot->getSpotNumber();
                }
            }
            return -1;
        }
        
        void removeVehicle(Vehicle* vehicle) {
            lock_guard<mutex> lock(floorMutex);
            vector<ParkingSpot*> spots;
            VehicleType vehicleType = vehicle->getVehicleType();
            switch(vehicleType) {
                case VehicleType::MOTORCYCLE:
                        spots = motorCycleParking;
                        break;
                case VehicleType::CAR:
                        spots = carParking;
                        break;  
                case VehicleType::TRUCK:
                        spots = truckParking;
                        break;
                default:
                    spots = motorCycleParking;
                        break;
            }
            for(auto spot: spots) {
                if(!spot->isAvailable() && spot->getCurrentVehicle() == vehicle){
                    spot->removeVehicle();
                    break;
                }
            }
        }
        
        int availableSpots(VehicleType vehicleType) {
            lock_guard<mutex> lock(floorMutex);
            int cnt = 0;
            vector<ParkingSpot*> spots;
            switch(vehicleType) {
                case VehicleType::MOTORCYCLE:
                        spots = motorCycleParking;
                        break;
                case VehicleType::CAR:
                        spots = carParking;
                        break;  
                case VehicleType::TRUCK:
                        spots = truckParking;
                        break;
                default:
                    spots = motorCycleParking;
                        break;
            }
            for(auto spot: spots) {
                if(spot->isAvailable()){
                    cnt++;
                }
            }
            return cnt;
        }
};

class ParkingLot {
    private:
        int floors;
        vector<ParkingFloor*> parkingFloors;
        mutex lotMutex;
    unordered_map<std::string, Ticket*> activeTickets; 
    public:
        ParkingLot(int floors, int motorCycleSpots, int carSpots, int truckSpots) {
            for(int i=0;i<floors;i++){
                parkingFloors.emplace_back(new ParkingFloor(motorCycleSpots, carSpots, truckSpots));
            }
            this->floors = floors;
        }
        
        Ticket* parkVehicle(Vehicle* vehicle){
            lock_guard<mutex> lock(lotMutex);
            for(int i=0;i<floors;i++) {
                int spotNumber = parkingFloors[i]->parkVehicle(vehicle);
                if(spotNumber!=-1){
                   Ticket* ticket  = new Ticket(vehicle->getLicensePlate(), i+1, time(0));
                    activeTickets[vehicle->getLicensePlate()] = ticket;
                    return ticket;
                }
            }
            return nullptr;
        }
    
        int exitVehicle(Vehicle* vehicle) {
            lock_guard<mutex> lock(lotMutex);
            int fees = 0;
            auto it = activeTickets.find(vehicle->getLicensePlate());
                if(it!=activeTickets.end()) {
                    Ticket* ticket = it->second;
                    fees = Payment::calculate(ticket->getEntryTime(), time(0), vehicle->getVehicleType());
                    activeTickets[vehicle->getLicensePlate()] = nullptr;
                    parkingFloors[ticket->getFloor()-1]->removeVehicle(vehicle);
                }
            return fees;
        }
    
    int getAvailableSpots(VehicleType vehicleType) {
        std::lock_guard<std::mutex> lock(lotMutex);
        int totalAvailable = 0;
        for (auto parkingFloor : parkingFloors) {
            totalAvailable += parkingFloor->availableSpots(vehicleType);
        }
        return totalAvailable;
    }
};

int main() {
    ParkingLot lot(3, 20, 10, 5); 
    
    Vehicle* car = new Car("ABC123");
    Vehicle* motorCycle = new MotorCycle("DEF456");
    Vehicle* truck = new Truck("XYZ789");

    // Simulate parking of vehicles
    Ticket* carTicket = lot.parkVehicle(car);
    Ticket* truckTicket = lot.parkVehicle(truck);
    Ticket* bikeTicket = lot.parkVehicle(motorCycle);

    std::cout << "Available spots for cars: " << lot.getAvailableSpots(VehicleType::CAR) << std::endl;
    std::cout << "Available spots for trucks: " << lot.getAvailableSpots(VehicleType::TRUCK) << std::endl;
    std::cout << "Available spots for bikes: " << lot.getAvailableSpots(VehicleType::MOTORCYCLE) << std::endl;

    // Simulate exiting of a vehicle
    double carFee = lot.exitVehicle(car);
    std::cout << "Car exited. Fee paid: $" << carFee << std::endl;

    return 0;
    return 0;
}