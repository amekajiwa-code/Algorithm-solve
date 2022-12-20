#include <iostream>
#include <algorithm>

using namespace std;

int dp[301];
int scores[301];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> scores[i];
	}
	dp[1] = scores[1];
	if (n >= 2) dp[2] = scores[1] + scores[2];
	//2���� ���� ��ܰ� 2ĭ ����� ���� ��� ������ ��
	for (int i = 3; i <= n; ++i) {
		dp[i] = max(dp[i - 2], dp[i - 3] + scores[i - 1]) + scores[i];
	}
	cout << dp[n];
	return 0;
}