#include <iostream>
#include<algorithm>

using namespace std;

int dp[501][501];
int page[501];
int sum[501];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; ++i) {
            cin >> page[i];
            sum[i] = sum[i - 1] + page[i];
        }

        //dp[j][j + i] j부터 j + 1까지 합쳤을 때 최소비용
        //i : dp를 구하는 범위
        //j : dp의 시작점
        //m : 구해야 되는 범위를 나누는 기준점 (pivot)
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N - i; ++j)
            {
                dp[j][j + i] = 1e9;
                //dp[i][j] = dp[i][m] + dp[m+1][j] + sum(i~j) (i~j까지 파일 합) 일때
                //최소가 되는 m값을 찾기
                for (int m = j; m < i + j; ++m)
                {
                    dp[j][j + i] = min(dp[j][j + i],
                        dp[j][m] + dp[m + 1][j + i] + sum[j + i] - sum[j - 1]);
                }
            }
        }

        cout << dp[1][N] << "\n";
    }
}