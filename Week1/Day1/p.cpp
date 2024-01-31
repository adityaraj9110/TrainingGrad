#include<bits/stdc++.h>
using namespace std;

bool checkFirstDigitZero(int n){
    while(n>=0){
        int rem = n%10;
        if(n==0 && rem==0 ){
            return true;
        }
        n/=10;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    cout<<checkFirstDigitZero(n);
    return 0;
}