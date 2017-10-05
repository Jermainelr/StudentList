#include <iostream>
#include <cstring>

using namespace std;

const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;
const int X_TURN = 0;
const int O_TURN = 1;

void printBoard(int board[3][3]);
bool checkWin(int player, int board[3][3]);
bool checkTie(int board[3][3]);
void clearBoard(int board[3][3]);

int main() {
	int board[3][3];
	char input[81];
	int turn = X_TURN;
	int totalXWins = 0;
	int totalOWins = 0;
	bool stillPlaying = true;
	clearBoard(board);
	// This is the start of the multi game loop
	while (stillPlaying == true) {
		// This is the start of a single game loop
		while (checkWin(X_MOVE, board) == false && checkWin(O_MOVE, board) == false
					&& checkTie(board) == false) {
			printBoard(board);
			// Ask user if they still want to play
			cin >> input;
			// Validate user input
			if (strlen(input) != 2) {
				cout << "Enter a letter followed by a number"<< endl;
			} else if (input[0] != 'a' && input[0]!= 'b'
					&& input[0] != 'c') {
				cout <<"Row must be an a, b, or c."<< endl;
			} else if (input[1] != '1' && input[1] != '2'
					&& input[1] != '3') {
				cout << "Column must be an 1, 2, or 3." << endl;
			} else {
				// User input was valid update game state
				int row = input[0] - 'a';
				int column = input[1] - '1';
				// Make sure that the board space is available
				if (board[row][column] == BLANK) {
					if (turn == X_TURN) {
						board[row][column] = X_MOVE;
						turn = O_TURN;
					} else {
						board[row][column] = O_MOVE;
						turn = X_TURN;
						}
				} else {
					cout << "There is a piece there!" << endl;
					}
				}
			} // End of single game loop
				// Check who won
			if (checkWin(X_MOVE, board) == true) {
				cout << "X Wins!" << endl;
				totalXWins++;
			} else if (checkWin(O_MOVE, board) == true) {
				cout << "O Wins!" << endl;
				totalOWins++;
			} else {
				// Must be a tie
				cout << "Tie Game!" << endl;

			}
			// Ask if they want to keep
			// playing
			cout << "Play again?"<< endl;
			char yesno[81];
			cin >> yesno;
			if (strcmp(yesno, "yes") == 0 || strcmp(yesno, "y") == 0) {
				stillPlaying = true;
				// Reset the board
				clearBoard(board);
				//Set turn to X
				turn = X_TURN;
				// Print total Wins
				cout << "X has won:" << totalXWins << " O has won:" <<
						totalOWins << endl;
			} else {
				stillPlaying = false;
			}

		} // End of multi game loop
}

void printBoard(int board[3][3]) {
	cout << " \t1\t2\t3" << endl;
	for (int row = 0; row < 3; row++) {
		cout << (char)('a' + row) << "\t";
		for (int column = 0; column < 3; column++) {
			if (board[row][column] == BLANK) {
				cout << " \t";
			} else if (board[row][column] == X_MOVE) {
				cout << "X\t";
			} else if (board[row][column] == O_MOVE) {
				cout << "O\t";
			}
		}
		cout << endl;
	}
}

bool checkWin(int player, int board[3][3]) {
	// Row Wins
	if (board[0][0] == player && board[0][1] == player
			&& board[0][2] == player) {
		return true;
	}
	if (board[1][0] == player && board[1][1] == player
			&& board[1][2] == player) {
		return true;
	}
	if (board[2][0] == player && board[2][1] == player
			&& board[2][2] == player) {
		return true;
	}
	// Column Wins
	if (board[0][0] == player && board[1][0] == player
			&& board[2][0] == player) {
		return true;
	}
	if (board[0][1] == player && board[1][1] == player
			&& board[2][1] == player) {
		return true;
	}
	if (board[0][2] == player && board[1][2] == player
			&& board[2][2] == player) {
		return true;
	}
	// Diagonal Wins
	if (board[0][0] == player && board[1][1] == player
			&& board[2][2] == player) {
		return true;
	}
	if (board[0][2] == player && board[1][1] == player
			&& board[2][0] == player) {
		return true;
	}

	return false;
}

bool checkTie(int board[3][3]) {
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			if (board[row][column] == BLANK) {
				return false;
			}
		}
	}
	return true;
}

void clearBoard(int board[3][3]) {
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			board[row][column] = 0;
		}
	}
}Cpp-TicTacToe
