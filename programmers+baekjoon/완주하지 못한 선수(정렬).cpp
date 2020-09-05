#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0; i < completion.size();i++) {
        if (participant[i] != completion[i])
            return participant[i];
    }
    //������� �Դٸ� participant���� ������ ���� ���� ��� ���ҵ��� ���ٴ� ��
    return participant[participant.size()-1];
}

int main() {
    vector<string>participant = { "mislav", "stanko", "mislav", "ana" };
    vector<string>completion = { "stanko", "mislav", "ana" };
    cout << solution(participant, completion);
    return 0;
}