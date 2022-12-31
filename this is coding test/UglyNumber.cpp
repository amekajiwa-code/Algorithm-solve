#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1001];

int main() {
	cin >> n;
	// 2배, 3배, 5배를 위한 인덱스
	int i2 = 0, i3 = 0, i5 = 0;
	// 처음에 곱셈 값을 초기화
	int next2 = 2, next3 = 3, next5 = 5;
	dp[0] = 1;

	//인덱스 1부터 n까지 돌면서 못생긴수의 배수 2,3,5를 갱신시키면서
	//다음 못생긴수를 구함
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