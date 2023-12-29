#include <iostream>
#include <string>
#include <vector>

class Ride {
public:
    Ride() {
        // Дефолтный конструктор
        name = "Unnamed";
        speed = 0;
    }

    Ride(const std::string& name, int speed) : name(name), speed(speed) {
        // Недефолтный конструктор через список инициализаторов
    }

    Ride(const std::string& name, int speed, int duration) : name(name), speed(speed), duration(duration) {
        // Произвольный конструктор с аргументом duration
    }

    std::string getName() const {
        return name;
    }

    void setName(const std::string& newName) {
        name = newName;
    }

    int getSpeed() const {
        return speed;
    }

    void setSpeed(int newSpeed) {
        speed = newSpeed;
    }

    int getDuration() const {
        return duration;
    }

    void setDuration(int newDuration) {
        duration = newDuration;
    }

private:
    std::string name;
    int speed;
    int duration;
};

class Employee {
public:
    Employee() {
        // Дефолтный конструктор
        name = "Unknown";
        age = 0;
        children = 0;
        currentRide = nullptr;
    }

    Employee(const std::string& name, int age, int children) : name(name), age(age), children(children), currentRide(nullptr) {
        // Недефолтный конструктор через список инициализаторов
    }

    std::string getName() const {
        return name;
    }

    void setName(const std::string& newName) {
        name = newName;
    }

    int getAge() const {
        return age;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    int getChildren() const {
        return children;
    }

    void setChildren(int newChildren) {
        children = newChildren;
    }

    Ride* getCurrentRide() const {
        return currentRide;
    }

    void setCurrentRide(Ride* newCurrentRide) {
        currentRide = newCurrentRide;
    }

private:
    std::string name;
    int age;
    int children;
    Ride* currentRide;
};

class RollerCoaster : public Ride {
public:
    RollerCoaster() : Ride() {
        // Дефолтный конструктор RollerCoaster, использующий дефолтный конструктор Ride
        loopCount = 0;
        dropHeight = 0;
    }

    RollerCoaster(const std::string& name, int speed, int loopCount, int dropHeight) : Ride(name, speed) {
        this->loopCount = loopCount;
        this->dropHeight = dropHeight;
    }

    int getLoopCount() const {
        return loopCount;
    }

    void setLoopCount(int newLoopCount) {
        loopCount = newLoopCount;
    }

    int getDropHeight() const {
        return dropHeight;
    }

    void setDropHeight(int newDropHeight) {
        dropHeight = newDropHeight;
    }

    void start() {
        std::cout << "The roller coaster ride has started!\n";
    }

    void stop() {
        std::cout << "The roller coaster ride has stopped.\n";
    }

private:
    int loopCount;
    int dropHeight;
};

class FerrisWheel : public Ride {
public:
    FerrisWheel() : Ride() {
        // Дефолтный конструктор FerrisWheel, использующий дефолтный конструктор Ride
        cabinCount = 0;
        height = 0;
    }

    FerrisWheel(const std::string& name, int speed, int cabinCount, int height) : Ride(name, speed) {
        // Недефолтный конструктор FerrisWheel, использующий недефолтный конструктор Ride
        this->cabinCount = cabinCount;
        this->height = height;
    }

    int getCabinCount() const {
        return cabinCount;
    }

    void setCabinCount(int newCabinCount) {
        cabinCount = newCabinCount;
    }

    int getHeight() const {
        return height;
    }

    void setHeight(int newHeight) {
        height = newHeight;
    }

    void start() {
        std::cout << "The Ferris wheel ride has started!\n";
    }

    void stop() {
        std::cout << "The Ferris wheel ride has stopped.\n";
    }

private:
    int cabinCount;
    int height;
};

class AmusementPark {
public:
    AmusementPark() {
        // Дефолтный конструктор
        name = "Unnamed Park";
    }

    AmusementPark(const std::string& name) : name(name) {
        // Недефолтный конструктор через список инициализаторов
    }

    void addEmployee(Employee& employee) {
        employees.push_back(employee);
    }

    void addRide(Ride& ride) {
        rides.push_back(ride);
    }

    void showEmployees() {
        std::cout << "Employees of " << name << ":\n";
        for (const auto& employee : employees) {
            std::cout << "- " << employee.getName() << ", Age: " << employee.getAge() << ", Children: " << employee.getChildren();
            if (employee.getCurrentRide() != nullptr) {
                std::cout << ", Current Ride: " << employee.getCurrentRide()->getName();
            }
            std::cout << "\n";
        }
    }

    void showRides() {
        std::cout << "Rides in " << name << ":\n";
        for (const auto& ride : rides) {
            std::cout << "- " << ride.getName() << ", Speed: " << ride.getSpeed() << "\n";
        }
    }

private:
    std::string name;
    std::vector<Employee> employees;
    std::vector<Ride> rides;
};

int main() {
    AmusementPark park("Fun Park");

    Employee emp1("John", 30, 2);
    Employee emp2("Alice", 25, 0);

    RollerCoaster rc1("Looping Coaster", 100, 3, 50);
    FerrisWheel fw1("Giant Wheel", 40, 20, 30);

    emp1.setCurrentRide(&rc1);
    emp2.setCurrentRide(&fw1);

    park.addEmployee(emp1);
    park.addEmployee(emp2);
    park.addRide(rc1);
    park.addRide(fw1);

    park.showEmployees();
    park.showRides();

    return 0;
}