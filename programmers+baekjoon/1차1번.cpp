#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;
unordered_map<char, int> map;
int solution(string s) {
	int answer = 0;
	for (int i = 0; i < s.length(); i++) {
		map[s[i]]++;
	}
	for (auto i : map) {
		if (i.second % 2 != 0)
			answer++;
	}
		
	
	return answer;
}
int main() {
	cout<<solution("aabbbccd");
}