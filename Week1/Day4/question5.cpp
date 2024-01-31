#include<bits/stdc++.h>
using namespace std;


void rotateBy90degree(vector<vector<int>>&arr,int row,int col){
    // first we swap the column
    for(int i=0;i<col;i++){
        int start = 0;
        int end = row-1;
        while(start<=end){
            swap(arr[start][i],arr[end][i]);
            start++;
            end--;
        }
    }
    // then we swap the ith,jth element with jth,ith element and at the same time we also increase the col
    int tempCol = 0;
    for(int i=0;i<row;i++){
        for(int j=tempCol;j<col;j++){
            swap(arr[i][j],arr[j][i]);
        }
        tempCol++;
        
    }
}

int main(){
    int row,col;
    cout<<"Enter the Row and Column Number: ";
    cin>>row>>col;
    vector<vector<int>>arr(row,vector<int>(col,0));
    
    for(int i=0;i<row;i++){
        cout<<"Enter Element For Row: "<<i+1;
        cout<<"-> ";
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Your input array: "<<"\n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    rotateBy90degree(arr,row,col);
    cout<<"Your output array: "<<"\n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}