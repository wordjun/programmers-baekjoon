#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	int M = 0, num = 0;
	string comm = "";
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> comm;
		if (comm == "add") {
			cin >> num;

		}
		else if (comm == "remove") {

		}
		else if (comm == "check") {

		}
		else if (comm == "toggle") {

		}
		else if (comm == "all") {

		}
		else if (comm == "empty") {

		}
	}
	return 0;
}