#include<bits/stdc++.h>
using namespace std;

void findnearGreastestElementInRight(vector<int>arr,int n){
    stack<int>st;
    st.push(-1);
    vector<int>ans;
    for(int i=0;i<n;i++){
        int currIndex = i;
        // int topIndex = st.top();

        while(st.top()!=-1 && arr[currIndex]>arr[st.top()] ) st.pop();
        ans.push_back(st.top());
        st.push(currIndex);
        
    }
    // reverse(ans.begin(),ans.end());
    for(auto it:ans) cout<<it<<" ";
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    findnearGreastestElementInRight(arr,n);
    return 0;
}