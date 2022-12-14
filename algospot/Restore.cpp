#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 15;
// k : �κй��ڿ��� ��
int k;
string word[MAX_N];
int cache[MAX_N][1 << MAX_N], overlap[MAX_N][MAX_N];

//�ܾ� a�ڿ� b�� �����Ҷ� �ִ� ��ĥ�� �ִ� ���� ���
void overlaping(int a, int b) {
	int len = min(word[a].size(), word[b].size());
	for (int i = len; len > 0; --i) {
		if (word[a].substr(word[a].size() - i) == word[b].substr(0, i)) {
			overlap[a][b] = i;
			return;
		}
	}
	overlap[a][b] = 0;
}

//last : �������� ������ ����
//used : ���ݱ��� ������ ����
int restore(int last, int used) {
	//����
	if (used == (1 << k) - 1) return 0;
	//�޸������̼�
	int& ret = cache[last][used];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < k; ++next) {
		if ((used & (1 << next)) == 0) {
			int cand = overlap[last][next] +
				restore(next, used | (1 << next));
			ret = max(ret, cand);
		}
	}
	return ret;
}

// ó�� ȣ�� �� last�� restore()�� �ִ��� ��ȯ�� ���� �ܾ��,
// used�� 1<<last
string reconstruct(int last, int used) {
	// ���� : ��� ������ ���������
	if (used == (1 << k) - 1) return "";
	//������ �� ���ڿ� ����ã��
	for (int next = 0; next < k; ++next) {
		//next�� �̹� ���� �����̸� ��ŵ
		if ((used & (1 << next)) != 0) continue;
		//next�� ������� ����� ���� �����ؿ� ���ٸ� next�� ����Ѵ�.
		int cand = overlap[last][next] +
			restore(next, used | (1 << next));
		if (restore(last, used) == cand) {
			return (word[next].substr(overlap[last][next]) +
				reconstruct(next, used | (1 << next)));
		}
	}
	return "@#(#@$";
}

int Restore_main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> k;
		for (int i = 0; i < k; ++i) {
			cin >> word[i];
		}
		memset(cache, -1, sizeof(cache));
		memset(overlap, -1, sizeof(overlap));
		while (true) {
			bool removed = false;
			for (int i = 0; i < k && !removed; ++i) {
				for (int j = 0; j < k; ++j) {
					if (i != j && word[i].find(word[j]) != -1) {
						word[j] = word[k - 1];
						k--;
						removed = true;
					}
				}
			}
			if (!removed) break;
		}
		word[k] = "";
		for (int a = 0; a <= k; ++a) {
			for (int b = 0; b <= k; ++b) {
				if (a != b) {
					overlaping(a, b);
				}
			}
		}
		cout << reconstruct(k, 0) << "\n";
	}
	return 0;
}