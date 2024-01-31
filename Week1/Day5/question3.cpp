#include <bits/stdc++.h>
using namespace std;

void printAllMaximumInGivenWindow(vector<int> arr, int n, int k)
{
    // initilasie and declaring the variable

    int left = 0;
    int right = 0;
    int windowSize = k;
    vector<int> ans;
    
    priority_queue<int>pq;
    // starting of loop
    // we use dq and assume that front element of dq is always have our answer when wwe hit the window size
    while (right < n)
    {

        int currentElement = arr[right];
        // checking if the front element of dq has already the element which is maximum or not!
        pq.push(currentElement);

        // if we do not reaches to window size then simply just go on and increase the size of window
        if (right - left + 1 < windowSize)
        {
            right++;
        }
        // if window size hit then we extract the answer

        else if (right - left + 1 == windowSize)
        {
            int currentAns = pq.top();
            ans.push_back(currentAns);
            int eleAtleftIndex = arr[left];
            // checking if the front element is the maximum in window then we need to pop otherwise no need!

            

            left++;
            right++;
        }
    }
    // printing the element
    for (auto element : ans)
        cout << element << " ";
}

int main()
{
    int n;
    vector<int> arr;
    int windowSize;
    cout << "Enter the size of array: ";
    cin >> n;

    arr.resize(n, 0);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the window size: ";
    cin >> windowSize;

    // if(windowSize>n || n%windowSize!=0) cout<<"Oops!! you have enter wroong window size";
    // if(n%windowSize==0 && windowSize>n) cout<<"Oops!! you have enter wroong window size";

    printAllMaximumInGivenWindow(arr, n, windowSize);
    return 0;
}