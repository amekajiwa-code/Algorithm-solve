#include <iostream>
#include <unordered_map>
using namespace std;

namespace solution10816 {
    void MyCode() {
        // O(2N)
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        unordered_map<int, int> map;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            if (map.find(temp) != map.end()) {
                map.insert(make_pair(temp, ++map.at(temp)));
            }
            else {
                map.insert(make_pair(temp, 1));
            }
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int temp;
            cin >> temp;
            if (map.find(temp) != map.end()) {
                cout << map.at(temp) << " ";
            }
            else {
                cout << "0 ";
            }
        }
    }
}
