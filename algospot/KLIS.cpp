#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 2000000000 + 1;
int n;
int cacheLen[501], cacheCnt[501], S[500];

// S[start]���� �����ϴ� ���� �κ� ���� �� �ִ� ���̸� ��ȯ�Ѵ�.
int LIS(int start) {
	//�޸������̼�
	int& ret = cacheLen[start + 1];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < n; ++next) {
		if (start == -1 || S[start] < S[next]) {
			ret = max(ret, LIS(next) + 1);
		}
	}
	return ret;
}

// S[start]���� �����ϴ� �ִ� ���� �κ� ������ ���� ��ȯ�Ѵ�.
int count(int start) {
	//���� : LIS ���̰� 1�϶�
	if (LIS(start) == 1) return 1;
	//�޸������̼�
	int& ret = cacheCnt[start + 1];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = start + 1; next < n; ++next) {
		if ((start == -1 || S[start] < S[next]) &&
			LIS(start) == LIS(next) + 1)
			ret = min<long long>(MAX, (long long)ret + count(next));
	}
	return ret;
}

void reconstruct(int start, int skip, vector<int>& lis) {
	// 1. S[start]�� �׻� LIS�� ���Եȴ�.
	if (start != -1) lis.push_back(S[start]);
	// 2. �ڿ� �ü��ִ� ���ڵ�� ��ġ�� ����� �����.
	// (����, ������ ��ġ)�� ����� �ȴ�.
	vector<pair <int, int>> followers;
	for (int next = start + 1; next < n; ++next) {
		if ((start == -1 || S[start] < S[next]) &&
			LIS(start) == LIS(next) + 1) {
			followers.push_back(make_pair(S[next], next));
		}
		sort(followers.begin(), followers.end());
	}
	// 3. k��° LIS�� ���� ���ڸ� ã�´�.
	for (int i = 0; i < followers.size(); ++i) {
		//�� ���ڸ� �ڿ� �̾ ���� �� �ִ� LIS�� ������ ����.
		int idx = followers[i].second;
		int cnt = count(idx);
		if (cnt <= skip) {
			skip -= cnt;
		}
		else {
			reconstruct(idx, skip, lis);
			break;
		}
	}
}

int KLIS_main() {
	int C;
	cin >> C;
	while (C--) {
		int k;
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			cin >> S[i];
		}
		memset(cacheLen, -1, sizeof(cacheLen));
		memset(cacheCnt, -1, sizeof(cacheCnt));
		int lisRet = LIS(-1) - 1;
		vector<int> myLis;
		reconstruct(-1, k - 1, myLis);
		cout << lisRet << "\n";
		for (int i = 0; i < myLis.size(); ++i) {
			cout << myLis[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}