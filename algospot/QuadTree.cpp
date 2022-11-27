#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverse(string::iterator& it) {
	//읽을 헤드에 iterator를 넘기고 다음 iterator로 ++
	char head = *it;
	++it;
	if (head == 'b' || head == 'w') {
		//string으로 char 1만큼 복사
		return string(1, head);
	}
	//각 위치의 현재 색깔을 반환받음
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);
	//상하 바꾸기
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int QuadTree_main() {
	int C;
	cin >> C;
	while (C--) {
		vector<string> quadTree;
		string input;
		cin >> input;
		quadTree.push_back(input);
		auto iter = quadTree[0].begin();
		string ret = "";
		ret += reverse(iter);
		cout << ret << "\n";
	}

	return 0;
}