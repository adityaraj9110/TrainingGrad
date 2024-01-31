#include<bits/stdc++.h>
using namespace std;

// for printing of board so that both users can see the current state of game

void printTicTakToe(char board[3][3],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<board[i][j];
            if(j!=col-1) cout<<" ";
        }
        cout<<"\n";
    }
    cout<<"-------"<<"\n";
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

    if((i==0 && j==0) || (i==0 && j==2) || (i==2 && j==0) || (i==2 && j==2) || (i==1 && j==1)){
        return checkForDiagonally(board,rowPositionByFirstPlayer,colPositionBySecondPlayer,sign) ;
    }
    else return checkForRowWise(board,rowPositionByFirstPlayer,sign) || checkForColumnWise(board,colPositionBySecondPlayer,sign)  ;
}

void checkForLossProbabilityInRowWise(char board[3][3],int row,int col,char signByPlayer1,char signByAI,bool &rowWise,int &totalMove){
    // rowWise Checking
    
    int rowWiseSignCount = 0;
    for(int i=0;i<3;i++){
        if(board[row][i]==signByPlayer1) rowWiseSignCount++;
    }

    if(rowWiseSignCount==2){
        for(int i=0;i<3;i++){
            if(board[row][i]==' '){
                board[row][i] = signByAI;
                rowWise = true;
                totalMove--;
                break;
            }
        }
    }

}

void checkForLossProbabilityInColWise(char board[3][3],int row,int col,char signByPlayer1,char signByAI,bool &colWise,int &totalMove){
    
    int colWiseSignCount = 0;
    for(int i=0;i<3;i++){
        if(board[i][col]==signByPlayer1) colWiseSignCount++;
    }
    // cout<<row<<" "<<col<<"\n";
    if(colWiseSignCount==2){
        for(int i=0;i<3;i++){
            if(board[i][col]==' '){
                board[i][col] = signByAI;
                colWise = true;
                totalMove--;
                break;
            }
        }
    }
}

void checkForLossProbabilityDiagonally(char board[3][3],int row,int col,char signByPlayer1,char signByAI,bool &diagonalWise,int &totalMove){
    
    int diagoanlWiseCount = 0;
    for(int i=0;i<3;i++){
        if(board[i][i]==signByPlayer1) diagoanlWiseCount++;
    }

    if(diagonalWise==2){
        for(int i=0;i<3;i++){
            if(board[i][i]==' '){
                board[i][i]=signByAI;
                diagonalWise = true;
                totalMove--;
                break;
            }
        }
    }
}

void checkForWinProbability(char board[3][3],char signByAI,char signByPlayer,int &totalMove,bool &placedForWin){
    int placingInXAxis = 0;
    int placingInYAxis = 0;
    // cout<<"Sign ByAI"<<signByAI<<"\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            char currentSign = board[i][j];

            if(currentSign==signByAI){
                // row wise
                int rowWiseCountOfSign=0;
                for(int x=0;x<3;x++){
                    if(board[i][x]==signByPlayer) break;
                    else if(board[i][x]==signByAI) rowWiseCountOfSign++;
                    else if(board[i][x]==' '){
                        placingInXAxis = i;
                        placingInYAxis = x;
                    }
                }
                
                if(rowWiseCountOfSign==2){
                    board[placingInXAxis][placingInYAxis] = signByAI;
                    // printTicTakToe(board,3,3);
                    totalMove--;
                    placedForWin = true;
                    break;
                }

                // col wise
                int colWiseCountOfSign = 0;
                for(int y=0;y<3;y++){
                    if(board[y][j]==signByPlayer) break;
                    else if(board[y][j]==signByAI) colWiseCountOfSign++;
                    else if(board[y][j]==signByAI){
                        placingInXAxis = j;
                        placingInYAxis = y;
                    }
                }

                if(colWiseCountOfSign==2){
                    board[placingInXAxis][placingInYAxis]=signByAI;
                    // printTicTakToe(board,3,3);
                    totalMove--;
                    placedForWin=true;
                    break;
                }
                // diagonally wise
                int diagonalyCountOfSign = 0;
                if((i==0&&j==0) || (i==0 && j==2) || (i==2 &&j==0) ||(i==1 && j==1) || (i==2 && j==2) ){
                   if(i==0 && j==0){
                    if((board[i][j+1]==' ' && board[i][j+2]==signByAI) || (board[i][j+1]==signByAI && board[i][j+2]==' ')){
                         if(board[i][j+1]==' '){
                            placingInXAxis = i;
                            placingInYAxis = j+1;
                         }
                         else if(board[i][j+2]==' '){
                            placingInXAxis = i;
                            placingInYAxis = j+2;
                         }
                         diagonalyCountOfSign=2; 
                    }
                   } 
                   if(i==0 && j==2){
                        if((board[i+1][j-1]==' ' && board[i+2][j-2]==signByAI) || (board[i+1][j-1]==signByAI && board[i+2][j-2]==' ')) {
                            if(board[i+1][j-1]==' '){
                                placingInXAxis = i+1;
                                placingInYAxis = j-1;
                            }
                            else if(board[i+2][j-2]==' '){
                                placingInXAxis = i+2;
                                placingInYAxis = j-2;
                            }
                            diagonalyCountOfSign=2;
                        }
                   } 
                   if(i==2 && j==0){
                        if((board[i+1][j+1]==' ' && board[i-2][j+2]==signByAI) || (board[i+1][j+1]==signByAI && board[i-2][j+2]==' ')) {
                            if(board[i+1][j+1]==' '){
                                placingInXAxis = i+1;
                                placingInYAxis = j+1;
                            }
                            else if(board[i-2][j+2]==' '){
                                placingInXAxis = i-2;
                                placingInYAxis = j+2;
                            }
                            diagonalyCountOfSign=2;
                        }
                   } 
                   if(i==2 && j==2){
                        if((board[i-1][j-1]==' ' && board[i-2][j-2]==signByAI) || (board[i-1][j-1]==signByAI && board[i-2][j-2]==' ')) {
                            if(board[i-1][j-1]==' '){
                                placingInXAxis = i-1;
                                placingInYAxis = j-1;
                            }
                            else if(board[i-2][j-2]==' '){
                                placingInXAxis = i-2;
                                placingInYAxis = j-2;
                            }
                            diagonalyCountOfSign=2;
                        }
                   } 
                   if(i==1 && j==1){
                        if((board[i-1][j-1]==' ' && board[i+2][j-2]==signByAI) || (board[i-1][j-1]==signByAI && board[i+2][j-2]==' ')) {
                            if(board[i-1][j-1]==' '){
                                placingInXAxis = i-1;
                                placingInYAxis = j-1;
                            }
                            else if(board[i+2][j-2]==' '){
                                placingInXAxis = i+2;
                                placingInYAxis = j-2;
                            }
                            diagonalyCountOfSign=2;
                        }
                   } 
                }
            
                if(diagonalyCountOfSign==2){
                    board[placingInXAxis][placingInYAxis] = signByAI;
                    printTicTakToe(board,3,3);
                    totalMove--;
                    placedForWin = true;
                    break;
                }
            }
        }
    }
    
    
}

