#include <string>
#include <vector>
#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string, int> map1;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for (int i = 0; i < participant.size(); i++) {
        map1[participant[i]]++;
    }
    for (auto& i : completion) {
        map1[i]--;
    }
    for (auto& i : map1) {
        if (i.second != 0)
            answer = i.first;
    }
    return answer;
}

int main() {
    vector<string>participant = { "mislav", "stanko", "mislav", "ana" };
    vector<string>completion = {"stanko", "mislav", "ana" };
    cout << solution(participant, completion);
    return 0;
}