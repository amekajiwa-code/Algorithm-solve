#include <iostream>

using namespace std;

int n;
int dp[500][500];
int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> dp[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int upLeft, up;
            if (j == 0) upLeft = 0;
            else upLeft = dp[i - 1][j - 1];
            if (j == i) up = 0;
            else up = dp[i - 1][j];
            dp[i][j] = dp[i][j] + max(upLeft, up);
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, dp[n - 1][i]);
    }
    cout << result << '\n';
}