#include <iostream>

bool checkBoard(int validBoard[3][3], int boardToCheck[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(boardToCheck[i][j] != validBoard[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void printBoard(int board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
}


// This doesn't work
void moveTiles(int input, int board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == input) {
                if (board[i + 1][j] == 0) {
                    board[i + 1][j] = board[i][j];
                    board[i][j] = 0;
                }
                if (board[i - 1][j] == 0) {
                    board[i - 1][j] = board[i][j];
                    board[i][j] = 0;
                }
                if (board[i][j + 1] == 0) {
                    board[i][j + 1] = board[i][j];
                    board[i][j] = 0;
                }
                if (board[i][j - 1] == 0) {
                    board[i][j - 1] = board[i][j];
                    board[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    int board[3][3] = {{1, 8, 2}, {4, 3, 5}, {7, 6, 0}};
    int validBoard[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    std::cout << "Welcome to the Sliding Puzzle game\n"
              << "Here's your board:\n";
    printBoard(board);

    int input;
    bool isInputValid = false;

    // if input is not valid, ask again for input
    while(!isInputValid) {
        std::cout << "Please enter a number between 1 and 8:\n";
        std::cin >> input;
        isInputValid = !(input > 8 || input < 0);
    }

    // move the tiles, and print the new board
    moveTiles(input, board);
    printBoard(board);

    bool isBoardValid = false;

    // as long as the board is not valid, ask for input again
    while(!isBoardValid) {
        std::cout << "Please enter another number:\n";
        std::cin >> input;
        isBoardValid = checkBoard(board, validBoard);
        moveTiles(input, board);
        printBoard(board);
    }

    std::cout << "You have won!";


    return 0;
}