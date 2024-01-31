#include<bits/stdc++.h>
using namespace std;

void printSpiralAntiClockwise(vector<vector<int>>arr,int row,int col){
        int totalElement = row*col;
        int startRow= 0;
        int startColumn = 0;
        int endRow = row-1;
        int endCol = col-1;
        while(totalElement>0){
            // to print the starting row
            for(int i=endCol;i>=startColumn;i--){
                totalElement--;
                cout<<arr[startRow][i]<<" ";
            }
            // increase the row
            startRow++;
            if(totalElement==0) break;
            
            // to print the last column
            for(int i=startRow;i<=endRow;i++){
                totalElement--;
                cout<<arr[i][startColumn]<<" ";
            }
            // increase the column
            startColumn++;
            if(totalElement==0) break;
            // to print the starting row
            for(int i=startColumn;i<=endCol;i++){
                totalElement--;
                cout<<arr[endRow][i]<<" ";
            }
            // decreasing last row
            endRow--;
            if(totalElement==0) break;
            // printing last row
            for(int i=endRow;i>=startRow;i--){
                totalElement--;
                cout<<arr[i][endCol]<<" ";
            }
            endCol--;
            if(totalElement==0) break;
        }
}

void printSpiralClockwise(vector<vector<int>>arr,int row,int col){
        int totalElement = row*col;
        int startRow= 0;
        int startColumn = 0;
        int endRow = row-1;
        int endCol = col-1;

        while(totalElement>0){
            // to print the starting row
            for(int i=startColumn;i<=endCol;i++){
                totalElement--;
                cout<<arr[startRow][i]<<" ";
            }
            // increase the row
            startRow++;
            if(totalElement==0) break;
            // to print the last column
            for(int i=startRow;i<=endRow;i++){
                totalElement--;
                cout<<arr[i][endCol]<<" ";
            }
            // decrease the column
            endCol--;
            if(totalElement==0) break;
            // to print the last row
            for(int i=endCol;i>=startColumn;i--){
                totalElement--;
                cout<<arr[endRow][i]<<" ";
            }
            // decrease the row
            endRow--;
            if(totalElement==0) break;
            // to print the first column
            for(int i=endRow;i>=startRow;i--){
                totalElement--;
                cout<<arr[i][startColumn]<<" ";
            }
            // increase the column
            startColumn++;
            if(totalElement==0) break;
        }
}


int main(){
    int row,col;
    cout<<"Enter the Row and Column Number: ";
    cin>>row>>col;

    // int arr[row][col];
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
        // cout<<"EntendRow For Row: "<<i+1;
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Clockwise--> ";
    printSpiralClockwise(arr,row,col);
    cout<<"\n";
    cout<<"Anticlockwise--> ";
    printSpiralAntiClockwise(arr,row,col);
    return 0;
}