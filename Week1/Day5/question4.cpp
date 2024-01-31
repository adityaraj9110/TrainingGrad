#include <bits/stdc++.h>
using namespace std;

vector<int> findnearGreastestIndexInRight(vector<int> arr, vector<int> &ans, int n)
{
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int currIndex = i;
        int topIndex = st.top();

        while (st.top() != -1 && arr[currIndex] > arr[st.top()])
            st.pop();
        ans.push_back(st.top());
        st.push(currIndex);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> findnearGreastestIndexInLeft(vector<int> arr, vector<int> &ans, int n)
{
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        int currIndex = i;
        int topIndex = st.top();

        while (st.top() != -1 && arr[currIndex] > arr[st.top()])
            st.pop();
        ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}

void printTheMaximumAmountOfWater(vector<int> arr, int n)
{
    // to find the maximum length we initiliase this way
    int maxiLengthLeft = INT_MIN;
    int maxiLength = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        int tower = arr[i];
        int currentIndex = i;
        int tempMin = INT_MAX;
        // to find the index which is greater than current tower
        for (int i = currentIndex; i >= 0; i--)
        {
            if (tower <= arr[i])
                tempMin = min(i, tempMin);
        }
        // calulating the volume
        maxiLengthLeft = max(maxiLengthLeft, tower * (currentIndex - tempMin));
    }

    for(int i=0;i<n;i++){
        int tower = arr[i];
        int currentIndex = i;
        int tempMax = INT_MIN;

        for(int j=currentIndex+1;j<n;j++){
            if(tower<=arr[j]){
                tempMax = max(j,tempMax);
            }
        }
        maxiLength = max(maxiLength, tower * (tempMax - currentIndex));
    }
    
    // cout<<maxiLength<<" ";
    cout << max(maxiLengthLeft, maxiLength);
}

int main()
{
    int n;
    vector<int> arr;
    cout << "Enter the size of array: ";
    cin >> n;

    arr.resize(n, 0);
    cout << "Enter the size of lines(Element): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printTheMaximumAmountOfWater(arr, n);
    return 0;
}