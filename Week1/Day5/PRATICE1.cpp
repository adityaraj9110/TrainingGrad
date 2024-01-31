#include<bits/stdc++.h>
using namespace std;

void printAns(char *str1,char *str2,int m,int n,char *temp,int i){
    if(n==0 and m==0) {
        cout<<temp<<" ";
        return;
    }

    if(m!=0){
        temp[i]=str1[0];
        printAns(str1+1,str2,m-1,n,temp,i+1);
    }
    if(n!=0){
        temp[i]=str2[0];
        printAns(str1,str2+1,m,n-1,temp,i+1);
    }
}

int main(){
    char str1[2]={'A','B'},str2[2]={'C','D'};
    int n = 2;
    int m = 2;
    char temp[n+m];
    printAns(str1,str2,n,m,temp,0);
    return 0;
}