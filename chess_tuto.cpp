#include <iostream>
#include <Windows.h>

using namespace std;
bool gameover;

enum Color {
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE
};

int knight_dx[] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int knight_dy[] = { 1, -1, 2, -2, 2, -2, 1, -1 };
int unit_dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int unit_dy[] = { 1, 0, -1, 1, -1, 1, 0, -1 };

typedef struct Node {
	char data;
	int player;
} Node;

typedef struct king {
	int x;
	int y;
};

Node Board[8][8];

king White_king;
king Black_king;

void textcolor(int foreground, int background) {
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void set_start() {
	gameover = false;
	Board[0][0].data = Board[0][7].data = Board[7][0].data = Board[7][7].data = 'R';
	Board[0][1].data = Board[0][6].data = Board[7][1].data = Board[7][6].data = 'N';
	Board[0][2].data = Board[0][5].data = Board[7][2].data = Board[7][5].data = 'B';
	Board[0][3].data = Board[7][3].data = 'Q';
	Board[0][4].data = Board[7][4].data = 'K';
	White_king.x = 7; White_king.y = 4;
	Black_king.x = 0; Black_king.y = 4;

	for (int i = 0; i < 8; i++) {
		Board[1][i].data = Board[6][i].data = 'P';
		Board[0][i].player = Board[1][i].player = 1;
		Board[7][i].player = Board[6][i].player = 2;
		Board[2][i].player = Board[3][i].player = Board[4][i].player = Board[5][i].player = 0;
		Board[2][i].data = Board[3][i].data = Board[4][i].data = Board[5][i].data = ' ';
	}
}

// 체스판 출력
void print_chess() {
	cout << "  ";
	for (int i = 0; i < 8; i++) {
		char t = 'a' + i;
		cout << " " << t << " ";
	}
	cout << '\n';

	for (int i = 0; i < 8; i++) {
		textcolor(WHITE, BLACK);
		cout << 1 + i << " ";
		for (int j = 0; j < 8; j++) {
			if (Board[i][j].player == 1) {
				if ((i + j) % 2 == 0)
					textcolor(RED, BROWN);
				else
					textcolor(RED, YELLOW);
			}
			else {
				if ((i + j) % 2 == 0)
					textcolor(BLACK, BROWN);
				else
					textcolor(BLACK, YELLOW);
			}
			cout << " " << Board[i][j].data << " ";
		}
		textcolor(WHITE, BLACK);
		cout << '\n';
	}
	textcolor(WHITE, BLACK);
}

bool Is_Unit_Right(char input_x, int y, int player) {
	int x = input_x - 'a';
	y--;
	if (x < 0 || x > 7 || y < 0 || y > 7)
		return false;
	if (Board[y][x].data == ' ')
		return false;
	if (Board[y][x].player != player) {
		return false;
	}

	return true;
}

bool Is_Pawn_Move_Right(int x, int y, int nx, int ny) {
	bool ans;

	// 흰색인 경우
	if (Board[y][x].player == 1) {
		// 처음엔 두칸 전진 가능
		if (y == 1 && ny - y == 2 && nx == x && Board[ny][nx].data == ' ')
			ans = true;
		else if (ny - y == 1) {
			// 직진할 때, 앞에 아무것도 없어야 함
			if (nx == x && Board[ny][nx].data == ' ')
				ans = true;
			// 왼쪽 대각선, 이동 할 곳에 적 기물이 있어야 함
			else if (x - nx == 1 && Board[ny][nx].player == 2)
				ans = true;
			// 오른쪽 대각선, 이동 할 곳에 적 기물이 있어야 함
			else if (nx - x == 1 && Board[ny][nx].player == 2)
				ans = true;
			else
				ans = false;
		}
		else
			ans = false;
	}

	// 검은색인 경우
	else {
		// 처음엔 두칸 전진 가능
		if (y == 6 && y - ny == 2 && nx == x && Board[ny][nx].data == ' ') {
			ans = true;
		}
		else if (y - ny == 1) {
			if (nx == x && Board[ny][nx].data == ' ')
				ans = true;
			else if (x - nx == 1 && Board[ny][nx].player == 1)
				ans = true;
			else if (nx - x == 1 && Board[ny][nx].player == 1)
				ans = true;
			else
				ans = false;
		}
		else
			ans = false;
	}

	return ans;
}

bool Is_King_Move_Right(int x, int y, int nx, int ny, int player) {
	bool ans = false;

	for (int index = 0; index < 8; index++) {
		if (nx == x + unit_dx[index] && ny == y + unit_dy[index]) {
			if (Board[ny][nx].player != player)
				ans = true;
		}
	}

	return ans;
}

bool Is_Bishop_Move_Right(int x, int y, int nx, int ny, int player) {
	bool ans = true;
	int index_x, index_y;

	if (ny > y)
		index_y = 1;
	else
		index_y = -1;
	if (nx > x)
		index_x = 1;
	else
		index_x = -1;

	// 대각선으로 움직였을때
	if (abs(nx - x) == abs(ny - y)) {
		int index;
		for (index = 1; index < abs(ny - y); index++) {
			if (Board[y + index * index_y][x + index * index_x].data != ' ') {
				ans = false;
				break;
			}
		}

		if (index == abs(ny - y) && Board[ny][nx].player == player) {
			ans = false;
		}
	}
	else {
		ans = false;
	}

	return ans;
}

bool Is_Knight_Move_Right(int x, int y, int nx, int ny, int player) {
	bool ans = false;

	for (int index = 0; index < 8; index++) {
		if (nx == x + knight_dx[index] && ny == y + knight_dy[index]) {
			if (Board[ny][nx].player != player)
				ans = true;
		}
	}

	return ans;
}

bool Is_Rook_Move_Right(int x, int y, int nx, int ny, int player) {
	bool ans = true;
	int index_x, index_y;

	if (ny > y)
		index_y = 1;
	else
		index_y = -1;
	if (nx > x)
		index_x = 1;
	else
		index_x = -1;

	if (nx != x && ny != y) {
		ans = false;
	}
	else {
		int index;

		if (nx == x) {
			for (index = 1; index < abs(ny - y); index++) {
				if (Board[y + index * index_y][x].data != ' ') {
					ans = false;
					break;
				}
			}

			if (index == abs(ny - y) && Board[ny][nx].player == player) {
				ans = false;
			}
		}
		else if (ny == y) {
			for (index = 1; index < abs(nx - x); index++) {
				if (Board[y][x + index * index_x].data != ' ') {
					ans = false;
					break;
				}
			}

			if (index == abs(nx - x) && Board[ny][nx].player == player) {
				ans = false;
			}
		}
	}

	return ans;
}

bool Is_Queen_Move_Right(int x, int y, int nx, int ny, int player) {
	bool ans = true;
	int index_x, index_y;

	//if (nx == x || ny == y) {
	//	ans = Is_Rook_Move_Right(x, y, nx, ny, player);
	//}
	//else
	//	ans = Is_Bishop_Move_Right(x, y, nx, ny, player);

	if (ny > y)
		index_y = 1;
	else if (ny == y)
		index_y = 0;
	else
		index_y = -1;

	if (nx > x)
		index_x = 1;
	else if (nx == x)
		index_x = 0;
	else
		index_x = -1;

	int index;
	if (nx == x) {
		for (index = 1; index < abs(ny - y); index++) {
			if (Board[y + index * index_y][x].data != ' ') {
				ans = false;
				break;
			}
		}

		if (index == abs(ny - y) && Board[ny][nx].player == player) {
			ans = false;
		}
	}
	else {
		for (index = 1; index < abs(nx - x); index++) {
			if (Board[y + index * index_y][x + index * index_x].data != ' ') {
				ans = false;
				break;
			}
		}

		if (index == abs(nx - x) && Board[ny][nx].player == player) {
			ans = false;
		}
	}

	return ans;
}

bool Is_Unit_Move_Right(char input_x, int y, char move_x, int ny, int player) {
	int x = input_x - 'a';
	int nx = move_x - 'a';
	y--; ny--;
	bool ans = false;

	if (nx < 0 || ny < 0 || nx > 8 || ny > 8)
		return false;

	switch (Board[y][x].data) {
		case 'P':
			ans = Is_Pawn_Move_Right(x, y, nx, ny);
			break;

		case 'K':
			ans = Is_King_Move_Right(x, y, nx, ny, player);
			break;

		case 'Q':
			ans = Is_Queen_Move_Right(x, y, nx, ny, player);
			break;

		case 'B':
			ans = Is_Bishop_Move_Right(x, y, nx, ny, player);
			break;

		case 'N':
			ans = Is_Knight_Move_Right(x, y, nx, ny, player);
			break;

		case 'R':
			ans = Is_Rook_Move_Right(x, y, nx, ny, player);
			break;
	}

	return ans;
}

void Move_Unit(char input_x, int y, char move_x, int ny) {
	int x = input_x - 'a';
	int nx = move_x - 'a';
	y--; ny--;
	
	if (Board[ny][nx].data == 'K') {
		cout << "(Player " << Board[ny][nx].player << " ) King is dead\n";
		cout << "Player " << Board[y][x].player << " Win \n";
		gameover = true;
	}

	Board[ny][nx].data = Board[y][x].data;
	Board[ny][nx].player = Board[y][x].player;
	Board[y][x].player = 0; Board[y][x].data = ' ';
	
	return;
}

void play_chess(int player) {
	char input_x, move_x;
	int input_y, move_y;
	bool is_correct_input = true;

	do {
		is_correct_input = true;
		cout << "Red word is player 1 && Black word is player 2\n";
		cout << "player : " << player << '\n';
		print_chess();
		cout << "Press Key : (a to h) (1 to 8) ";
		cin >> input_x >> input_y;

		while (!Is_Unit_Right(input_x, input_y, player)) {
			cout << "잘못된 입력입니다. Press Key : (a to h) (1 to 8) ";
			cin >> input_x >> input_y;
		}


		cout << "z 0 을 입력시 되돌리기 할 수 있습니다.\n";
		cout << "Where we go? : (a to h) (1 to 8) ";
		cin >> move_x >> move_y;
		if (move_x == 'z' && move_y == 0) {
			
			is_correct_input = false;
		}
		if (is_correct_input == true) {

			while (is_correct_input == true && !Is_Unit_Move_Right(input_x, input_y, move_x, move_y, player)) {
				cout << "갈 수 없습니다. Where we go? : (a to h) (1 to 8) ";
				cin >> move_x >> move_y;
				if (move_x == 'z' && move_y == 0) {
					is_correct_input = false;
				}
			}
		}
	} while (!is_correct_input);


	Move_Unit(input_x, input_y, move_x, move_y);
	
	/*if (gameover == true) {
		print_chess();
		return;
	}*/

	/*for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << Board[i][j].player << " ";
		}
		cout << '\n';
	}*/

	/*if (player == 1)
		play_chess(2);
	else if (player == 2)
		play_chess(1);*/
}

int main() {
	int turn;
	gameover = true;
	set_start();

	turn = 1;
	while (gameover == false) {
		play_chess(turn);

		if (turn == 1)
			turn = 2;
		else
			turn = 1;
	}

	print_chess();


	return 0;
}