void startGameWithAi(char board[3][3],int row,int col){

    int totalMove = 9;
    char moveByPlayer1 ;
    char moveByPlayer2 ;
    cout<<"Player 1 choose for sign 0 or x: ";
    cin>>moveByPlayer1;
    moveByPlayer2 = moveByPlayer1=='0' ? 'x' : '0';
    bool player2IsCorrect = true;
    int rowPositionByFirstPlayer;
    int colPositionByFirstPlayer;
    while(totalMove>0){

        if(player2IsCorrect){
            
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
                // cout<<"TotalMove:"<<totalMove<<"\n";
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

        // vs AI

        


        int rowPositionBySecondPlayer;
        int colPositionBySecondPlayer;

        

        
        rowPositionBySecondPlayer = clock()%3;
        colPositionBySecondPlayer = clock()%3;

        if(!isCorrectPosition(board,rowPositionBySecondPlayer,colPositionBySecondPlayer)){
            player2IsCorrect = false;
            continue;
        }
        else{
            player2IsCorrect = true;

            bool rowWise = false;
            bool colWise = false;
            bool diagonalWise = false;
            
            bool placedForWin = false;
            checkForWinProbability(board,moveByPlayer2,moveByPlayer1,totalMove,placedForWin);
            
            if(placedForWin){
                cout<<"Oops Computer Win"<<"\n";
                printTicTakToe(board,3,3);
                break;
            }

            checkForLossProbabilityInRowWise(board,rowPositionByFirstPlayer,colPositionByFirstPlayer,moveByPlayer1,moveByPlayer2,rowWise,totalMove);
            checkForLossProbabilityInColWise(board,rowPositionByFirstPlayer,colPositionByFirstPlayer,moveByPlayer1,moveByPlayer2,colWise,totalMove);
            checkForLossProbabilityDiagonally(board,rowPositionByFirstPlayer,colPositionByFirstPlayer,moveByPlayer1,moveByPlayer2,diagonalWise,totalMove);
            
            if(rowWise){
                printTicTakToe(board,row,col);
            }

            else if(colWise) {
                printTicTakToe(board,row,col);
            }

            else if(diagonalWise) {
                printTicTakToe(board,row,col);
            }
            else{
                placedSignAtPosition(board,rowPositionBySecondPlayer,colPositionBySecondPlayer,moveByPlayer2);
                totalMove--;
                
                if(totalMove==0) {
                    printTicTakToe(board,3,3);
                    cout<<"No Game Is Tie";
                    break;
                }
            }  

        } 
        printTicTakToe(board,row,col);

        // check For the win situation
        if(checkForTheWinSitutation(board,rowPositionBySecondPlayer,colPositionBySecondPlayer,moveByPlayer2)){
            cout<<"Oops Computer is winner!!";
            break;
        }
        


        
        
        
        cout<<"Move Left: "<<totalMove<<"\n";
        

        
    }
}

void startGameWithFriend(char board[3][3],int row,int col){
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
    int level=1;
    cout<<"Play with your friend Or vs Computer (press 1 to play with friend and 2 for computer as oppenent): ";
    cin>>level;
    if(level==1){
        startGameWithFriend(board,3,3);
    }else{

        startGameWithAi(board,3,3);
    }
    return 0;
}