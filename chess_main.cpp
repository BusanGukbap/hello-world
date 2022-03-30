#include <bits/stdc++.h>

using namespace std;

class Player {
	int PlayerNum;
	char color;
};

class Unit {
	Player* player;
	int x;
	int y;
public:
	void setPosition(int x, int y);
	void InitMember(char * data, int current_x, int current_y);
	void display();
	bool isCorrectMove();
};

class Board {
	Unit* board[8][8];
	
public:
	void display();
	void setGame();
};

class Pawn : public Unit {
	void display() {

	}
};

void Board::display() {
	for
		for
			if (board[i][j] == NULL)
				cout << " "
			else
				board[i][j]->display();

}
void Board::setGame() {
	Pawn* player1Pawn[8];

	for (int i = 0; i < 8; i++) {
		
		Pawn* pawn = new Pawn();
		board[1][i] = pawn;
		board[1][i]->setPosition(i, 1);
	}
}

int main() {
	Player player1, player2;
	Board chessBoard;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			chessBoard.display();
		}
	}



	return 0;
}