#include <iostream>
#include <vector>

using namespace std;

vector<int> h;

int solve(int left, int right) {
	//���� : ���ڰ� �ϳ��϶�
	if (left == right) {
		return h[left];
	}
	//��� �������� 2����
	int mid = (left + right) / 2;
	//������ �ΰ����� ����ū ���簢�� ã��
	int ret = max(solve(left, mid), solve(mid + 1, right));
	// �ΰ��� ��� ��ġ�� ������ ����ū ���簢�� ã��;
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	// mid�� mid+1�� ���簢�� ���
	ret = max(ret, height * 2);
	// �簢���� �Է� ��ü�� ���� ������ Ȯ��
	while (left < lo || hi < right) {
		//������ ���̰� ���������� ���簢�� Ȯ��
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}
		// Ȯ���� �簢���� ��
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}

int Fence_main() {
	int C;
	cin >> C;
	while (C--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			int boardH;
			cin >> boardH;
			h.push_back(boardH);
		}
		int result = solve(0, n - 1);
		cout << result << "\n";
		h.clear();
	}
	return 0;
}