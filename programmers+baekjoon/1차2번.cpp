#include<string>
#include<vector>
#include<iostream>
using namespace std;

int solution(vector<int> arr) {
	int answer = 1;
	int num = 0, count = 0, index1= 0, index2 = 0;
	vector<int> temp = arr;
	vector<int> temp2;
	vector<int> swap;
	if (arr.size() == 1) {
		answer = 1;
	}
	else {
		 do{
			index2 = 0;
			while(index2 < temp.size() - 1) {
				num = temp[index2];
				count = 1, index1 = index2 + 1;
				while (num == temp[index1]) {
					num = temp[index1];
					index1++;
					count++;
					if (index1 == temp.size())
						break;
				}
				index2 += count;
				temp2.push_back(count);
			}
			for (auto& i : temp2)
				cout << i << " ";
			cout << '\n';
			answer++;
			temp = temp2;
			temp2.clear();
		}while (temp.size() != 1);
		
	}
	return answer;
}

int main() {
	cout<<solution({ 1, 2, 3 });
}