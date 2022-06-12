#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;
char c4board[6][7];
int c4turn = 1;
string c4player;
char c4piece;
int c4gameoverval;

//Gameboard Values
void c4gameval() {
	for (int c4rows = 0; c4rows < 6; c4rows++) {
		for (int c4cols = 0; c4cols < 7; c4cols++) {
			c4board[c4rows][c4cols] = '?';
		}
	}
}
//Gameboard that will get printed at the beginning and each time a move is made
void c4gameboard() {
	cout << "    1   2   3   4   5   6   7  " << endl;
	int c4boardcount;
	for (int c4c = 0; c4c < 6; c4c++) {
		c4boardcount = c4c + 1;
		cout << c4boardcount << " | " << c4board[c4c][0] << " | " << c4board[c4c][1] << " | " << c4board[c4c][2] << " | " << c4board[c4c][3] << " | " << c4board[c4c][4] << " | " << c4board[c4c][5] << " | " << c4board[c4c][6] << " | " << endl;
	}
}

//Player 1 Move
void c4p1turn() {
	int c4colnum = 8;
	int c4repeat = 1;
	int c4colplace;
	c4player = "P1";
	c4piece = 'X';
	cout << "Turn " << c4turn << endl;
	//move
	while ((c4turn % 2) == 1) {
		//column you want the piece to be placed into
		while (c4repeat > 0) {
			cout << "Which column do you want to place your piece(1-7)? ";
			cin >> c4colnum;
			while (c4colnum <= 0 || c4colnum >= 8) {
				cout << "Which column do you want to place your piece(1-7)? ";
				cin >> c4colnum;
			}
			c4repeat = 0;
		}
		c4colplace = c4colnum - 1;
		//check for open space in the column
		for (int c4rowcount = 5; c4rowcount >= 0; c4rowcount--) {
			if (c4board[c4rowcount][c4colplace] == '?') {
				c4board[c4rowcount][c4colplace] = c4piece;
				c4gameboard();
				cout << "Turn " << c4turn << " over" << endl;
				c4turn = c4turn + 1;
				break;
			}
		}
		//End Turn if column is acceptable for move
		if ((c4turn % 2) == 0) {
			break;
		}
		//Ask for another column if column is not acceptable for move
		c4repeat = 1;
		cout << "Choose another column" << endl;
	}
}

//Player 2 Move
void c4p2turn() {
	int c4colnum = 8;
	int c4repeat = 1;
	int c4colplace;
	c4player = "P2";
	c4piece = 'O';
	cout << "Turn " << c4turn << endl;
	//move
	while ((c4turn % 2) == 0) {
		//column you want the piece to be placed into
		while (c4repeat > 0) {
			cout << "Which column do you want to place your piece(1-7)? ";
			cin >> c4colnum;
			while (c4colnum <= 0 || c4colnum >= 8) {
				cout << "Which column do you want to place your piece(1-7)? ";
				cin >> c4colnum;
			}
			c4repeat = 0;
		}
		c4colplace = c4colnum - 1;
		//check for open space in the column
		for (int c4rowcount = 5; c4rowcount >= 0; c4rowcount--) {
			if (c4board[c4rowcount][c4colplace] == '?') {
				c4board[c4rowcount][c4colplace] = c4piece;
				c4gameboard();
				cout << "Turn " << c4turn << " over" << endl;
				c4turn = c4turn + 1;
				break;
			}
		}
		//End Turn if column is acceptable for move
		if ((c4turn % 2) == 1) {
			break;
		}
		//Ask for another column if column is not acceptable for move
		c4repeat = 1;
		cout << "Choose another column" << endl;
	}
}

//Gameover Scenarios: Return 1 if game is over, Return 0 if game is still ongoing
int c4gameover() {
	//Vertical Win
	for (int c4colcount = 0; c4colcount <= 6; c4colcount++) {
		for (int c4rowcount = 5; c4rowcount > 2; c4rowcount--) {
			if (c4board[c4rowcount][c4colcount] == c4piece && c4board[c4rowcount - 1][c4colcount] == c4piece && c4board[c4rowcount - 2][c4colcount] == c4piece && c4board[c4rowcount - 3][c4colcount] == c4piece) {
				cout << c4player << " wins" << endl;
				return 1;
			}
		}
	}
	//Horizontal Win
	for (int c4rowcount = 5; c4rowcount >= 0; c4rowcount--) {
		for (int c4colcount = 0; c4colcount < 4; c4colcount++) {
			if (c4board[c4rowcount][c4colcount] == c4piece && c4board[c4rowcount][c4colcount + 1] == c4piece && c4board[c4rowcount][c4colcount + 2] == c4piece && c4board[c4rowcount][c4colcount + 3] == c4piece) {
				cout << c4player << " wins" << endl;
				return 1;
			}
		}
	}
	//Downward Diagonal Win
	for (int c4colcount = 0; c4colcount < 4; c4colcount++) {
		for (int c4rowcount = 0; c4rowcount < 3; c4rowcount++) {
			if (c4board[c4rowcount][c4colcount] == c4piece && c4board[c4rowcount + 1][c4colcount + 1] == c4piece && c4board[c4rowcount + 2][c4colcount + 2] == c4piece && c4board[c4rowcount + 3][c4colcount + 3] == c4piece) {
				cout << c4player << " wins" << endl;
				return 1;
			}
		}
	}
	//Upward Diagonal Win
	for (int c4colcount = 6; c4colcount > 2; c4colcount--) {
		for (int c4rowcount = 0; c4rowcount < 3; c4rowcount++) {
			if (c4board[c4rowcount][c4colcount] == c4piece && c4board[c4rowcount + 1][c4colcount - 1] == c4piece && c4board[c4rowcount + 2][c4colcount - 2] == c4piece && c4board[c4rowcount + 3][c4colcount - 3] == c4piece) {
				cout << c4player << " wins" << endl;
				return 1;
			}
		}
	}
	//Tie
	if (c4turn == 43) {
		cout << "Its a tie";
		return 1;
	}
	return 0;
}

int main() {
	cout << "Welcome to Connect Four" << endl;
	cout << "Player 1 is X and Player 2 is O" << endl;
	//Create values
	c4gameval();
	//Create board
	c4gameboard();
	c4gameoverval = 0;
	while (c4gameoverval == 0) {
		c4p1turn();
		c4gameoverval = c4gameover();
		//The game ends and P1 wins if the function above returns 1
		if (c4gameoverval == 1) {
			break;
		}
		c4p2turn();
		c4gameoverval = c4gameover();
		//The game ends and P2 wins if the function above returns 1
		if (c4gameoverval == 1) {
			break;
		}
	}
	return 0;
}