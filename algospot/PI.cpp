/*#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

const int INF = 987654321;
string N;

//���� ������ ���̵��� �Ǻ�
int classify(int a, int b) {
	//�ε���a���� b - a + 1������ ���ڿ� ��������
	string M = N.substr(a, b - a + 1);
	//���ڿ��� ��� ������ ���̵� 1
	if (M == string(M.size(), M[0])) return 1;
	//���ڰ� ������������ Ȯ��
	bool progressive = true;
	for (int i = 0; i < M.size() - 1; ++i) {
		if (M[i + 1] - M[i] != M[1] - M[0]) {
			progressive = false;
		}
	}
	//���������̸鼭 1�� �����ϸ� ���̵� 2
	if (progressive && abs(M[1] - M[0]) == 1) {
		return 2;
	}
	//�μ��� 1212ó�� �����Ƴ������� Ȯ��
	bool alternating = true;
	for (int i = 0; i < M.size(); ++i) {
		if (M[i] != M[i % 2]) {
			alternating = false;
		}
	}
	//�μ��� ������ ���ö� ���̵� 4
	if (alternating) {
		return 4;
	}
	//1���� ũ�� �����ϴ� ���������϶� ���̵� 5
	if (progressive) {
		return 5;
	}
	//�ƹ��͵� �ش���� ������ ���̵� 10
	return 10;
}

int cache[10002];
//3,5�� ��� �д� ����� �ּ� ���̵��� ���ϱ�
int memorize(int begin) {
	//���� : ������ �о�����
	if (begin == N.size()) return 0;
	//�޸������̼� : ĳ�ÿ� �����Ͱ� ������
	int& ret = cache[begin];
	if (ret != -1) return ret;
	//��������
	ret = INF;
	//���̰� 3, 4, 5�϶��� ����
	for (int L = 3; L <= 5; ++L) {
		if (begin + L <= N.size()) {
			ret = min(ret, memorize(begin + L) + classify(begin, begin + L - 1));
		}
	}
	return ret;
}



int PI_main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> N;
		memset(cache, -1, sizeof(cache));
		cout << memorize(0) << "\n";
	}
	return 0;
}*/