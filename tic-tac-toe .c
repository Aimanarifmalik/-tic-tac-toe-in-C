#include <stdio.h>
#include <stdlib.h>

char board[3][3];

void initialize_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

char check_winner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    int tie = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                tie = 0;
        }
    }
    if (tie)
        return 'T';

    return ' ';
}

void user_move() {
    int row, col;
    printf("Enter your move (row and column): ");
    scanf("%d %d", &row, &col);
    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
        printf("Invalid move. Try again.\n");
        user_move();
    } else {
        board[row][col] = 'X';
    }
}

void ai_move() {
    printf("AI's move:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                return;
            }
        }
    }
}

int main() {
    initialize_board();
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are X, and the AI is O.\n");

    char winner = ' ';
    while (winner == ' ') {
        print_board();
        user_move();
        winner = check_winner();
        if (winner != ' ')
            break;
        ai_move();
        winner = check_winner();
    }

    print_board();

    if (winner == 'X')
        printf("Congratulations! You win!\n");
    else if (winner == 'O')
        printf("AI wins! Better luck next time!\n");
    else
        printf("It's a tie!\n");

    return 0;
}

