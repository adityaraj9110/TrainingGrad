#include<bits/stdc++.h>
using namespace std;

// for printing of board so that both users can see the current state of gamecccccccccccccccccccxxxxxxxxxxxxxxxxxxxxxxxxxss


void printTicTakToe(char board[3][3],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<board[i][j];
            if(j!=col-1) cout<<" ";
        }
        cout<<"\n";
    }
}

void placedSignAtPosition(char board[3][3],int row,int col,char sign){
    board[row][col] = sign;
}

bool isCorrectPosition(char board[3][3], int row,int col){
    return row>=0 && row<3 && col>=0 && col<3 && board[row][col]==' ';
}

bool checkForRowWise(char board[3][3],int row,char sign){
    int countOfSameCharacter = 0;
    for(int i=0;i<3;i++){
        if(board[row][i]!=sign) return false;
    }
    
    return true;
}

bool checkForColumnWise(char board[3][3],int col,char sign){
    int countOfSameCharacter = 0; 
    for(int i=0;i<3;i++){
        if(board[i][col]!=sign) return false;
    }
    return true;
}

bool checkForDiagonally(char board[3][3],int row,int col,char sign){
    cout<<"Check Diagonally"<<row<<" "<<col<<'\n';
    if(row==0 && col==0){
        
        if(board[0][1]!=sign || board[0][2]!=sign) return false;
        else return true;
    }

    if(row==0 && col==2){
        if(board[1][1]!=sign || board[2][0]!=sign) return false;
        else return true;
    }

    if(row==2 && col==0){
        if(board[1][1]!=sign || board[0][2]!=sign) return false;
        else return true;
    }
    if(row==2 && col==2){
        if(board[1][1]!=sign || board[0][0]!=sign) return false;
        else return true;
    }
    if(row==1 && col==1){
        if(board[0][0]!=sign || board[2][0]!=sign) return false;
        else return true;
    }
}

bool checkForTheWinSitutation(char board[3][3],int rowPositionByFirstPlayer,int colPositionBySecondPlayer,char sign){
    // checking of rowWise
    int i = rowPositionByFirstPlayer,j=colPositionBySecondPlayer;

    if((i==0 && j==0) || (i==0 && j==2) || (i==2 && j==0) || (i==2 && j==2) || i==1 && j==1){
        return checkForDiagonally(board,rowPositionByFirstPlayer,colPositionBySecondPlayer,sign) ;
    }
    else return checkForRowWise(board,rowPositionByFirstPlayer,sign) || checkForColumnWise(board,colPositionBySecondPlayer,sign)  ;
}

void getInputFormUser1(int &row,int &col){
    
}

void startGame(char board[3][3],int row,int col){
    int totalMove = 9;
    char moveByPlayer1 ;
    char moveByPlayer2 ;
    cout<<"Player 1 choose for sign 0 or x: ";
    cin>>moveByPlayer1;
    moveByPlayer2 = moveByPlayer1=='0' ? 'x' : '0';
    bool player2IsCorrect = true;
    while(totalMove>0){
        


        if(player2IsCorrect){
            int rowPositionByFirstPlayer;
            int colPositionByFirstPlayer;
            cout<<"Player 1 turn"<<"\n";
            cout<<"Now Enter the position(row number and column number) you want to fit this: ";
            cin>>rowPositionByFirstPlayer>>colPositionByFirstPlayer;

            if(!isCorrectPosition(board,rowPositionByFirstPlayer,colPositionByFirstPlayer)){
                cout<<"Please provide valid move\n";
                continue;
            }
            else{
                placedSignAtPosition(board,rowPositionByFirstPlayer,colPositionByFirstPlayer,moveByPlayer1);
                totalMove--;
                if(totalMove==0){
                    printTicTakToe(board,3,3);
                    cout<<"Game is Tie";
                    break;
                }
            } 
                
            printTicTakToe(board,row,col);

            // check For the win situation
            if(checkForTheWinSitutation(board,rowPositionByFirstPlayer,colPositionByFirstPlayer,moveByPlayer1)){
                cout<<"Congratulations player 1 you are winner";
                break;
            }
        }

        
        int rowPositionBySecondPlayer;
        int colPositionBySecondPlayer;

        cout<<"Player 2 turn"<<"\n";
        cout<<"Now Enter the position(row number and column number) you want to fit this: ";
        cin>>rowPositionBySecondPlayer>>colPositionBySecondPlayer;

        if(!isCorrectPosition(board,rowPositionBySecondPlayer,colPositionBySecondPlayer)){
            cout<<"Please provide valid move\n";
            player2IsCorrect = false;
            continue;
        }
        else{
            player2IsCorrect = true;
            placedSignAtPosition(board,rowPositionBySecondPlayer,colPositionBySecondPlayer,moveByPlayer2);
            totalMove--;
            if(totalMove==0) {
                printTicTakToe(board,3,3);
                cout<<"No Game Is Tie";
                break;
            }
        } 
        printTicTakToe(board,row,col);

        // check For the win situation
        if(checkForTheWinSitutation(board,rowPositionBySecondPlayer,colPositionBySecondPlayer,moveByPlayer2)){
            cout<<"Congratulations player 2 you are winner";
            break;
        }
        
        
        cout<<"Move Left: "<<totalMove<<"\n";
        

        
    }
}

int main(){
    char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

    startGame(board,3,3);
    
    
    return 0;
}