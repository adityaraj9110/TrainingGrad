 Write a method Boolean isValidSudoku(int[][]Sudoku)Returns true if the given Sudoku is correctly arranged otherwise false
Determine if a 9 x 9 The Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Example :
Input: board = 
 {'.','.','.','.','.','.','.','.'}
,{'.','.','.','.','k','e','.','h'}
,{'.','.','.','.','.','.','.','.'}
,{'.','.','.','.','.','.','.','.'}
,{'.','.','.','.','.','.','.','.'}
,{'.','.','.','.','.','.','.','.'}
,{'.','.','.','.','.','.','.','.'}
,{'.','.','.','.','.','.','.','.'}


[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]Output: true
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
 
 
ii) Write a method Boolean isKingSafe(int[][]chessBoard)
Returns true if king in the given chess board is safe from the given enemies otherwise false;
NOTE: Enemies are- Horse, Camel, Queen, Elephant only
Do not consider the colour case of the chess board for traversal of camel and all.

{'.','.','.','.','.','.','.','.'}
,{'.','.','.','.','.','.','.','.'}
,{'.','.','.','.','.','.','.','.'}
,{'.','.','.','k','.','e','.','.'}
,{'.','.','.','.','.','.','.','.'}
,{'.','.','.','.','.','.','.','.'}
,{'.','.','.','.','.','.','.','.'}
,{'.','.','.','.','.','.','.','.'}