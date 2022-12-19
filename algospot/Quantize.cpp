#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int n;

// ����ȭ �� ����(���ĵ�), A�� �κ����� �����Ұ�, A������ �κ����� ������ ��
int A[101], pSum[101], pSqSum[101];

//������� : A�����ϰ� �κ��� ���
void precalc() {
	sort(A, A + n);
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];
	for (int i = 1; i < n; ++i) {
		pSum[i] = pSum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	}
}

// A������ ������ ���ڷ� ǥ���Ҷ��� �ּҿ����� ���
int minError(int lo, int hi) {
	//�κ����� �̿��� A���� ������ �� ���ϱ�
	//hi���� ��o - 1 �� ���� ������ ���� �ȴ�.
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);
	//����� �ݿø��� ������ ������ ǥ��
	int m = int(0.5 + (double)sum / (hi - lo + 1));
	int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
	return ret;
}

int cache[101][11];
int quantize(int from, int parts) {
	//���� : ��� ���ڸ� �� ����ȭ������
	if (from == n) return 0;
	//���� : ���ڰ� �������� ����ȭ �Ҽ� ������ ���� ū �� ��ȯ
	if (parts == 0) return INF;
	//�޸������̼�
	int& ret = cache[from][parts];
	if (ret != -1) return ret;
	ret = INF;
	// ������ ���̸� ��ȭ���� ���� �ּ�ġ ã��
	for (int partSize = 1; from + partSize <= n; ++partSize) {
		ret = min(ret, minError(from, from + partSize - 1)
			+ quantize(from + partSize, parts - 1));
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int s;
		cin >> n >> s;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; ++i) {
			cin >> A[i];
		}
		precalc();
		cout << quantize(0, s) << "\n";
	}
	return 0;
}