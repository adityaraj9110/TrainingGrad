#include<bits/stdc++.h>
using namespace std;


// it ony checks column

bool checkForColumn(char sudoku[][9],int col){
    // it is used here to account the frequency of number and also ensures o(1) time
    unordered_map<char,int>countOccurenceOfNumber;
    for(int i=0;i<9;i++){
        char ch = sudoku[i][col];
        if(ch!='.'){
            countOccurenceOfNumber[ch]++;
            if(countOccurenceOfNumber[ch]>1) return false;
        }
    }
    return true;




}
// it only checks row

bool checkForRow(char sudoku[][9],int row){
    // it is used here to account the frequency of number and also esures o(1) time
    unordered_map<char,int>countOccurenceOfNumber;
    for(int i=0;i<9;i++){
        char ch = sudoku[row][i];
        if(ch!='.'){
            countOccurenceOfNumber[ch]++;
            if(countOccurenceOfNumber[ch]>1) return false;
        }
    }
    return true;
    // return true;
}
// this is for mini sudoku i.e, 3x3 matrix
bool checkForMiniSudoku(char sudoku[][9],int row,int col){
    // unordered_set<char>st;
    unordered_map<char,int>countOccurenceOfNumberInMiniMatrix;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            char ch = sudoku[i+row][j+col];
            if(ch!='.'){
                countOccurenceOfNumberInMiniMatrix[ch]++;
                if(countOccurenceOfNumberInMiniMatrix[ch]>1) return false;
            }
        }
    }
    return true;
}

// here is the isValid funtion which check all the conditions which are given in the question !

bool isValid(char sudoku[][9],int row,int col){
    // return true when the three conditions met
    // for the last case we have to find the starting row and col of mini matrix
    return checkForRow(sudoku,row) && checkForColumn(sudoku,col) && checkForMiniSudoku(sudoku,row-(row%3),col-(col%3)) ;
}

bool checkSudoku(char sudoku[][9],int size){
    // this is to traverse through all the element of sudoku

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            // this isValid funtion is here to check the at each ith and jth row and col the entire row and col and also the 3x3 there is no repetition
            if(!isValid(sudoku,i,j)) return false;
        }
    }
    return true;
}

int main(){
    char sudoku[9][9]=
    {
         {'5','3','.','.','.','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','2','.','.','.','.','6','.'}
        ,{'8','.','.','.','.','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'6','.','.','.','8','.','.','7','9'}
    }
    // {
        
    //     {'8','3','.','.','7','.','.','.','.'}
    //     ,{'6','.','.','1','9','5','.','.','.'}
    //     ,{'.','9','8','.','.','.','.','6','.'}
    //     ,{'8','.','.','.','6','.','.','.','3'}
    //     ,{'4','.','.','8','.','3','.','.','1'}
    //     ,{'7','.','.','.','2','.','.','.','6'}
    //     ,{'.','6','.','.','.','.','2','8','.'}
    //     ,{'.','.','.','4','1','9','.','.','5'}
    //     ,{'.','.','.','.','8','.','.','7','9'}
    
    // }

    ;

    if(checkSudoku(sudoku,9)) cout<<"TRUE";
    else cout<<"FALSE";

    return 0;
}
// TC - O(n^3)