#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
// i번 친구가 먹을 수 있는 음식의 집합 canEat
// i번 음식을 먹을 수 있는 친구들의 집합 eaters
vector<int> canEat[50], eaters[50];
int best;

void search(vector<int>& edible, int chosen) {
	if (chosen >= best) return;
	int first = 0;
	while (first < n && edible[first] > 0) ++first;
	if (first == n) {
		best = chosen;
		return;
	}
	for (int i = 0; i < canEat[first].size(); ++i) {
		int food = canEat[first][i];
		for (int j = 0; j < eaters[food].size(); ++j) {
			edible[eaters[food][j]]++;
		}
		search(edible, chosen + 1);
		for (int j = 0; j < eaters[food].size(); ++j) {
			edible[eaters[food][j]]--;
		}
	}
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			canEat[i].clear();
		}
		for (int i = 0; i < m; ++i) {
			eaters[i].clear();
		}
		unordered_map<string, int> freinds;
		for (int i = 0; i < n; ++i) {
			string str;
			cin >> str;
			freinds.insert(make_pair(str, i));
		}
		//i번 친구가 먹을수 있는 음식,
		//i번 음식을 먹을 수 있는 친구를 찾아서 배열수정
		for (int i = 0; i < m; ++i) {
			int canEatNum;
			cin >> canEatNum;
			for (int j = 0; j < canEatNum; ++j) {
				string str;
				cin >> str;
				canEat[freinds.at(str)].push_back(i);
				eaters[i].push_back(freinds.at(str));
			}
		}
		vector<int> edible(n, 0);
		best = 987654321;
		search(edible, 0);
		cout << best << "\n";
	}
	return 0;
}