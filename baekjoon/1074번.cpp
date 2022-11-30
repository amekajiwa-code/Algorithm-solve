#include <iostream>

using namespace std;

int r, c;

int visit(int row, int col, int start, int size) {
	//(r, c)가 찾으려는 범위에 있을때만 넘어감
	if (row > r || col > c || r >= row + size || c >= col + size) {
		return -1;
	}
	if (row == r && col == c) {
		return start;
	}

	int ret = 0;
	int nSize = size / 2;
	// 다음 사분면의 시작점은 현재 start에 nSize * nSize를 더한값
	int nStart = nSize * nSize;
	//왼쪽위
	ret = max(ret, visit(row, col, start, nSize));
	//오른쪽위
	ret = max(ret, visit(row, col + nSize, start + (nStart * 1), nSize));
	//왼쪽아래
	ret = max(ret, visit(row + nSize, col, start + (nStart * 2), nSize));
	//오른쪽아래
	ret = max(ret, visit(row + nSize, col + nSize, start + (nStart * 3), nSize));
	return ret;
}

int main1074() {
	int N;
	cin >> N >> r >> c;
	int result = visit(0, 0, 0, 1 << N);
	cout << result << "\n";
	return 0;
}