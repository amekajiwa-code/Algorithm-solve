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
        // ������ ������ 1�� ���� ���
        ret = solve(i - 1) + 1;
        // ������ ���� 2�� ������ �������� ���
        if (i % 2 == 0)
            ret = min(ret, solve(i / 2) + 1);
        // ������ ���� 3���� ������ �������� ���
        if (i % 3 == 0)
            ret = min(ret, solve(i / 3) + 1);
        // ������ ���� 5�� ������ �������� ���
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