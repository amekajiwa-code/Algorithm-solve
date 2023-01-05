#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int boardH, boardW, blockH, blockW;
vector<string> board;
int covered[10][10];
int best;
//����� ȸ���� ���¸� ��� ��ǥ�� ������� �����ϴ� �迭
vector<vector<pair<int, int>>> rotations;
int blockSize;

bool set(int y, int x, const vector<pair<int, int>>& block, int delta) {
	int ret = true;
	for (int i = 0; i < block.size(); ++i) {
		int ny = y + block[i].first;
		int nx = x + block[i].second;
		if (ny < 0 || ny >= boardH || nx < 0 || nx >= boardW)
			ret = false;
		else if ((covered[ny][nx] += delta) > 1)
			ret = false;
	}
	return ret;
}

bool pruning(int placed) {
	int emptys = 0;
	for (int i = 0; i < boardH; i++)
		for (int j = 0; j < boardW; j++) {
			if (covered[i][j] == 0)
				emptys++;
		}
	return (emptys / blockSize) + placed <= best ? true : false;
}

void search(int placed) {
	//����ġ��
	if (pruning(placed))return;
	int y = -1, x = -1;
	for (int i = 0; i < boardH; ++i) {
		for (int j = 0; j < boardW; ++j) {
			if (covered[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	//����
	if (y == -1) {
		best = max(best, placed);
		return;
	}
	// �� ĭ�� ���´�
	for (int i = 0; i < rotations.size(); ++i) {
		if (set(y, x, rotations[i], 1)) {
			search(placed + 1);
		}
		set(y, x, rotations[i], -1);
	}
	// �� ĭ�� ���´�
	covered[y][x] = 1;
	search(placed);
	covered[y][x] = 0;
}

int solve() {
	best = 0;
	for (int i = 0; i < boardH; ++i) {
		for (int j = 0; j < boardW; ++j) {
			covered[i][j] = (board[i][j] == '#' ? 1 : 0);
		}
	}
	search(0);
	return best;
}

// 2���� �迭 arr �ð���� 90�� ȸ���ؼ� ��ȯ
vector<string> rotate(const vector<string>& arr) {
	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[0].size(); ++j) {
			ret[j][arr.size() - i - 1] = arr[i][j];
		}
	}
	return ret;
}

// block�� �װ��� ȸ�� ���¸� ������ ��� ��ǥ�� ������� ��ȯ
void generateRotations(vector<string> block) {
	rotations.clear();
	rotations.resize(4);
	for (int rot = 0; rot < 4; ++rot) {
		int originY = -1, originX = -1;
		for (int i = 0; i < block.size(); ++i) {
			for (int j = 0; j < block[i].size(); ++j) {
				if (block[i][j] == '#') {
					if (originY == -1) {
						originY = i;
						originX = j;
					}
					rotations[rot].push_back(make_pair(i - originY, j - originX));
				}
			}
		}
		block = rotate(block);
	}
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	blockSize = rotations[0].size();
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		board.clear();
		vector<string> block;
		cin >> boardH >> boardW >> blockH >> blockW;
		for (int i = 0; i < boardH; ++i) {
			string temp;
			cin >> temp;
			board.push_back(temp);
		}
		for (int i = 0; i < blockH; ++i) {
			string temp;
			cin >> temp;
			block.push_back(temp);
		}
		generateRotations(block);
		cout << solve() << "\n";
	}
	return 0;
}