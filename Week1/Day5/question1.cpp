#include <bits/stdc++.h>
using namespace std;

// void printTheAns(string input1, int ind1, int size1, string input2, int ind2, int size2, string temp)
// {

//     if (ind1 == size1 - 1 and ind2 == size2 - 1)
//     {
//         cout << temp;
//         return;
//     }
//     cout<<ind1<<" "<<ind2<<"\n";
//     if (ind1 < size1)
//     {
//         temp += input1[ind1];
//         // cout << temp;
//         printTheAns(input1, ind1 + 1, size1, input2, ind2, size2, temp);
//     }

//     if (ind2 < size2)
//     {
//         temp += input2[ind2];
//         // cout << temp;
//         printTheAns(input1, ind1, size1, input2, ind2 + 1, size2, temp);
//     }
// }

// void printAllInterleaving(string input1, string input2)
// {
//     string temp = "";
//     int size1 = input1.size();
//     int size2 = input2.size();
//     printTheAns(input1, 0, size1, input2, 0, size2, temp);
// }

// int main()
// {
//     string input1, input2;
//     cout << "Enter the string1: ";
//     cin >> input1;
//     cout << "Enter the string2: ";
//     cin >> input2;

//     printAllInterleaving(input1, input2);
//     return 0;
// }

// this is the funtion which is used here to find all interleaving

void printAns(char *input1, char *input2, int size1, int size2, char *temproraryArray, int index)
{
    // if both array exhausted then simply print the temp array
    if (size1 == 0 and size2 == 0)
    {
        for (int i = 0; i < index; i++)
        {
            cout << temproraryArray[i];
        }
        cout << " ";
        return;
    }
    // if first array is stil left then go for first array only
    if (size1 != 0)
    {
        temproraryArray[index] = input1[0];
        // recursive call
        printAns(input1 + 1, input2, size1 - 1, size2, temproraryArray, index + 1);
    }
    // if second array is stil left then go for first array only
    if (size2 != 0)
    {
        temproraryArray[index] = input2[0];
        // recursive call
        printAns(input1, input2 + 1, size1, size2 - 1, temproraryArray, index + 1);
    }
}

int main()
{
    int size1, size2;
    cout << "Enter the size of both string one by one: ";
    cin >> size1 >> size2;

    char input1[size1], input2[size2];
    cout << "Enter the character for first string : ";
    for (int i = 0; i < size1; i++)
    {
        cin >> input1[i];
    }
    cout << "Enter the character for second string : ";
    for (int i = 0; i < size2; i++)
    {
        cin >> input2[i];
    }
    // cout << size1 << size2;
    char temproraryArray[size1 + size2];

    printAns(input1, input2, size1, size2, temproraryArray, 0);
}