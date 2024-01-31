#include <bits/stdc++.h>
using namespace std;

// function that find triplet

void findTriplet(vector<int> arr, vector<vector<int>> &ans, int sum)
{
    int n = arr.size();
    sort(arr.begin(),arr.end());

    int left=-1;
    int right=-1;
    vector<int>temp;
    // loop which is used to find the triplet and it takes o(n^2) time.

    for(int i=0;i<n-2;i++){
        temp.push_back(arr[i]);
        left = i+1;
        right = n-1;
        while(left<right){
            if(arr[i]+arr[left]+arr[right]==sum){
                
                // here we push other element which makes sum 

                temp.push_back(arr[left]);
                temp.push_back(arr[right]);
                ans.push_back(temp);
                temp.pop_back();
                temp.pop_back();
                
                left++;
                right--;
            }

            else if(arr[i]+arr[left]+arr[right]<sum){
                // since the value is lower so we need to increae hence left++
                left++;
            }
            else if(arr[i]+arr[left]+arr[right]>sum){
                // value goes higher so we need to reduced the value
                right--;
            }

        }
        // this is important since we also need to find all the triplet
        temp.pop_back();
    }

    if(ans.size()==0) cout<<"No Triplet Exist!";

    else{
        cout << "Triplets Are: ";
        // iterating through the ans 
        for(auto it:ans){
            for(auto i:it){
                cout<<i<<" ";
            }
            cout<<"\n";
        }
    }
}

int main()
{
    int n, sum;
    cout << "Enter the Size Of The Array: ";
    cin >> n;
    cout << "Enter the sum: ";
    cin >> sum;
    vector<int> arr;
    arr.resize(n, 0);

    cout << "Enter the element of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << "Hello";
    vector<vector<int>> ans;
    // for (auto it : arr)
    //     cout << it;
    findTriplet(arr, ans, sum);
    
    return 0;
}