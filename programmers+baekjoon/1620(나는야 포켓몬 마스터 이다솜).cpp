#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


bool comp(pair<string, int>a, pair<string, int>b) {
	return a.first < b.first;//문자열 오름차순
}

int main() {
	vector<string> v1;//문제가 숫자로 주어졌을 때
	vector<pair<string, int>> v2;//문제가 문자열로 주어졌을 때
	
	int N = 0, M = 0;
	cin >> N >> M;
	string name;
	v1.push_back("");
	for (int i = 1; i <= N; i++) {
		cin >> name;
		v1.push_back(name);
		v2.push_back({ name, i});
	}
	sort(v2.begin(), v2.end(), comp);
	cout << '\n';
	for (int i = 1; i <= M; i++) {
		cin >> name;
		if (name[0] >= 'A' && name[0] <= 'Z') {//입력의 첫문자가 알파벳인 경우 해당하는 숫자를
			//이진탐색으로 시간초과 방지
			int low = 0, high = N - 1, mid = 0;
			while (low <= high) {
				mid = (low + high) / 2;
				if (v2[mid].first == name) {
					cout << v2[mid].second << '\n';
					break;
				}
				else if (v2[mid].first < name) {//찾고자 하는 문자열이 가운데 인덱스에 위치한 문자열보다 더 뒤에 있을 경우
					low = mid + 1;
				}
				else {//찾고자하는 문자열이 가운데 인덱스에 위치한 문자열보다 앞에 있을 경우
					high = mid - 1;
				}
			}
		}
		else {//숫자가 주어진 경우 해당하는 문자열을 출력
			cout << v1[stoi(name)] << '\n';
		}
	}
	return 0;
}