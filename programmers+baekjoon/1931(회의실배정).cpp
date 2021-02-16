#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//bool firstSort(pair<int, int>a, pair<int, int>b) {
//	return a.first < b.first;
//}
bool secondSort(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	int N = 0, start = 0, end = 0, cnt1 = 1, cnt2 = 1;
	//vector<pair<int, int>> time1;
	vector<pair<int, int>> time2;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		//time1.push_back({ start, end });
		time2.push_back({ start, end });
	}
	//sort(time1.begin(), time1.end(), firstSort);
	sort(time2.begin(), time2.end(), secondSort);

	/*for (auto& i : time1)
		cout << i.first << " " << i.second << '\n';*/
	for (auto& i : time2)
		cout << i.first << " " << i.second << '\n';

	/*int current = time1[0].second;
	for (int i = 1; i < time1.size(); i++) {
		if (time1[i].first >= current) {
			current = time1[i].second;
			cnt1++;
		}
	}*/
	int current = time2[0].second;
	for (int i = 1; i < time2.size(); i++) {
		if (time2[i].first >= current) {
			current = time2[i].second;
			cnt2++;
		}
	}
	cout << cnt2 << '\n';
	return 0;
}