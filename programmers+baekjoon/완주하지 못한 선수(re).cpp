#include <string>
#include <vector>
#include<unordered_map>
#include<iostream>
using namespace std;

unordered_map<string, int> map;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for (auto& i : participant) {
        if (map[i] != 0) {
            //�̹� �ִ� ���(�ߺ��� ���)
            map[i]++;
        }
        else {
            //�ʿ� ù ���� 
            map[i] = 1;
        }
    }
    for (auto& i : completion) {
        map[i]--;
    }
    //�ᱹ 1�� map[i]�� ã���� �ȴ�
    for (auto& i : participant) {
        if (map[i] == 1)
            return i;
    }
}

int main() {
    vector<string> p = { "leo", "kiki", "eden" };
    vector<string> c = { "eden" , "kiki" };
    cout<<solution(p, c);
    return 0;
}