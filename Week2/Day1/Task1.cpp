#include <iostream>
#include <vector>

using namespace std;

// Forward declarations
class Constituency;
class Vehicle;

class Person {
protected:
    string name;
public:
    Person(const string& name) : name(name) {}
};

class MemberOfParliament : public Person {
protected:
    vector<Vehicle*> vehicles;
    Constituency* constituency;
    int spendingCost;
public:
    MemberOfParliament(const string& name) : Person(name), constituency(nullptr), spendingCost(0) {}

    void setConstituency(Constituency* const constituency) {
        this->constituency = constituency;
    }

    void addVehicle(Vehicle* const vehicle) {
        vehicles.push_back(vehicle);
    }

    void setSpendingCost(const int cost) {
        spendingCost = cost;
    }

    int getSpendingCost() const {
        return spendingCost;
    }

    bool exceedsSpendingLimit() const {
        return spendingCost > 100000; // 1 lakh spending limit for MP
    }

    Constituency* getConstituency() const {
        return constituency;
    }

    virtual bool isMinister() const {
        return false;
    }

    virtual bool isPrimeMinister() const {
        return false;
    }

    virtual bool givePermissionToArrest() const {
        return false;
    }
};

class Minister : public MemberOfParliament {
public:
    Minister(const string& name) : MemberOfParliament(name) {}

    bool exceedsSpendingLimit() {
        return spendingCost > 1000000; // 10 lakhs spending limit for Minister
    }

    bool isMinister() const override {
        return true;
    }
};

class PrimeMinister : public Minister {
public:
    PrimeMinister(const string& name) : Minister(name) {}

    bool exceedsSpendingLimit() {
        return spendingCost > 10000000; // 1 crore spending limit for Prime Minister
    }

    bool givePermissionToArrest()  {
        // Prime Minister can give permission to arrest a Minister if the Minister exceeds spending limit
        return (spendingCost > 1000000); // Only give permission when Minister exceeds spending limit
    }
};

class Commisioner : public Person {
public:
    bool canArrest(MemberOfParliament* const mp) const {
        // Commissioner can arrest any MP if they exceed spending limit
        return mp->exceedsSpendingLimit();
    }
};

class Constituency {
    string name;
public:
    Constituency(const string& name) : name(name) {}

    string getName() const {
        return name;
    }
};

class Vehicle {
    string driverName;
    string type;
public:
    Vehicle(const string& driverName, const string& type) : driverName(driverName), type(type) {}
};

int main() {
    

    return 0;
}
