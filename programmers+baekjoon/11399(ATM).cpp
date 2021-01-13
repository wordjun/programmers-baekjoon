#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	vector<pair<int, int>> v;
	int N = 0, num = 0, sum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		v.push_back({i, num});
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size();i++) {
		for (int j = 0; j <= i; j++) {
			sum += v[j].second;
		}
	}
	cout << sum << '\n';
	return 0;
}