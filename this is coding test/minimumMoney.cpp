#include <iostream>
#include<algorithm>

using namespace std;

int dp[10001];
int moneys[101];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> moneys[i];
    }

    for (int i = 1; i <= m; ++i) {
        dp[i] = 10001;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = moneys[i]; j <= m; ++j) {
            if (dp[j - moneys[i]] != 10001) {
                dp[j] = min(dp[j], dp[j - moneys[i]] + 1);
            }
        }
    }

    if (dp[m] == 10001) {
        cout << -1 << "\n";
    }
    else {
        cout << dp[m] << "\n";
    }
}