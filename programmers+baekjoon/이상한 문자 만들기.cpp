#include <string>
#include <vector>
#include<iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    vector<string> words;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 32) {//공백인 경우 
            words.push_back(temp);
            temp = "";
        }
        else {
            temp.push_back(s[i]);
        }
    }
    if (temp != "")
        words.push_back(temp);

    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].length(); j++) {
            if (j % 2 == 0) {
                answer.push_back(words[i].at(j) - 32);
            }
            else
                answer.push_back(words[i].at(j));
        }
        answer.push_back(32);
    }
    answer.pop_back();
    return answer;
}
