#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
// ���簡��, digits: e�� �ڸ������� ������ ��
string curPrice, digits;
//n : ���� ������ �ڸ������� m : ������ ��� ������ ���
int n, m;
int cache[1 << 14][20][2];
// index : �̹��� ä�� �ڸ��� index, taken : ���ݱ��� ����� �ڸ������� ����
// mod : ���ݱ��� ���� ������ m�� ���� ������, less : ���ݱ��� ���� ������ �̹� e���� ������ 1 �ƴϸ� 0
int price(int index, int taken, int mod, int less) {
	//����
	if (index == n) {
		return (less && mod == 0) ? 1 : 0;
	}
	//�޸������̼�
	int& ret = cache[taken][mod][less];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < n; ++next) {
		if ((taken & (1 << next)) == 0) {
			// ���� ������ �� ���ݺ��� �׻� �۴�
			if (!less && curPrice[index] < digits[next]) {
				continue;
			}
			// ���� ���ڴ� �ѹ��� �����Ѵ�.
			if (next > 0 && digits[next - 1] == digits[next] &&
				(taken & (1 << (next - 1))) == 0) {
				continue;
			}
			int nextTaken = taken | (1 << next);
			int nextMod = (mod * 10 + digits[next] - '0') % m;
			int nextLess = less || curPrice[index] > digits[next];
			ret += price(index + 1, nextTaken, nextMod, nextLess);
			ret %= MOD;
		}
	}
	return ret;
}

int ZIM_main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> curPrice >> m;
		n = curPrice.size();
		digits = curPrice;
		sort(digits.begin(), digits.end());
		memset(cache, -1, sizeof(cache));
		cout << price(0, 0, 0, 0) << "\n";
	}
	return 0;
}