#include "1920번.h"
#include <iostream>
#include <algorithm>

using namespace std;

namespace solution1920 {
	int binarySearch(int array[], int n, int target) {
		//이진탐색
		int start = 0;
		int end = n - 1;
		bool isFinished = false;

		while (start <= end) {
			int mid = (start + end) / 2;

			if (target == array[mid]) {
				isFinished = true;
				return 1;
			}
			else if (target < array[mid]) {
				end = mid - 1;
			}
			else if (target > array[mid]) {
				start = mid + 1;
			}
		}

		if (isFinished == false) {
			return 0;
		}
	}

	void MyCode() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		int n;
		cin >> n;
		int* array = new int[n]; // 동적 배열 할당

		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			array[i] = temp;
		}

		sort(array, array + n);

		int m;
		cin >> m;

		for (int i = 0; i < m; i++) {
			int target;
			cin >> target;
			if (binarySearch(array, n, target)) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
			
		}

		delete[] array; // 배열 할당 해제
	}
}