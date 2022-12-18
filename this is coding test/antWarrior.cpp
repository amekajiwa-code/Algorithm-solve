#include <iostream>
#include <vector>

using namespace std;

int n;
int cache[100];
vector<int> arr;

//╧ыер╬В ╧Ф╫д
void solve() {
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cache[0] = arr[0];
    cache[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        cache[i] = max(cache[i - 1], cache[i - 2] + arr[i]);
    }
}

int antwarrior_main(void) {
    cin >> n;
    solve();
    cout << cache[n - 1] << '\n';
}