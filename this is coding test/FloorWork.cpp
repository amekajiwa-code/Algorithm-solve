#include <iostream>

using namespace std;

const int MOD = 796796;
int d[1001];
int n;

int main(void) { // ╧ыер╬В╧Ф╫д
    cin >> n;
    d[1] = 1;
    d[2] = 3;
    for (int i = 3; i <= n; i++) {
        d[i] = (d[i - 1] + 2 * d[i - 2]) % MOD;
    }
    cout << d[n] << '\n';
}