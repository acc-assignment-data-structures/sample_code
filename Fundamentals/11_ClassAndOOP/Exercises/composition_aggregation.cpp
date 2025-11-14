#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Composition and Aggregation Example
 * 
 * Demonstrates:
 * - Composition: Engine is part of Car (strong ownership)
 * - Aggregation: Driver uses Car (weak relationship)
 * - Has-a relationships
 */

// Component class for Composition
class Engine {
private:
    string type;
    int horsepower;
    double displacement;

public:
    Engine(string engineType = "V6", int hp = 200, double disp = 3.0) {
        type = engineType;
        horsepower = hp;
        displacement = disp;
        cout << "Engine created: " << type << endl;
    }

    ~Engine() {
        cout << "Engine destroyed: " << type << endl;
    }

    void start() {
        cout << "Engine started: " << type << " (" << horsepower << " HP)" << endl;
    }

    void stop() {
        cout << "Engine stopped" << endl;
    }

    void displaySpecs() const {
        cout << "  Engine Type: " << type << endl;
        cout << "  Horsepower: " << horsepower << " HP" << endl;
        cout << "  Displacement: " << displacement << "L" << endl;
    }

    string getType() const {
        return type;
    }
};

// Component class
class Tire {
private:
    string brand;
    double pressure;

public:
    Tire(string tireBrand = "Generic", double psi = 32.0) {
        brand = tireBrand;
        pressure = psi;
    }

    void inflate(double psi) {
        pressure = psi;
        cout << "Tire inflated to " << pressure << " PSI" << endl;
    }

    void displayInfo() const {
        cout << "  Tire: " << brand << " - " << pressure << " PSI" << endl;
    }
};

// Composite class - Car contains Engine and Tires (Composition)
class Car {
private:
    string make;
    string model;
    int year;
    Engine engine;  // Composition - Engine is part of Car
    vector<Tire> tires;  // Composition - Tires belong to Car

public:
    // Constructor with initializer list
    Car(string carMake, string carModel, int carYear, 
        string engineType, int hp, double disp) 
        : make(carMake), model(carModel), year(carYear),
          engine(engineType, hp, disp) {
        
        // Initialize 4 tires
        for (int i = 0; i < 4; i++) {
            tires.push_back(Tire("Michelin", 32.0));
        }
        
        cout << "Car created: " << year << " " << make << " " << model << endl;
    }

    ~Car() {
        cout << "Car destroyed: " << make << " " << model << endl;
    }

    void startCar() {
        cout << "\nStarting " << make << " " << model << "..." << endl;
        engine.start();
        cout << "Car is ready to drive!" << endl;
    }

    void stopCar() {
        cout << "\nStopping " << make << " " << model << "..." << endl;
        engine.stop();
        cout << "Car stopped." << endl;
    }

    void displayInfo() const {
        cout << "\n--- Car Information ---" << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Engine Specifications:" << endl;
        engine.displaySpecs();
        cout << "Tires:" << endl;
        for (size_t i = 0; i < tires.size(); i++) {
            cout << "  Tire " << (i + 1) << ": ";
            tires[i].displayInfo();
        }
        cout << "----------------------" << endl;
    }

    string getMake() const {
        return make;
    }

    string getModel() const {
        return model;
    }
};

// Class that has aggregation relationship with Car
class Driver {
private:
    string name;
    int licenseNumber;
    Car* currentCar;  // Aggregation - Driver uses Car but doesn't own it

public:
    Driver(string driverName, int license) {
        name = driverName;
        licenseNumber = license;
        currentCar = nullptr;
        cout << "Driver created: " << name << endl;
    }

    ~Driver() {
        // Driver doesn't destroy the car (aggregation)
        cout << "Driver profile deleted: " << name << endl;
    }

    void assignCar(Car* car) {
        currentCar = car;
        cout << name << " has been assigned to " << car->getMake() 
             << " " << car->getModel() << endl;
    }

    void drive() {
        if (currentCar != nullptr) {
            cout << "\n" << name << " is driving the " 
                 << currentCar->getMake() << " " << currentCar->getModel() << endl;
            currentCar->startCar();
        } else {
            cout << name << " has no car assigned!" << endl;
        }
    }

