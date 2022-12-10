#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[30001];

int solve(int x) {
    if (x == 1) {
        return 0;
    }
    int& ret = cache[x];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 2; i <= x; i++) {
        // 현재의 수에서 1을 빼는 경우
        ret = solve(i - 1) + 1;
        // 현재의 수가 2로 나누어 떨어지는 경우
        if (i % 2 == 0)
            ret = min(ret, solve(i / 2) + 1);
        // 현재의 수가 3으로 나누어 떨어지는 경우
        if (i % 3 == 0)
            ret = min(ret, solve(i / 3) + 1);
        // 현재의 수가 5로 나누어 떨어지는 경우
        if (i % 5 == 0)
            ret = min(ret, solve(i / 5) + 1);
    }
    return ret;
}

int makeOne_main() {
    int X;
    cin >> X;
    memset(cache, -1, sizeof(cache));
    cout << solve(X) << "\n";
    return 0;
}