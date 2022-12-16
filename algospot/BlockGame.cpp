#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

vector<int> moves;
inline int cell(int y, int x) {
	return 1 << (y * 5 + x);
}
//게임판에 놓을 수 있는 블록들의 위치를 미리 계산
void precalc() {
	// 세칸 L자 블록 계산
	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {
			vector<int> cells;
			for (int dy = 0; dy < 2; ++dy) {
				for (int dx = 0; dx < 2; ++dx) {
					cells.push_back(cell(y + dy, x + dx));
				}
			}
			int square = cells[0] + cells[1] + cells[2] + cells[3];
			for (int i = 0; i < 4; ++i) {
				moves.push_back(square - cells[i]);
			}
		}
	}
	// 두칸 일자 블록 계산
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 4; ++j) {
			moves.push_back(cell(i, j) + cell(i, j + 1));
			moves.push_back(cell(j, i) + cell(j + 1, i));
		}
	}
}

char cache[1 << 25];
// 현재 게임판 상태가 board일 때 현재 차례인 사람이 승리할지 아닐지 여부를 반환
char play(int board) {
	//메모이제이션
	char& ret = cache[board];
	if (ret != -1) return ret;
	ret = 0;
	//모든 수를 고려
	for (int i = 0; i < moves.size(); ++i) {
		// 이 수를 이 게임판에 놓을 수 있는가 확인
		if ((moves[i] & board) == 0) {
			if (!play(board | moves[i])) {
				ret = 1;
				break;
			}
		}
	}
	return ret;
}

int blockgame_main() {
	int C;
	cin >> C;
	precalc();
	while (C--) {
		//비트를 보드처럼 사용
		int board = 0;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				char input;
				cin >> input;
				if (input == '#') {
					board |= cell(i, j);
				}
			}
		}
		memset(cache, -1, sizeof(cache));
		char result = play(board);
		if (result == 1) {
			cout << "WINNING" << "\n";
		}
		else if (result == 0) {
			cout << "LOSING" << "\n";
		}

	}
	return 0;
}