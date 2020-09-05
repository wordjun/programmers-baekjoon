#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	//듣도못한 사람수 N, 보도못한 사람수 M
	int N, M;
	string str;
	unordered_map<string, int> map;
	vector<string>result;
	int count = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		map[str]++;
	}
	for (int i = 0; i < M; i++) {
		cin >> str;
		map[str]--;
	}

	for (auto& i : map) {
		if (!i.second) {
			result.push_back(i.first);
			count++;
		}
	}
	cout << count << '\n';
	sort(result.begin(), result.end());
	for (auto& i : result)
		cout << i << "\n";
	return 0;
}