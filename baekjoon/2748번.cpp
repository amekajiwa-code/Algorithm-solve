#include <iostream>

using namespace std;

long long dp[101];

int main() {
	int n;
	cin >> n;
	//�Ǻ���ġ n = (n-1) + n(n-2)
	//90������ �Ǻ���ġ ������ �ſ� ũ�� ������ long long ���
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
	return 0;
}