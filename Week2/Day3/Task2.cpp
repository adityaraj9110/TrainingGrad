#include<bits/stdc++.h>
using namespace std;
class ATM {
private:
    vector<int> denominations;
    vector<int> notesCount;

public:
    // Constructor to initialize ATM with denominations and notes count
    ATM(vector<int> denomimations, vector<int> counts) {
        denominations = denomimations;
        notesCount = counts;
    }

    // Function to top-up ATM with specific denomination and count
    void topUp(int denomimation, int count) {
        // finding the dominationPosition
        auto dinominationPosition = find(denominations.begin(), denominations.end(), denomimation);
        if (dinominationPosition != denominations.end()) {
            int index = dinominationPosition - denominations.begin();
            notesCount[index] += count;
        } else {
            // if domination not found then add the domination
            denominations.push_back(denomimation);
            notesCount.push_back(count);
        }
    }

    // Function to withdraw cash
    void withdraw(int amount) {
        vector<int> result;
        for (int i = denominations.size() - 1; i >= 0; i--) {
            int denomination = denominations[i];
            // count is calculated 
            int count = min(amount / denomination, notesCount[i]);
            // subtract the amount
            amount -= count * denomination;

            // this  insert funtion insert the denomination in the from the end and count represents that how many copies of denomination be inserted
            // like if amount is 4700 then 2000 note should be 2 times inserted 
            result.insert(result.end(), count, denomination);
        }
        if (amount != 0) {
            cout << "Insufficient balance or invalid denomination\n";
        } else {
            cout << "Amount dispensed: ";
            for (int note : result) {
                cout << note << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    // Initialize ATM with initial denominations and notes count
    vector<int> denominations = {100, 200, 500, 2000};
    vector<int> notesCount = {10, 5, 3, 2};
    ATM atm(denominations, notesCount);

    // Top-up ATM with additional denominations and counts
    atm.topUp(2000, 20);
    atm.topUp(500, 2);

    // Withdraw cash
    atm.withdraw(2300);  // Expected output: 2000 200 100
    atm.withdraw(4100);  // Expected output: 2000 2000 2000 100

    return 0;
}
