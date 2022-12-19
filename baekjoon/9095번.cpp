#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int cache[11][11][11];

int solve(int one, int two, int three) {
    //����
    int sum = one + two * 2 + three * 3;
    if (sum == n) {
        return 1;
    }
    //�޸������̼�
    int& ret = cache[one][two][three];
    if (ret != -1) return ret;
    //����
    if (sum > n) return 0;
    //Ž��
    ret = 0;
    ret += solve(one + 1, two, three);
    ret += solve(one, two + 1, three);
    ret += solve(one, two, three + 1);
    return ret;
}

int main_9095(void) {
    int c;
    cin >> c;
    while (c--) {
        cin >> n;
        memset(cache, -1, sizeof(cache));
        cout << solve(0, 0, 0) << "\n";
    }
}