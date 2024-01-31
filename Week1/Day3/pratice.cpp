#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ind=0;
    for (int i = 0; i < 8; i++)
    {
        cout<<ind++;
        if (i == 6)
            continue;
        if (i == 2)
            continue;
        else
        {
            cout << "Hello";
        }
    }
    return 0;
}