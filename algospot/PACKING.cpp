#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, capacity;
string itemsName[100];
vector<pair <int, int>> itemsFigure(100);
int cache[1001][100];

int pack(int capacity, int item) {
	// 기저 : 모든 물건을 다 탐색했을때
	if (item == N) return 0;
	//메모이제이션
	int& ret = cache[capacity][item];
	if (ret != -1) return ret;
	// 이 물건을 담지 않을 경우
	ret = pack(capacity, item + 1);
	// 이 물건을 담을 경우
	if (capacity >= itemsFigure[item].first) {
		ret = max(ret, pack(capacity - itemsFigure[item].first, item + 1)
			+ itemsFigure[item].second);
	}
	return ret;
}

void reconstruct(int capacity, int item,
	vector<string>& picked) {
	//기저 : 모든 물건을 다 탐색했을때
	if (item == N) return;
	if (pack(capacity, item) == pack(capacity, item + 1)) {
		reconstruct(capacity, item + 1, picked);
	}
	else {
		picked.push_back(itemsName[item]);
		reconstruct(capacity - itemsFigure[item].first, item + 1, picked);
	}
}

int packing_main() {
	int C;
	cin >> C;
	while (C--) {
		memset(cache, -1, sizeof(cache));
		cin >> N >> capacity;
		for (int i = 0; i < N; ++i) {
			int capacity, priority;
			cin >> itemsName[i] >> capacity >> priority;
			itemsFigure[i] = make_pair(capacity, priority);
		}
		int maxPackege = pack(capacity, 0);
		vector<string> pickItems;
		reconstruct(capacity, 0, pickItems);
		cout << maxPackege << " " << pickItems.size() << "\n";
		for (int i = 0; i < pickItems.size(); ++i) {
			cout << pickItems[i] << "\n";
		}
	}
	return 0;
}