#include <iostream>
#include <vector>

using namespace std;

// Function to display the board
void displayBoard(const vector<char>& board) {
    cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        cout << " " << board[i] << " | " << board[i + 1] << " | " << board[i + 2] << "\n";
        if (i < 6) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Function to check for a winner
char checkWinner(const vector<char>& board) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if (board[i] == board[i + 3] && board[i] == board[i + 6]) return board[i]; // Columns
        if (board[3 * i] == board[3 * i + 1] && board[3 * i] == board[3 * i + 2]) return board[3 * i]; // Rows
    }
    if (board[0] == board[4] && board[0] == board[8]) return board[0]; // Main diagonal
    if (board[2] == board[4] && board[2] == board[6]) return board[2]; // Anti-diagonal

    return ' '; // No winner yet
}

// Function to check if the board is full (draw)
bool isDraw(const vector<char>& board) {
    for (char cell : board) {
        if (cell != 'X' && cell != 'O') return false;
    }
    return true;
}

int main() {
    cout << "Press 'a' to start the game: ";
    char start;
    cin >> start;

    if (start != 'a') {
        cout << "Invalid input. Exiting.\n";
        return 0;
    }

    vector<char> board(9); // Tic-tac-toe board
    for (int i = 0; i < 9; ++i) board[i] = '1' + i; // Initialize with cell numbers

    char currentPlayer = 'X';
    while (true) {
        displayBoard(board);

        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        int move;
        cin >> move;

        // Validate move
        if (move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        // Make the move
        board[move - 1] = currentPlayer;

        // Check for a winner
        char winner = checkWinner(board);
        if (winner != ' ') {
            displayBoard(board);
            cout << "Player " << winner << " wins!\n";
            break;
        }

        // Check for a draw
        if (isDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
