#include <iostream>

using namespace std;

int r, c;

int visit(int row, int col, int start, int size) {
	//(r, c)�� ã������ ������ �������� �Ѿ
	if (row > r || col > c || r >= row + size || c >= col + size) {
		return -1;
	}
	if (row == r && col == c) {
		return start;
	}

	int ret = 0;
	int nSize = size / 2;
	// ���� ��и��� �������� ���� start�� nSize * nSize�� ���Ѱ�
	int nStart = nSize * nSize;
	//������
	ret = max(ret, visit(row, col, start, nSize));
	//��������
	ret = max(ret, visit(row, col + nSize, start + (nStart * 1), nSize));
	//���ʾƷ�
	ret = max(ret, visit(row + nSize, col, start + (nStart * 2), nSize));
	//�����ʾƷ�
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