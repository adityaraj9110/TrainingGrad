#include <bits/stdc++.h>
using namespace std;

void modifyArray(vector<int>arr, int n)
{

    // sort(arr, arr + n);
    // int ind = 0;
    // int newArray[n];
    // for (int i = 0; i < n; i++)
    // {
    //     newArray[ind++] = arr[i];
    //     while (arr[i] == arr[i + 1])
    //         i++;
    // }
    // cout << "\n";
    // cout << "Modified Array: ";
    // for (int i = 0; i < ind; i++)
    // {
    //     cout << newArray[i] << " ";
    // }
    // cout << "\nSize of the array becomes: " << ind;
    
    // this vector is used to count the occurence of element just ike map

    vector<int>countOccurence;
    countOccurence.resize(1000,0);
    
    // we are store the count of element which are repeated
    for(auto it:arr){
        countOccurence[it]++;
    }
     
    // this is temprorary array which we have used to maintain the order of array
    vector<int>temp;
    
    
    // traverse from last to ensure the proper order of array
    for(int i=arr.size()-1;i>=0;i--){
        // if occurence is 1 that would mean that the element has single occurence
        if(countOccurence[arr[i]]==1){
            temp.push_back(arr[i]);
        }

        // if we get some element which has occurence more that once then we need to decrease the count of that element
        else if(countOccurence[arr[i]]>1){
            countOccurence[arr[i]]--;
        }
    }
    
    // here we have reverse the temp as it store the element but in the reverse order
    reverse(temp.begin(),temp.end());
    cout<<"After Modification: ";
    for(auto it:temp) cout<<it<<" ";

    
    




}
// 2 4 6 2 8 10 4 12 14 6
int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int>arr;
    arr.resize(n,0);
    cout << "Now Enter The Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Before Modification: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<"\n";
    modifyArray(arr, n);

    return 0;
}