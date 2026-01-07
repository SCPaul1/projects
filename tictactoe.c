#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
int makeMove(char board[SIZE][SIZE], int row, int col, char player);
int checkWin(char board[SIZE][SIZE], char player);
int checkDraw(char board[SIZE][SIZE]);
void switchPlayer(char *currentPlayer);

int main() {
    char board[SIZE][SIZE];
    char currentPlayer = 'X';
    int row, col;
    int moves = 0;
    int gameOver = 0;
    
    printf("=== TIC-TAC-TOE GAME ===\n");
    printf("Player 1: X | Player 2: O\n\n");
    
    initializeBoard(board);
    
    while (!gameOver) {
        displayBoard(board);
        
        int validInput = 0;
        while (!validInput) {
            printf("\nPlayer %c's turn\n", currentPlayer);
            printf("Enter row (1-3) and column (1-3): ");
            
            if (scanf("%d %d", &row, &col) != 2) {
                printf("Invalid input! Please enter numbers only.\n");
                while (getchar() != '\n'); 
                continue;
            }
            
            row--;
            col--;
            
            if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
                printf("Invalid position! Row and column must be between 1 and 3.\n");
            } else if (makeMove(board, row, col, currentPlayer)) {
                validInput = 1;
                moves++;
            } else {
                printf("Position already occupied! Try again.\n");
            }
        }
        
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            printf("\n🎉 Player %c wins! 🎉\n", currentPlayer);
            gameOver = 1;
        }
        else if (checkDraw(board)) {
            displayBoard(board);
            printf("\n🤝 It's a draw! 🤝\n");
            gameOver = 1;
        }
        else {
            switchPlayer(&currentPlayer);
        }
    }
    
    printf("\nThanks for playing!\n");
    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}


void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");
    printf("    1   2   3\n");
    printf("  +---+---+---+\n");
    
    for (int i = 0; i < SIZE; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("  +---+---+---+\n");
    }
}

int makeMove(char board[SIZE][SIZE], int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return 1;
    }
    return 0; 
}

int checkWin(char board[SIZE][SIZE], char player) {
    
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && 
            board[i][1] == player && 
            board[i][2] == player) {
            return 1;
        }
    }
    

    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == player && 
            board[1][j] == player && 
            board[2][j] == player) {
            return 1;
        }
    }
    

    if (board[0][0] == player && 
        board[1][1] == player && 
        board[2][2] == player) {
        return 1;
    }
    
    if (board[0][2] == player && 
        board[1][1] == player && 
        board[2][0] == player) {
        return 1;
    }
    
    return 0;
}


int checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; 
            }
        }
    }
    return 1; 
}


void switchPlayer(char *currentPlayer) {
    *currentPlayer = (*currentPlayer == 'X') ? 'O' : 'X';
}