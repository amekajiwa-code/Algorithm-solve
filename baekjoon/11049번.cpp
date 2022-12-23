#include <iostream>
#include<algorithm>

using namespace std;

int dp[501][501];
int matrix[501][2];
int sum[501];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int row;
        int col;
        cin >> row >> col;
        matrix[i][0] = row;
        matrix[i][1] = col;
    }

    // 11066번 파일합치기 알고리즘과 유사
    for (int i = 1; i < N; i++) {
        for (int j = 1; i + j <= N; j++) {
            dp[j][i + j] = 1e9;
            for (int k = j; k <= i + j; k++) {
                //k를 기준으로 왼쪽값과 오른쪽의 행렬의 곱값이 최소인것을 선택
                dp[j][i + j] = min(dp[j][i + j],
                    dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
            }
        }

    }

    cout << dp[1][N];
}