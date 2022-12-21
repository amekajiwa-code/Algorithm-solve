#include <iostream>

using namespace std;

int dp[1001][1001];
string A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    int aLen = A.length();
    int bLen = B.length();
    //PreCalc
    for (int i = 1; (unsigned int)i <= aLen; ++i) {
        for (int j = 1; (unsigned int)j <= bLen; ++j) {
            // 같은 문자열이면 dp에 +1
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            //위와 왼쪽중 긴 문자열을 저장
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    //최종 대각선에서 완성된 LCS의 길이와 문자열을 출력
    int result = dp[aLen][bLen];
    cout << result << "\n";
}