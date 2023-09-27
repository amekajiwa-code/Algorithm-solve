#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_RANGE = 10000000;
vector<int> divisorCounts(MAX_RANGE + 1, 0);

void precalculateDivisorCounts() {
    for (int i = 1; i <= MAX_RANGE; ++i) {
        for (int j = i; j <= MAX_RANGE; j += i) {
            divisorCounts[j]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precalculateDivisorCounts();

    int c;
    cin >> c;
    while (c--) {
        int n, lo, hi;
        cin >> n >> lo >> hi;
        int result = 0;

        for (int i = lo; i <= hi; ++i) {
            if (n == divisorCounts[i]) {
                ++result;
            }
        }

        cout << result << endl;
    }

    return 0;
}

/* �̸� ��� ������ ����ؼ� ���� ���� ��� ���ڿ� ����
����� ������ �̸� ����Ͽ� ������ �д�.
�̷��� �ϸ� �� ���ڿ� ���� ��� ������ �ٽ� ������� 
�ʾƵ� �ǹǷ� ��� �ð��� ũ�� �����ų �� �ִ�. */