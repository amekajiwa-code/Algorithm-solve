#include <iostream>
#include <queue>
using namespace std;

namespace solution2164 {
    void MyCode() {
        int n;
        cin >> n;
        queue<int> queue;

        for (int i = 1; i <= n; ++i) queue.push(i);

        while (queue.size() != 1) {
            queue.pop();
            queue.push(queue.front());
            queue.pop();
        }

        cout << queue.front();
    }
}
