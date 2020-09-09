#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

bool comp(pair<char, string>a, pair<char, string> b) {
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    bool isOverlap = false;
    unordered_map<char, int>count;
    vector<pair<char, string>> temp;
    for (int i = 0; i < strings.size(); i++) {
        temp.push_back({ strings[i].at(n), strings[i] });
    }
    sort(temp.begin(), temp.end(), comp);
    for (auto& i : temp)
        answer.push_back(i.second);
    return answer;
}
