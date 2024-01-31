#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int findSmallest(int n){
    long long ans = 1;
    for(int i=1;i<=n;i++){
        ans = (ans*i)/gcd(ans,i);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<findSmallest(n);
    return 0;
}

// TC -> o(n)
// SC ->o(n)