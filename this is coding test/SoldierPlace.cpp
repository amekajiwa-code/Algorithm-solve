#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int dp[2001];
vector<int> army;

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		army.push_back(x);
	}

	reverse(army.begin(), army.end());

	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (army[j] < army[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int maxValue = 0;
	for (int i = 0; i < n; ++i) {
		maxValue = max(maxValue, dp[i]);
	}
	cout << n - maxValue << "\n";
}