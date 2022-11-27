#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverse(string::iterator& it) {
	//���� ��忡 iterator�� �ѱ�� ���� iterator�� ++
	char head = *it;
	++it;
	if (head == 'b' || head == 'w') {
		//string���� char 1��ŭ ����
		return string(1, head);
	}
	//�� ��ġ�� ���� ������ ��ȯ����
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);
	//���� �ٲٱ�
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