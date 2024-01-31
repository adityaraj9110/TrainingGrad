#include<bits/stdc++.h>
using namespace std;




int swapLastDigit(int n){
    int temp = n,cntDigit=0;
    

    while(temp>0){
        cntDigit++;
        temp/=10;
    }
    cntDigit--;
    temp = n;
    // first we find the last digit 

    int lastDigit = temp%10;
    temp = n;
    // find first digit
    // check first digit is 0 or not

    // checkFirstDigitZero = ;



    int firstDigit = (int) n/pow(10,cntDigit);


    // now we need to swap

    int swappingNumber = 0;
    swappingNumber = lastDigit;
    swappingNumber*=pow(10,cntDigit);
    swappingNumber+=(n%(int)pow(10,cntDigit));
    
    // inorder to get the first digit on the last position we need to delete the last digit from swappingnumber since it contain the all the the number except first one
    swappingNumber-=lastDigit;
    swappingNumber+=firstDigit;

    // return it

    return swappingNumber;

    
    
}

int main(){
    int n;
    cin>>n;
    cout<<swapLastDigit(n);
    return 0;
}

// TC - o(1) and o(n) is required in order to count the digit
// SC - o(1)