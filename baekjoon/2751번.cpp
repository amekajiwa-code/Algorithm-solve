#include "2751번.h"
#include <iostream>
#include <algorithm>

using namespace std;

namespace solution2751 {
	void MyCode() {
		int n;
		cin >> n;
		int *array = new int[n]; // 동적 배열 할당

		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			array[i] = temp;
		}

		sort(array, array + n);
		for (int i = 0; i < n; i++) {
			cout << array[i] << " ";
		}

		delete[] array; // 배열 할당 해제
	}
}