#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1001];

int main() {
	cin >> n;
	// 2��, 3��, 5�踦 ���� �ε���
	int i2 = 0, i3 = 0, i5 = 0;
	// ó���� ���� ���� �ʱ�ȭ
	int next2 = 2, next3 = 3, next5 = 5;
	dp[0] = 1;

	//�ε��� 1���� n���� ���鼭 ��������� ��� 2,3,5�� ���Ž�Ű�鼭
	//���� ��������� ����
	for (int i = 1; i < n; ++i) {
		dp[i] = min(next2, min(next3, next5));
		if (dp[i] == next2) {
			++i2;
			next2 = dp[i2] * 2;
		}
		if (dp[i] == next3) {
			++i3;
			next3 = dp[i3] * 3;
		}
		if (dp[i] == next5) {
			++i5;
			next5 = dp[i5] * 5;
		}
	}

	cout << dp[n - 1] << "\n";
}