#include<bits/stdc++.h>
using namespace std;

// to generate combination
void generateCombinations(unordered_map<string, vector<char>>& mapping, string& input, string currentCombination, vector<string>& result) {
    // since input has empty so we get the output
    if (input.empty()) {
        result.push_back(currentCombination);
        return;
    }
    
    string currentDigit = input.substr(0, 1);
    string restOfInput = input.substr(1);
    // finding if the digit is in map or not

    if (mapping.find(currentDigit) != mapping.end()) {
        for (char letter : mapping[currentDigit]) {
            generateCombinations(mapping, restOfInput, currentCombination + letter, result);
        }
    } 
    // else {
    //     // if digit does not in the map then go to next in fucntion
    //     generateCombinations(mapping, restOfInput, currentCombination + currentDigit, result);
    // }
    // if input has length 2
    if (input.length() >= 2) {
        string twoDigit = input.substr(0, 2);
        restOfInput = input.substr(2);

        if (mapping.find(twoDigit) != mapping.end()) {
            for (char letter : mapping[twoDigit]) {
                generateCombinations(mapping, restOfInput, currentCombination + letter, result);
            }
        }
    }
}

int main() {
    unordered_map<string, vector<char>> valuesMapping = {
        {"1", {'Z', 'Y', 'A'}},
        {"2", {'B', 'O'}},
        {"12", {'L'}},
        {"3", {'U', 'P'}}
    };

    string input;
    cout<<"Enter the input: ";
    cin>>input;
    vector<string> output;
    string currentCombination = "";
    generateCombinations(valuesMapping, input, currentCombination, output);

    // Print the result
    cout<<"Here are the possible combinations: ";
    for (string& combination : output) {
        cout << combination << " ";
    }

    return 0;
}
