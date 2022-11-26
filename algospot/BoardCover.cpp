#include <iostream>

using namespace std;

int H, W;

// ���� ���� ��� �����ǥ
const int coverType[4][3][2] = {
		{ {0, 0}, {1, 0}, {0, 1} }, // �� �¿����
		{ {0, 0}, {0, 1}, {1, 1} }, // ��
		{ {0, 0}, {1, 0}, {1, 1} }, // ��
		{ {0, 0}, {1, 0}, {1, -1} } // �� �¿����
};

//������ ä��� or ����
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

//�������� ���� �� �ִ� ����� �� ã��
int BoardCover(int board[][20]) {
	//��ó�� ä�� ����ĭ ã��
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
	//����
	if (y == -1) {
		return 1;
	}
	int ret = 0;
	//4���� ����߿� ������ ������ ����Լ� ȣ��
	for (int type = 0; type < 4; ++type) {
		if (set(board, y, x, type, 1)) {
			ret += BoardCover(board);
		}
		set(board, y, x, type, -1);
	}
	return ret;
}

int BoardCover_main() {
	// ����ĭ,����ĭ : 1 , ��ĭ : 0
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
		//��ĭ�� 3�� ����� �ƴ϶�� 0 ���
		if (white % 3 != 0) {
			cout << "0\n";
		}
		else {
			cout << BoardCover(board) << "\n";
		}
	}


	return 0;
}