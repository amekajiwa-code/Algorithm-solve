#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[5001];

int delivery(int kg) {
	//���� : 5kg����� 3kg������ �˸°� ���� ��ȯ, �ʰ��ϸ� �ſ�ū�� ��ȯ
	if (kg < 0) return 1e9;
	if (kg == 0) return 0;
	//�޸������̼�
	int& ret = cache[kg];
	if (ret != -1) return ret;
	//������ �˸°� ���� ���� +1�ؼ� ���氳���� �ø�
	return ret = min(delivery(kg - 5) + 1, delivery(kg - 3) + 1);
}

int main() {
	int n;
	cin >> n;
	memset(cache, -1, sizeof(cache));
	int result = delivery(n);
	if (result >= 1e9) cout << "-1";
	else cout << result;
	return 0;
}