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
    //여기까지 왔다면 participant벡터 마지막 원소 제외 모든 원소들이 같다는 뜻
    return participant[participant.size()-1];
}

int main() {
    vector<string>participant = { "mislav", "stanko", "mislav", "ana" };
    vector<string>completion = { "stanko", "mislav", "ana" };
    cout << solution(participant, completion);
    return 0;
}