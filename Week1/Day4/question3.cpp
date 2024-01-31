#include<bits/stdc++.h>
using namespace std;

bool searchElementinMatrix(vector<vector<int>>arr,int row,int col,int target){
    
    // this is temprorary row and column
    int tempRow = 0;
    int tempColumn = col-1;
    // thses condition in the while insures that the pointers in the matrix restricted
    while(tempRow>=0 && tempRow<row && tempColumn>=0 && tempColumn<col){
        int currentElement = arr[tempRow][tempColumn];
        // if current element is greater then it is sure that it can't be in other row because it is sorted that's why tempColumn--
        if(currentElement>target){
            tempColumn--;
        }
        // if current element is smaleer then it is sure that it can't be in other row because it is sorted that's why tempRow++
        else if(currentElement<target){
            tempRow++;
        }
        else if(currentElement==target) return true;
        
    }
    // since there if in while loop we can't find the element then we just return false
    return false;

}

int main(){
    int row,col;
    cout<<"Enter the Row and Column Number: ";
    cin>>row>>col;

    vector<vector<int>>arr(row,vector<int>(col,0));

    cout<<"Now you need to enter elements in such a way that it is Row and column wise sorted (*As Per Question Condition)\n";
    for(int i=0;i<row;i++){
        cout<<"Enter Element For Row: "<<i+1;
        cout<<"-> ";
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    int target;
    cout<<"Enter the element you want to search: ";
    cin>>target;
    
    cout<<"Your input array: "<<"\n";
    for(int i=0;i<row;i++){
        // cout<<"EntendRow For Row: "<<i+1;
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    if(searchElementinMatrix(arr,row,col,target)) cout<<"True";
    else cout<<"False";
    return 0;
}