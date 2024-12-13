#include <iostream>
#include <vector>

using namespace std;
//It was easier to display the board using a funciton. It is good for practice and helps in preventing cluttering and confusion.
//Much easier to just call the function in the while loop as it is a void function.
void Board(const vector<char>& board) {
    cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        cout << " " << board[i] << " | " << board[i + 1] << " | " << board[i + 2] << "\n";
        if (i < 6) cout << "---+---+---\n";
    }
    cout << "\n";
}

int main() {
    //I felt it was a good way to emulate games so I added this option.
    cout << "Press 'a' to start the game: ";
    char st;
    cin >> st;

    if (st != 'a') {
        cout << "You did not press a! Exiting.\n";
        return 0;
    }
    //Create a board using vector.
    vector<char> board(9); 
    for (int i = 0; i < 9; ++i) board[i] = '1' + i; 

    char ctPlr = 'X';
    //flag variable. useful to stop a while loop from going infinite.
    bool gameOver=false;
    while (!gameOver) {
        //Display the board to hepl the participants see its current state.
        Board(board);

        cout << "Player " << ctPlr << ", enter your move (1-9): ";
        int mv;
        cin >> mv;

        //Validate the move. It is very important to take care of the glaring edge cases.
        if (mv < 1 || mv > 9 || board[mv - 1] == 'X' || board[mv - 1] == 'O') {
            cout << "Only 1-9 is allowed and no overlapping of moves please! Try again.\n";
            continue;
        }

        //The players will move from 1-9 while the board is 0-indexed so it is important to subtract one fromt the input given by the user. 
        board[mv - 1] = ctPlayer;
        // Check for a winner
        //Didn't create a function here to check for a winner since this is much more explanatory.
        //I did not want to over complicate the program.
        //This block checks for columns.
        for (int i = 0; i < 3; ++i) {
        if (board[i] == board[i + 3] && board[i] == board[i + 6]){
            cout << "Player " << board[i] << " wins!\n";
            gameOver = true;
            break;
        } // Columns
            //This block checks for rows.
        if (board[3 * i] == board[3 * i + 1] && board[3 * i] == board[3 * i + 2]){
            cout << "Player " << board[3 * i] << " wins!\n";
            Board(board);
            gameOver = true;
            break;
        } // Rows
    }
        //This block checks for main diagonal from top left to bottom right
        if (board[0] == board[4] && board[0] == board[8]){
            cout << "Player " << board[0] << " wins!\n";
            Board(board);
            gameOver = true;
        } // Main diagonal
        //This block checks for anti-diagonal from top-right to bottom left.
        if (board[2] == board[4] && board[2] == board[6]){
            cout << "Player " << board[2] << " wins!\n";
            Board(board);
            gameOver = true;
        }//Anti-Diagonal
        //Much easier to write this here insted of outside main funciton as another functon. It is less cconfusing.
        //Check for draw
        for (char cell : board) {
        if (cell != 'X' && cell != 'O'){
            cout<<"It is a draw"<<endl;
            Board(board);
            gameOver=true;
            break;
        }
    }
        //Flag used to close the while loop
        if(gameOver) break;
        
        ctPlayer = (ctPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
