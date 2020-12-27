#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main() {
	vector<pair<int, int>>coord;
	int N = 0, x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		coord.push_back({ x, y });
	}
	sort(coord.begin(), coord.end(), comp);
	for (auto& i : coord)
		cout << i.first << " " << i.second << '\n';
}