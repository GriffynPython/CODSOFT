#include <iostream>
#include <vector>

using namespace std;

void Board(const vector<char>& board) {
    cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        cout << " " << board[i] << " | " << board[i + 1] << " | " << board[i + 2] << "\n";
        if (i < 6) cout << "---+---+---\n";
    }
    cout << "\n";
}


char Winner(const vector<char>& board) {
    
    for (int i = 0; i < 3; ++i) {
        if (board[i] == board[i + 3] && board[i] == board[i + 6]) return board[i]; 
        if (board[3 * i] == board[3 * i + 1] && board[3 * i] == board[3 * i + 2]) return board[3 * i]; 
    }
    if (board[0] == board[4] && board[0] == board[8]) return board[0]; 
    if (board[2] == board[4] && board[2] == board[6]) return board[2]; 

    return ' '; 
}


bool Draw(const vector<char>& board) {
    for (char cell : board) {
        if (cell != 'X' && cell != 'O') return false;
    }
    return true;
}

int main() {
    cout << "Press 'a' to start the game: ";
    char st;
    cin >> st;

    if (st != 'a') {
        cout << "You did not press a! Exiting.\n";
        return 0;
    }

    vector<char> board(9); 
    for (int i = 0; i < 9; ++i) board[i] = '1' + i; 

    char currentPlayer = 'X';
    while (true) {
        Board(board);

        cout << "Player " << ctPlr << ", enter your move (1-9): ";
        int mv;
        cin >> mv;

        
        if (mv < 1 || mv > 9 || board[mv - 1] == 'X' || board[mv - 1] == 'O') {
            cout << "Only 1-9 is allowed and no overlapping of moves please! Try again.\n";
            continue;
        }

        
        board[mv - 1] = ctPlayer;

        
        char winner = Winner(board);
        if (winner != ' ') {
            Board(board);
            cout << "Player " << winner << " wins!\n";
            break;
        }

        
        if (Draw(board)) {
            Board(board);
            cout << "Unfortunately it's a draw! Please Try Again!\n";
            break;
        }

        
        ctPlayer = (ctPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
