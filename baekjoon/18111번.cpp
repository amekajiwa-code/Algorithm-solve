#include <iostream>

using namespace std;

namespace solution18111 {
	void MyCode() {
		int col = 0;
		int row = 0;
		int inventory = 0;
		int mostTime = 1e9;
		int mostFloor = -1;
		cin >> col >> row >> inventory;
		int ground[500][500]; // 너무 많은 스택을 사용해서 경고

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				cin >> ground[i][j];
			}
		}

		for (int h = 0; h <= 256; ++h) {
			int build = 0;
			int remove = 0;
			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < col; ++j) {
					int removeFloor = ground[i][j] - h;
					if (removeFloor < 0) {
						build -= removeFloor;
					}
					else {
						remove += removeFloor;
					}
				}
			}
			if (remove + inventory >= build) {
				int time = 2 * remove + build;
				if (mostTime >= time) {
					mostTime = time;
					mostFloor = h;
				}
			}
		}
		cout << mostTime << " " << mostFloor;
	}
}