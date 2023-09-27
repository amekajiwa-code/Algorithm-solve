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

/* 미리 약수 개수를 계산해서 범위 내의 모든 숫자에 대해
약수의 개수를 미리 계산하여 저장해 둔다.
이렇게 하면 각 숫자에 대한 약수 개수를 다시 계산하지 
않아도 되므로 계산 시간을 크게 단축시킬 수 있다. */