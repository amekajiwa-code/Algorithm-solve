#include <iostream>

using namespace std;

const int MOD = 10007;
int dp[1001];

int main() {
	int n;
	cin >> n;
	// 2 * n 블록의 경우의 수는 (n - 1)의 경우의 수 + (n - 2)의 경우의 수
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	cout << dp[n];
	return 0;
}