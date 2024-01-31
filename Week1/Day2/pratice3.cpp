#include <bits/stdc++.h>
using namespace std;

void printPattern(int n)
{
    
    // this first for loop is use to handle the upper hallf of pattern

    for(int i=1;i<=n/2;i++){
        for(int j=1;j<=n;j++){
            if(i==j) cout<<"\\";
            else if(j==(n-i+1)) cout<<"/";
            else {
                cout<<"*";
            }
        }
        cout<<"\n";
    }

    // this for loop is used to handle the mid case separately

    for (int i = n / 2; i <= n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << "/";
            else{
                cout << "*";
            }
        }
        cout << "\n";
    }
    
    // this is used here to print the lower half of the pattern

    for (int i = n / 2 + 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << "\\";
            else if (j == (n - i - 1))
                cout << "/";
            else{
                cout << "*";
            }
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    printPattern(n);
    return 0;
}