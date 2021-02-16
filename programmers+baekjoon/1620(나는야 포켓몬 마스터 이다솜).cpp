#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


bool comp(pair<string, int>a, pair<string, int>b) {
	return a.first < b.first;//���ڿ� ��������
}

int main() {
	vector<string> v1;//������ ���ڷ� �־����� ��
	vector<pair<string, int>> v2;//������ ���ڿ��� �־����� ��
	
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
		if (name[0] >= 'A' && name[0] <= 'Z') {//�Է��� ù���ڰ� ���ĺ��� ��� �ش��ϴ� ���ڸ�
			//����Ž������ �ð��ʰ� ����
			int low = 0, high = N - 1, mid = 0;
			while (low <= high) {
				mid = (low + high) / 2;
				if (v2[mid].first == name) {
					cout << v2[mid].second << '\n';
					break;
				}
				else if (v2[mid].first < name) {//ã���� �ϴ� ���ڿ��� ��� �ε����� ��ġ�� ���ڿ����� �� �ڿ� ���� ���
					low = mid + 1;
				}
				else {//ã�����ϴ� ���ڿ��� ��� �ε����� ��ġ�� ���ڿ����� �տ� ���� ���
					high = mid - 1;
				}
			}
		}
		else {//���ڰ� �־��� ��� �ش��ϴ� ���ڿ��� ���
			cout << v1[stoi(name)] << '\n';
		}
	}
	return 0;
}