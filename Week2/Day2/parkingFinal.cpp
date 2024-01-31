#include<bits/stdc++.h>

using namespace std;

// Enum for PaymentType
enum class PaymentType {
    CASH,
    CREDIT_CARD,
};

// Enum for ParkingSpaceType
enum class ParkingSpaceType {
    BIKE_PARKING,
    CAR_PARKING,
    TRUCK_PARKING,
    HANDICAP
};

// Enum for VehicleType
enum class VehicleType {
    BIKE,
    CAR,
    TRUCK,
    WHEELCHAIR
};

// Enum for ParkingTicketStatus
enum class ParkingTicketStatus {
    PAID,
    ACTIVE
};

// Enum for PaymentStatus
enum class PaymentStatus {
    UNPAID,
    PENDING,
    COMPLETED,
};

// Forward declaration to avoid any conflict
class ParkingLot;
class Account;
class Account {

	string name;
	string email;
	string password;
	string empId;
	Address address;

};
// Class Address
class Address {
public:
    string country;
    string state;
    string city;
};

// Class PaymentInfo
class PaymentInfo {
public:
    double amount;
    time_t paymentDate;
    int transactionId;
    ParkingTicket *parkingTicket;
    PaymentStatus paymentStatus;
};

// Class Payment
class Payment {
public:
    // construcctor to make payments
    PaymentInfo makePayment(ParkingTicket *parkingTicket, PaymentType paymentType){};
};

// Class Vehicle
class Vehicle {
public:
    string licenseNumber;
    VehicleType vehicleType;
    ParkingTicket *parkingTicket;
    PaymentInfo *paymentInfo;
};

// Class ParkingTicket
class ParkingTicket {
public:
    int ticketId;
    int levelId;
    int spaceId;
    // these two are the time_t type variable used to store the time in second
    time_t vehicleEntryDateTime;
    time_t vehicleExitDateTime;
    ParkingSpaceType parkingSpaceType;
    double totalCost;
    ParkingTicketStatus parkingTicketStatus;
    // these are the funtion which is used to update the total cost and exit time of vehicle
    void updateTotalCost(){};
    void updateVehicleExitTime(time_t vehicleExitDateTime){
        this->vehicleExitDateTime = vehicleExitDateTime;

    };
};

// Class PaymentService
class PaymentService {
public:
    PaymentInfo makePayment(ParkingTicket *parkingTicket, PaymentType paymentType){
        PaymentInfo paymentInfo;
        paymentInfo.amount = parkingTicket->totalCost; // the payment amount is the total cost
        paymentInfo.paymentDate = time(nullptr); // payment date is current date/time
        paymentInfo.transactionId = generateTransactionId(); 
        paymentInfo.parkingTicket = parkingTicket;
        paymentInfo.paymentStatus = PaymentStatus::COMPLETED; // payment is completed
        return paymentInfo;
    };
    private:
        int generateTransactionId() {
        // Generate a unique transaction ID
            static int transactionId = 0;
            return ++transactionId;
    }
};

// Class ParkingDisplayBoard
class ParkingDisplayBoard {
public:
    map<ParkingSpaceType, int> freeSpotsAvailableMap;

    void updateFreeSpotsAvailable(ParkingSpaceType parkingSpaceType, int spaces){};
};

// Class ParkingSpace
class ParkingSpace {
public:
    int spaceId;
    bool isFree;
    double costPerHour;
    Vehicle *vehicle;
    ParkingSpaceType parkingSpaceType;
};

// Class Gate
class Gate {
public:
    int gateId;
    ParkingAttendant *parkingAttendant;
};

// Class Entrance
class Entrance : public Gate {

public:
    ParkingTicket *getParkingTicket(Vehicle *vehicle){
        ParkingTicket *parkingTicket = new ParkingTicket();
        parkingTicket->ticketId = generateTicketId(); // Function to generate ticket ID
        parkingTicket->vehicleEntryDateTime = time(nullptr); // Set entry time to current time

        return parkingTicket;
    };
private:
    int generateTicketId() {
        // Generate a unique transaction ID
            static int transactionId = 0;
            return ++transactionId;
    }
};

// Class Exit
class Exit : public Gate {
public:
    ParkingTicket *payForParking(ParkingTicket *parkingTicket, PaymentType paymentType){
        Payment payment;
        PaymentInfo paymentInfo = payment.makePayment(parkingTicket, paymentType);
        // Update parking ticket status and other relevant details
        parkingTicket->parkingTicketStatus = ParkingTicketStatus::PAID;
        parkingTicket->updateTotalCost();
        parkingTicket->updateVehicleExitTime(time(nullptr)); // Assuming current time
        return parkingTicket;
    };
};

// Class ParkingFloor
class ParkingFloor {
public:
    int levelId;
    vector<ParkingSpace *> parkingSpaces;
    ParkingDisplayBoard parkingDisplayBoard;
};

// Class ParkingAttendant
class ParkingAttendant : public Account {
public:
    PaymentService *paymentService;
    // this funtion is used to process the entry of vehicle
    bool processVehicleEntry(Vehicle *vehicle){};
    PaymentInfo *processPayment(ParkingTicket *parkingTicket, PaymentType paymentType){
         PaymentService paymentService;
        return &paymentService.makePayment(parkingTicket, paymentType);
    };
};

// Class Admin
class Admin : public Account {
public:
    bool addParkingFloor(ParkingLot *parkingLot, ParkingFloor *floor) {
        // adding a parking floor to the parking lot
        if (parkingLot != nullptr && floor != nullptr) {
            parkingLot->parkingFloors.push_back(floor);
            return true;
        }
        return false;
    }

    bool addParkingSpace(ParkingFloor *floor, ParkingSpace *parkingSpace) {
        // adding a parking space to a parking floor
        if (floor != nullptr && parkingSpace != nullptr) {
            floor->parkingSpaces.push_back(parkingSpace);
            return true;
        }
        return false;
    }

    bool addParkingDisplayBoard(ParkingFloor *floor, ParkingDisplayBoard *parkingDisplayBoard) {
        // adding a parking display board to a parking floor
        if (floor != nullptr && parkingDisplayBoard != nullptr) {
            floor->parkingDisplayBoard = *parkingDisplayBoard;
            return true;
        }
        return false;
    }
};

// Class ParkingLot
class ParkingLot {
    public:
    // since pakring lot has multiple floors
    vector<ParkingFloor *> parkingFloors;
    vector<Entrance *> entrances;
    vector<Exit *> exits;

    Address address;
    string parkingLotName;

    bool isParkingSpaceAvailableForVehicle(Vehicle *vehicle){};
    bool updateParkingAttendant(ParkingAttendant *parkingAttendant, int gateId){};
};

int main() {
    return 0;
}
