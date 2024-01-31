#include<bits/stdc++.h>
using namespace std;
const char KING = 'k';
const char BLANK = '.';
const char ELEPHANT = 'e';
const char CAMEL = 'c';
const char HORSE = 'h';
const char QUEEN = 'q';



bool checkForHorse(char chess[][8],int row,int col){
    // since upon close obervation of horse movement we can save time and iteration by using of hashing
    int dr[4]={-2,-2,+2,+2};
    int dc[4]={-1,+1,+1,-1};
    // like for horse since it can move only in 4 direction that's why loop is set to traverse only 4 time

    for(int i=0;i<4;i++){
        // since if add starting position of horse with the hased value we get his next position
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        if(newRow>=0 && newRow<8 && newCol>=0 && newCol<8 && chess[newRow][newCol]==KING){
            return false;
        }
    }
    return true;

}

bool checkForCamel(char chess[][8],int row,int col){
    // upper right diagonal
    
    
    int i = row;
    int j = col;
    while(i>=0 && j<8){
        char ch = chess[i][j];
        if(ch==KING) return false;
        i--;
        j++;
    }

    i=  row;
    j = col;

    // upper left diagonal

    

    while(i>=0 && j>=0){
        char ch = chess[i][j];
        if(ch==KING) return false;
        i--;
        j--;
    }
    
    i=row;
    j=col;
    // lower right diagonal

    
    while(i<8 && j<8){
        char ch = chess[i][j];
        if(ch==KING) return false;
        i++;
        j++;
    }
    // lower left diagonal
    i=row;
    j=col;
    

    while(i<8&& j>=0){
        char ch = chess[i][j];
        if(ch==KING) return false;
        i++;
        j--;
    }

    // if none of above loop gives false then we can simply return true

    return true;

}

bool checkForElephant(char chess[][8],int row,int col){
    

    // these two map are used to take the account of all entitites's count

    unordered_map<char,int>rowWiseCount;
    unordered_map<char,int>colWiseCount;

    // for row
    
    // saved the count of the entities
    for(int i=0;i<8;i++){
        char ch = chess[row][i];
        if(ch!=BLANK)rowWiseCount[ch] = i;
    }

    
    // traversing in row
    for(int i=0;i<8;i++){
        char ch = chess[row][i];
        
        if(ch=='k'){

            int indexOfKing = rowWiseCount['k'];
            int indexOfElephant = rowWiseCount['e'];
            // these two if contidittion are here to check if elephant is in left or right side of king
            if(indexOfElephant<indexOfKing){
                for(int j = indexOfElephant+1;j<=indexOfKing-1;j++){
                    char tempCh = chess[row][j];
                    if(tempCh!=BLANK){
                        return true;
                    }
                }
            }

            else if(indexOfElephant>indexOfKing){
                for(int j = indexOfKing+1;j<=indexOfElephant-1;j++){
                    char tempCh = chess[row][j];
                    if(tempCh!=BLANK){
                        return true;
                    }
                }
            }
            

            return false;


        }
    }

    // for column
    // taking an account of count of the entities
    for(int i=0;i<8;i++){
        char ch = chess[i][col];
        if(ch!=BLANK) colWiseCount[ch] = i;
    }

    
    
    

    for(int i=0;i<8;i++){
        char ch = chess[i][col];
        if(ch=='k'){
            int indexOfKing = colWiseCount[KING];
            int indexOfElephant = colWiseCount[ELEPHANT];

            // these two if condition are here to check if the elephant is above or below from king
            if(indexOfElephant<indexOfKing){
                for(int j = indexOfElephant+1;j<=indexOfKing-1;j++){
                    char tempCh = chess[j][col];
                    if(tempCh!=BLANK){
                        return true;
                    }
                }
            }

            else if(indexOfElephant>indexOfKing){
                cout<<"Second";
                for(int j = indexOfKing+1;j<=indexOfElephant-1;j++){
                    char tempCh = chess[j][col];
                    if(tempCh!=BLANK){
                        return true;
                    }
                }
            }
            

            return false;


        }
        
    }


    return true;
}
bool checkForQueen(char chess[][8],int row,int col){
    // since queen's movement is like elephant and camel as well so we just check for both
    return checkForElephant(chess,row,col) && checkForCamel(chess,row,col);
}

bool isKingSave(char chess[][8],int n){
    // check for element first

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            char nameOfEntity = chess[i][j];

            if(nameOfEntity==ELEPHANT){
                if(!checkForElephant(chess,i,j)) return false;
            }

            if(nameOfEntity==CAMEL){
                if(!checkForCamel(chess,i,j)) return false;
            }
            if(nameOfEntity==HORSE){
               if(!checkForHorse(chess,i,j)) return false;
            }
            if(nameOfEntity==QUEEN){
                if(!checkForQueen(chess,i,j)) return false;
            }

        }
    }
    // since after traversing if we do not get falsy value then it would mean that king is safe so return truth
    return true;
}

int main(){
    char chess[8][8]=
    {
         {'.','.','.','k','.','.','.','.'}
        ,{'.','.','.','.','.','.','.','.'}
        ,{'.','.','.','.','.','.','q','.'}
        ,{'.','.','.','.','.','.','.','.'}
        ,{'.','.','.','c','.','.','e','.'}
        ,{'.','.','.','.','.','.','.','.'}
        ,{'.','.','.','.','h','.','.','.'}
        ,{'.','.','.','.','.','.','.','.'}
    };
    
    if(isKingSave(chess,8)) cout<<"Saved";
    else cout<<"Killed";
    return 0;
}