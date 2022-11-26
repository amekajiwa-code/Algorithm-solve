#include <iostream>

using namespace std;

int H, W;

// 보드 덮는 모양 상대좌표
const int coverType[4][3][2] = {
		{ {0, 0}, {1, 0}, {0, 1} }, // ㄱ 좌우반전
		{ {0, 0}, {0, 1}, {1, 1} }, // ㄱ
		{ {0, 0}, {1, 0}, {1, 1} }, // ㄴ
		{ {0, 0}, {1, 0}, {1, -1} } // ㄴ 좌우반전
};

//보드판 채우기 or 비우기
bool set(int board[][20], int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; ++i) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= H ||
			nx < 0 || nx >= W) {
			ok = false;
		}
		else if ((board[ny][nx] += delta) > 1) {
			ok = false;
		}
	}
	return ok;
}

//보드판을 덮을 수 있는 경우의 수 찾기
int BoardCover(int board[][20]) {
	//맨처음 채울 기준칸 찾기
	int y = -1;
	int x = -1;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) {
			break;
		}
	}
	//기저
	if (y == -1) {
		return 1;
	}
	int ret = 0;
	//4가지 모양중에 덮을수 있을때 재귀함수 호출
	for (int type = 0; type < 4; ++type) {
		if (set(board, y, x, type, 1)) {
			ret += BoardCover(board);
		}
		set(board, y, x, type, -1);
	}
	return ret;
}

int BoardCover_main() {
	// 검은칸,덮인칸 : 1 , 빈칸 : 0
	int board[20][20];
	int c;
	cin >> c;
	while (c--) {
		int white = 0;
		cin >> H >> W;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				char color;
				cin >> color;
				if (color == '#') {
					board[i][j] = 1;
				}
				else {
					board[i][j] = 0;
					++white;
				}
			}
		}
		//빈칸이 3의 배수가 아니라면 0 출력
		if (white % 3 != 0) {
			cout << "0\n";
		}
		else {
			cout << BoardCover(board) << "\n";
		}
	}


	return 0;
}