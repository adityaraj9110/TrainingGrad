#include <bits/stdc++.h>

using namespace std;

// Enum for PaymentType
enum class PaymentType
{
    CASH,
    CREDIT_CARD,
};

// Enum for ParkingLotType
enum class ParkingLotType
{
    BIKE_PARKING,
    CAR_PARKING,
    TRUCK_PARKING,
    HANDICAP
};

// Enum for VehicleType
enum class VehicleType
{
    BIKE,
    CAR,
    TRUCK,
    WHEELCHAIR
};

// Enum for TicketStatus
enum class ParkingTicketStatus
{
    PAID,
    ACTIVE
};

// Enum for PaymentStatus
enum class PaymentStatus
{
    UNPAID,
    PENDING,
    COMPLETED,
};

// Forward declaration to avoid any errors
class ParkingLot;
class Account;
class ParkingTicket;
class PaymentMode;
class Account
{

    string name;
    string password;
    string empId;
};
// Class Address
class Address
{
public:
    string country;
    string state;
    string city;
};

// Class PaymentInfo
class PaymentInfo
{
public:
    int amount;
    time_t paymentDate;
    int transactionId;
    ParkingTicket *parkingTicket;
    PaymentStatus paymentStatus;
};

// Class Payment
class Payment
{
public:
    // construcctor to make payments
    PaymentInfo makePayment(ParkingTicket *parkingTicket, PaymentType paymentType)
    {
        PaymentMode paymentMode;
        PaymentInfo paymentInfo = paymentMode.makePayment(parkingTicket, paymentType);
        parkingTicket->parkingTicketStatus = ParkingTicketStatus::PAID;
        parkingTicket->updateTotalCost();
        return paymentInfo;
    };
};

// Class Vehicle
class Vehicle
{
public:
    string licenseNumber;
    VehicleType vehicleType;
    ParkingTicket *parkingTicket;
    PaymentInfo *paymentInfo;
};

// Class ParkingTicket
class ParkingTicket
{
public:
    int ticketId;
    int floorId;
    int spaceId;
    // these two are the time_t type variable used to store the time in second
    time_t vehicleEntryDateTime;
    time_t vehicleExitDateTime;
    ParkingLotType ParkingLotType;
    double totalCost;
    ParkingTicketStatus parkingTicketStatus;
    // these are the funtion which is used to update the total cost and exit time of vehicle
    void updateTotalCost()
    {
        // we convert the seconds in hours by diving 3600 and perhour price is 4 so multiply with 4
        totalCost = (difftime(vehicleExitDateTime, vehicleEntryDateTime) / 3600) * 4;
    };
    void updateVehicleExitTime(time_t vehicleExitDateTime)
    {
        this->vehicleExitDateTime = vehicleExitDateTime;
    };
};

// Class PaymentMode
class PaymentMode
{
public:
    PaymentInfo makePayment(ParkingTicket *parkingTicket, PaymentType paymentType)
    {
        PaymentInfo paymentInfo;
        paymentInfo.amount = parkingTicket->totalCost; // the payment amount is the total cost
        paymentInfo.paymentDate = time(nullptr);       // payment date is current date/time
        paymentInfo.transactionId = generateTransactionId();
        paymentInfo.parkingTicket = parkingTicket;
        paymentInfo.paymentStatus = PaymentStatus::COMPLETED; // payment is completed
        return paymentInfo;
    };

private:
    int generateTransactionId()
    {
        // Generate a unique transaction ID
        static int transactionId = 0;
        return transactionId++;
    }
};

// Class ParkingDisplayBoard
class DisplayBoard
{
public:
    unordered_map<ParkingLotType, int> freeSpots;

    void updateFreeSpotsAvailable(ParkingLotType ParkingLotType, int spaces)
    {
        // if free spots available store it in map with its type
        freeSpots[ParkingLotType] += spaces;
    };
};

// Class ParkingLot
class ParkingLot
{
public:
    int spaceId;
    bool isFree;
    int rate;
    Vehicle *vehicle;
    ParkingLotType parkingLotType;
};

// Class Gate
class Gate
{
public:
    int gateId;
    // since each gate has parking attendants
    ParkingAttendant *parkingAttendant;
};

// Class Entrance
class Entrance : public Gate
{

public:
    ParkingTicket *getParkingTicket(Vehicle *vehicle)
    {
        ParkingTicket *parkingTicket = new ParkingTicket();
        parkingTicket->ticketId = generateTicketId();        // Function to generate ticket ID
        parkingTicket->vehicleEntryDateTime = time(nullptr); // Set entry time to current time

        return parkingTicket;
    };

private:
    int generateTicketId()
    {
        // Generate a unique transaction ID
        static int transactionId = 0;
        return transactionId++;
    }
};

// Class Exit
class Exit : public Gate
{
public:
    ParkingTicket *payForParking(ParkingTicket *parkingTicket, PaymentType paymentType)
    {
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
class ParkingFloor
{
public:
    int floorId;
    vector<ParkingLot *> ParkingLots;
    DisplayBoard displayBoard;
};

// Class ParkingAttendant
class ParkingAttendant : public Account
{
public:
    PaymentMode *paymentMode;
    // this funtion is used to process the entry of vehicle
    bool processVehicleEntry(Vehicle *vehicle){

    };
    PaymentInfo *processPayment(ParkingTicket *parkingTicket, PaymentType paymentType)
    {
        PaymentMode paymentMode;
        return &paymentMode.makePayment(parkingTicket, paymentType);
    };
};

// Class Admin
class Admin : public Account
{
public:
    bool addParkingFloor(ParkingLot *parkingLot, ParkingFloor *floor)
    {
        // adding a parking floor to the parking lot
        if (parkingLot != nullptr && floor != nullptr)
        {
            parkingLot->parkingFloors.push_back(floor);
            return true;
        }
        return false;
    }

    bool addParkingLot(ParkingFloor *floor, ParkingLot *ParkingLot)
    {
        // adding a parking space to a parking floor
        if (floor != nullptr && ParkingLot != nullptr)
        {
            floor->ParkingLots.push_back(ParkingLot);
            return true;
        }
        return false;
    }

    bool addParkingDisplayBoard(ParkingFloor *floor, DisplayBoard *displayBoard)
    {
        // adding a parking display board to a parking floor
        if (floor != nullptr && displayBoard != nullptr)
        {
            floor->DisplayBoard = *displayBoard;
            return true;
        }
        return false;
    }
};

// Class ParkingLot
class ParkingLot
{
public:
    // since pakring lot has multiple floors
    vector<ParkingFloor *> parkingFloors;
    vector<Entrance *> entrances;
    vector<Exit *> exits;

    Address address;
    string parkingLotName;

    bool isParkingLotAvailableForVehicle(Vehicle *vehicle)
    {
        for (auto floor : parkingFloors)
        {
            for (auto ParkingLot : floor->ParkingLots)
            {
                if (ParkingLot->isFree)
                {
                    return true; // Parking space available
                }
            }
        }
        return false; // No parking space available
    };
    bool updateParkingAttendant(ParkingAttendant *parkingAttendant, int gateId)
    {
        for (auto entrance : entrances)
        {
            if (entrance->gateId == gateId)
            {
                entrance->parkingAttendant = parkingAttendant;
                return true; // Attendant updated successfully
            }
        }
        for (auto exit : exits)
        {
            if (exit->gateId == gateId)
            {
                exit->parkingAttendant = parkingAttendant;
                return true; // Attendant updated successfully
            }
        }
        return false; // Gate ID not found
    };
};

int main()
{
    return 0;
}
