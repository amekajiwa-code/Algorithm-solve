#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int isSame(const vector <vector<int>>* quadTree, int curLen, int startX, int startY) {
	int first = quadTree[0][startX][startY];

	//if (curLen == 1) {
	//	return first;
	//}

	for (int i = startX; i < startX + curLen; ++i) {
		for (int j = startY; j < startY + curLen; ++j) {
			if (first != quadTree[0][i][j]) {
				return -1;
			}
		}
	}
	return first;
}

string DivisionTreeRecursive(const vector<vector<int>>* quadTree, int curLen, int startX, int startY) {
	if (startX > quadTree->size() || startY > quadTree->size()) {
		return "";
	}

	string result = "";
	int sameNum = isSame(quadTree, curLen, startX, startY);
	if (sameNum == 0 || sameNum == 1) {
		char move = sameNum;
		result += move + 48;
	}
	else if (sameNum == -1) {
		result += "(";
		int inputLen = curLen / 2;
		result += DivisionTreeRecursive(quadTree, inputLen, startX, startY);
		result += DivisionTreeRecursive(quadTree, inputLen, startX, startY + inputLen);
		result += DivisionTreeRecursive(quadTree, inputLen, startX + inputLen, startY);
		result += DivisionTreeRecursive(quadTree, inputLen, startX + inputLen, startY + inputLen);
		result += ")";
	}

	return result;
}

string DivisionTree(const vector<vector<int>>* quadTree, int curLen) {
	string output = "";
	output += DivisionTreeRecursive(quadTree, curLen, 0, 0);
	return output;
}

//2차원 벡터로 해결
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<vector<int>>* quadTree = new vector<vector <int>>;
	int N;
	cin >> N;
	while (N--) {
		string input;
		cin >> input;
		vector<int> tempVec;
		for (char c : input) {
			tempVec.push_back(c - 48);
		}
		quadTree->push_back(tempVec);
	}

	string printText = DivisionTree(quadTree, quadTree->size());

	cout << printText;

	delete quadTree;
}
