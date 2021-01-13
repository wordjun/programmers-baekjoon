#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<pair<int, int>, int>a, pair<pair<int, int>, int>b) {
	return a.first.second < b.first.second;
}
bool restore(pair<pair<int, int>, int>a, pair<pair<int, int>, int>b) {
	return a.first.first < b.first.first;
}

int main() {
	vector<pair<pair<int, int>, int>> v;
	int N, num, cnt = 0, prev = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		v.push_back({ { i, num }, 0 });
	}
	sort(v.begin(), v.end(), comp);
	prev = v[0].first.second;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].first.second != prev) {
			cnt++;
		}
		prev = v[i].first.second;
		v[i].second = cnt;
	}
	sort(v.begin(), v.end(), restore);
	for (auto& i : v)
		cout << i.second << " ";
	return 0;
}