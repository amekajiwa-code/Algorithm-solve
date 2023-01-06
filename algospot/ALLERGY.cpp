#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
// i�� ģ���� ���� �� �ִ� ������ ���� canEat
// i�� ������ ���� �� �ִ� ģ������ ���� eaters
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
		//i�� ģ���� ������ �ִ� ����,
		//i�� ������ ���� �� �ִ� ģ���� ã�Ƽ� �迭����
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