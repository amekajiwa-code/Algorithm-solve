#include <iostream>
#include<algorithm>

using namespace std;

int dp[21];
int mine[21][21];
int t, n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> mine[i][j];
            }
        }

        for (int row = 1; row <= n; ++row) {
            for (int col = 1; col <= m; ++col) {
                dp[col] = mine[row][col];
                if (row != 1) {
                    dp[col] = max(mine[row - 1][col], dp[col]);
                }
                if (row < n) {
                    dp[col + 1] = max(mine[row + 1][col], dp[col]);
                }
                dp[col] += dp[col - 1];
            }
        }

        cout << dp[m] << "\n";
    }
}