#include <iostream>

using namespace std;

long long dp[101];

int main() {
	int n;
	cin >> n;
	//피보나치 n = (n-1) + n(n-2)
	//90까지의 피보나치 수열은 매우 크기 때문에 long long 사용
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
	return 0;
}