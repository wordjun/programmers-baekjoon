#include <string>
#include <vector>
#include<iostream>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.length(); i++) {
        int temp = s[i] + n;
        if (temp > 90 && s[i] <= 91) {//�빮���̸鼭 ������ �Ѿ�� ���
            answer.push_back(temp - 26);
        }
        else if (temp > 122 && s[i] >= 97) {//�ҹ���
            answer.push_back(temp - 26);
        }
        else if (s[i] == 32) {//����
            answer.push_back(s[i]);
        }
        else
            answer.push_back(temp);
    }
    return answer;
}

int main() {
    cout << solution("a B z", 4);
}