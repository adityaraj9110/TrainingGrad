#include<bits/stdc++.h>
using namespace std;

// this is dfs algorithm which is a recursive algorith used in graphs to traverse the graph
void dfsAlgorithn(vector<vector<int>>arr,int row,int col,vector<vector<int>>&visitedArray){
    
    // we first marked as visited in visited array for this particular row can column
    visitedArray[row][col]=1;
    // these two array is so that we can save time and iteration . Without this we have to make 4 loops and traverse one by one 
    int dr[4]={-1,0,+1,0};
    int dc[4]={0,+1,0,-1};
    int originalRow = arr.size();
    int originalColumn = arr[0].size();

    for(int i=0;i<4;i++){
        int newRow = row+dr[i];
        int newCol = col+dc[i];
        // here we are cheecking complete thing that is boundary constraints and the upcoming element is 1 and also the next row and col is not visited
        if(newRow>=0 && newRow<originalRow && newCol>=0 && newCol<originalColumn && arr[newRow][newCol]==1 && !visitedArray[newRow][newCol]){
            // here for every valid candidate we call dfs algorithm
            dfsAlgorithn(arr,newRow,newCol,visitedArray);
        }
    }
}

int countTheIsland(vector<vector<int>>arr,int row,int col){
    int countIsland = 0;
    // this array is created to mark visited to the entire element
    vector<vector<int>>visitedArray(row,vector<int>(col,0));
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int currentElement = arr[i][j];
            if(!visitedArray[i][j] && currentElement==1){
                dfsAlgorithn(arr,i,j,visitedArray);
                // here if dfs algo return it wopuld mean that for that particular element we have explore all the its adjacent ones.
                countIsland++;
            }
        }
    }
    return countIsland;

    
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

    cout<<"Numbers of islands are: "<<countTheIsland(arr,row,col);

    return 0;
}