#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int dp[15000001];
vector<pair<int, int>> table;

int main() { // 탑바텀 방식
	cin >> n;
	table.push_back(make_pair(0, 0)); // 0일을 제외하기 위해서 더미 삽입
	for (int i = 0; i < n; ++i) {
		int time, pay;
		cin >> time >> pay;
		table.push_back(make_pair(time, pay));
	}

	for (int today = n; today >= 1; --today) {
		int day = table[today].first;
		int profit = table[today].second;
		if (today + day > n + 1) {
			dp[today] = dp[today + 1];
		}
		else {
			dp[today] = max(dp[today + 1], profit + dp[today + day]);
		}
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ret = max(ret, dp[i]);
	}
	cout << ret;
}