#include <string>
#include <vector>
#include<algorithm>
using namespace std;

bool comp(char a, char b) {
    return a > b;//���� �������� ����
}

string solution(string s) {
    string answer = "";
    vector<char> v;
    for (int i = 0; i < s.length(); i++) {
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end(), comp);
    for (auto& i : v)
        answer.push_back(i);
    return answer;
}