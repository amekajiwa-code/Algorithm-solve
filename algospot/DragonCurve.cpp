//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <cassert>
//
//using namespace std;
//
//const int MAX = 1000000000 + 1;
//int length[51];
//
//void precalc() {
//	length[0] = 1;
//	for (int i = 1; i <= 50; ++i) {
//		length[i] = min(MAX, length[i - 1] * 2 + 2);
//	}
//}
//
//const string EXPAND_X = "X+YF";
//const string EXPAND_Y = "FX-Y";
//
//char expand(const string& dragonCurve, int generations, int skip) {
//	//����
//	if (generations == 0) {
//		assert(skip < dragonCurve.size());
//		return dragonCurve[skip];
//	}
//
//	for (int i = 0; i < dragonCurve.size(); ++i) {
//		//���ڿ��� Ȯ��ɶ�
//		if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
//			if (skip >= length[generations]) {
//				skip -= length[generations];
//			}
//			else if (dragonCurve[i] == 'X') {
//				return expand(EXPAND_X, generations - 1, skip);
//			}
//			else {
//				return expand(EXPAND_Y, generations - 1, skip);
//			}
//		}
//		//Ȯ����� ������ ��ŵ�Ҷ�
//		else if (skip > 0) {
//			--skip;
//		}
//		//���� ã������
//		else {
//			return dragonCurve[i];
//		}
//	}
//	return '#'; // ���� ������ ������� �ʴ´�.
//}
//
//int main() {
//	int C;
//	cin >> C;
//	precalc();
//	while (C--) {
//		int generation, p, l;
//		cin >> generation >> p >> l;
//		for (int i = p - 1; i < p + l - 1; ++i) {
//			cout << expand("FX", generation, i);
//		}
//		cout << "\n";
//	}
//	return 0;
//}