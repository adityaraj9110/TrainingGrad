#include<bits/stdc++.h>
using namespace std;

int  findMedian(vector<int>firstArray,vector<int>secondArray,int size1,int size2){
    // to minimize the time complexity we are applying binary search on shorted array
    if(size1>size2)  return findMedian(secondArray,firstArray,size2,size1);
    
    // binary search
    int start = 0;
    int end = size1;
    while(start<=end){
        // forming symmetry
        int cut1 = (start+end)/2;
        int cut2 = (size1+size2+1)/2-cut1;
        // defing the left and right for both the array
        int left1 = cut1==0 ? INT_MIN : firstArray[cut1-1];
        int left2 = cut2==0 ? INT_MIN : secondArray[cut2-1];

        int right1 = cut1==size1?INT_MAX : firstArray[cut1];
        int right2 = cut2==size2?INT_MAX : secondArray[cut2];
        
        // simple binary search thing which is being used here
        if(left1<=right2 && left2<=right1) {
            if((size1+size2)%2==0){
                return (max(left1,left2)+min(right1,right2))/2;
            }
            else{
                return max(left1,left2);
            }
        }
        else if(left1>left2) end = cut1-1;
        else{
            start = cut1+1;
        }
        

    }
    return 0;
}

int main(){
    int size1,size2;
    cout<<"Enter the size of both Arrays: ";
    cin>>size1>>size2;

    vector<int>firstArray,secondArray;
    firstArray.resize(size1,0);
    secondArray.resize(size2,0);
    cout<<"Enter the element for first array in sorted order: ";
    for(int i=0;i<size1;i++){
        cin>>firstArray[i];
    }
    cout<<"Enter element for second array in sorted order: ";
    for(int i=0;i<size2;i++){
        cin>>secondArray[i];
    }


    cout<< findMedian(firstArray,secondArray,size1,size2);
    return 0;
}