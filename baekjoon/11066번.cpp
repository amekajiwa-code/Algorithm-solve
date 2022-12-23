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

        //dp[j][j + i] j���� j + 1���� ������ �� �ּҺ��
        //i : dp�� ���ϴ� ����
        //j : dp�� ������
        //m : ���ؾ� �Ǵ� ������ ������ ������ (pivot)
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N - i; ++j)
            {
                dp[j][j + i] = 1e9;
                //dp[i][j] = dp[i][m] + dp[m+1][j] + sum(i~j) (i~j���� ���� ��) �϶�
                //�ּҰ� �Ǵ� m���� ã��
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