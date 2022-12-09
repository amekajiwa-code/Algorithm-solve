//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int BigNum = 1000000007;
//
//int cache[101];
//int tiling(int width) {
//	//���� : �ʺ� 1�϶�
//	if (width <= 1) return 1;
//	//�޸������̼�
//	int& ret = cache[width];
//	if (ret != -1) return ret;
//	return ret = (tiling(width - 2) + tiling(width - 1)) % BigNum;
//}
//
//// 2 * n �簢���� ���Ī���� ä��� ����� ��
//int asymmetric(int width) {
//	//�ʺ� Ȧ���� ��
//	if (width % 2 == 1) {
//		return (tiling(width) - tiling(width / 2) + BigNum) % BigNum;
//	}
//	// �簢���� ä��� ��� ����� ������ ��Ī�θ�ŭ ����
//	int ret = tiling(width);
//	ret = (ret - tiling(width / 2) + BigNum) % BigNum;
//	ret = (ret - tiling(width / 2 - 1) + BigNum) % BigNum;
//	return ret;
//}
//
//int Asym_main() {
//	int C;
//	cin >> C;
//	while (C--) {
//		int width;
//		cin >> width;
//		memset(cache, -1, sizeof(cache));
//		int result = asymmetric(width);
//		cout << result << "\n";
//	}
//	return 0;
//}