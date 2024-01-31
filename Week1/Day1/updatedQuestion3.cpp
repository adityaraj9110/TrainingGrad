#include<bits/stdc++.h>
using namespace std;

// Function to check primality
bool isPrime(int n){
    if(n < 2) return false;
    for(int i=2; i*i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

// Function to find the largest number less than N whose each digit is prime
int findLargest(int n){
    while(n > 2){
        n--; // Start from the number just below N

        // Check if each digit of the number is prime
        int temp = n;
        bool allDigitsPrime = true;
        while(temp > 0){
            int digit = temp % 10;
            if(!isPrime(digit)){
                allDigitsPrime = false;
                break;
            }
            temp /= 10;
        }

        if(allDigitsPrime){
            return n;
        }
    }

    return -1; // If no such number is found
}

int main(){
    int n;
    cin >> n;
    cout << findLargest(n) << endl;
    return 0;
}
// tc - o(n)