    void parkCar() {
        if (currentCar != nullptr) {
            cout << "\n" << name << " is parking the car..." << endl;
            currentCar->stopCar();
        } else {
            cout << name << " has no car to park!" << endl;
        }
    }

    void displayInfo() const {
        cout << "\n--- Driver Information ---" << endl;
        cout << "Name: " << name << endl;
        cout << "License: " << licenseNumber << endl;
        if (currentCar != nullptr) {
            cout << "Current Car: " << currentCar->getMake() 
                 << " " << currentCar->getModel() << endl;
        } else {
            cout << "Current Car: None assigned" << endl;
        }
        cout << "-------------------------" << endl;
    }
};

// Class demonstrating multiple aggregation
class ParkingLot {
private:
    string location;
    int capacity;
    vector<Car*> parkedCars;  // Aggregation - ParkingLot doesn't own cars

public:
    ParkingLot(string loc, int cap) {
        location = loc;
        capacity = cap;
        cout << "Parking lot created at: " << location << endl;
    }

    ~ParkingLot() {
        // Doesn't delete cars (aggregation)
        cout << "Parking lot closed at: " << location << endl;
    }

    bool parkCar(Car* car) {
        if (parkedCars.size() < static_cast<size_t>(capacity)) {
            parkedCars.push_back(car);
            cout << car->getMake() << " " << car->getModel() 
                 << " parked at " << location << endl;
            return true;
        } else {
            cout << "Parking lot is full!" << endl;
            return false;
        }
    }

    void displayStatus() const {
        cout << "\n--- Parking Lot Status ---" << endl;
        cout << "Location: " << location << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Parked Cars: " << parkedCars.size() << "/" << capacity << endl;
        
        if (!parkedCars.empty()) {
            cout << "Cars currently parked:" << endl;
            for (size_t i = 0; i < parkedCars.size(); i++) {
                cout << "  " << (i + 1) << ". " << parkedCars[i]->getMake() 
                     << " " << parkedCars[i]->getModel() << endl;
            }
        }
        cout << "-------------------------\n" << endl;
    }
};

int main() {
    cout << "=== Composition and Aggregation Demo ===" << endl;

    // Create cars (composition - cars own their engines and tires)
    cout << "\n1. Creating cars:\n" << endl;
    Car car1("Toyota", "Camry", 2023, "V6", 301, 3.5);
    Car car2("Honda", "Civic", 2023, "I4", 180, 2.0);
    Car car3("Ford", "Mustang", 2023, "V8", 450, 5.0);

    // Display car information
    cout << "\n2. Car specifications:\n" << endl;
    car1.displayInfo();
    car2.displayInfo();

    // Create drivers (aggregation - drivers use cars but don't own them)
    cout << "\n3. Creating drivers:\n" << endl;
    Driver driver1("Alice Johnson", 123456);
    Driver driver2("Bob Smith", 654321);

    // Assign cars to drivers (aggregation relationship)
    cout << "\n4. Assigning cars to drivers:\n" << endl;
    driver1.assignCar(&car1);
    driver2.assignCar(&car2);

    driver1.displayInfo();
    driver2.displayInfo();

    // Drivers use their cars
    cout << "\n5. Drivers using their cars:\n" << endl;
    driver1.drive();
    driver2.drive();

    // Create parking lot (aggregation - parking lot doesn't own cars)
    cout << "\n6. Creating parking lot:\n" << endl;
    ParkingLot lot("Downtown", 5);

    // Park cars
    cout << "\n7. Parking cars:\n" << endl;
    lot.parkCar(&car1);
    lot.parkCar(&car2);
    lot.parkCar(&car3);

    lot.displayStatus();

    // Drivers park their cars
    cout << "\n8. Drivers parking:\n" << endl;
    driver1.parkCar();
    driver2.parkCar();

    cout << "\n=== Program ending ===" << endl;
    cout << "(Note: Cars will be destroyed, but drivers only lose reference)\n" << endl;
    
    return 0;
}
