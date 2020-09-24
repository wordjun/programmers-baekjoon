#include <string>
#include <vector>
#include<iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    bool flag = true;

    for (int i = 0; i < s.size(); i++) {

        if (s.at(i) == ' ') {
            answer += " ";
            flag = true;
        }
        else {

            if (flag) {
                flag = false;
                answer += toupper(s[i]);
            }
            else {
                flag = true;
                answer += tolower(s[i]);
            }
        }
    }

    //string temp = "";
    //vector<string> words;
    //for (int i = 0; i < s.size(); i++) {
    //    if (s[i] == 32) {//공백인 경우 
    //        words.push_back(temp);
    //        temp = "";
    //    }
    //    else {
    //        temp.push_back(s[i]);
    //    }
    //}
    //if (temp != "")
    //    words.push_back(temp);

    //char c;
    //for (int i = 0; i < words.size(); i++) {//각 단어별로 처리
    //    for (int j = 0; j < words[i].size(); j++) {
    //        c = words[i].at(j);
    //        if (j % 2 == 0) {//현재 단어의 인덱스를 기준으로 홀,짝수 판별
    //            if (c >= 'A' && c <= 'Z')//이미 대문자면 그대로 넣는다
    //                answer += c;
    //            else
    //                answer += c - 32;//대문자가 아닌 경우 -32
    //        }
    //        else {
    //            if (c >= 'a' && c <= 'z')//이미 소문자면 그대로 넣는다
    //                answer += c;
    //            else
    //                answer += c + 32;//소문자가 아닌 경우 +32
    //        }
    //            
    //    }
    //    answer += 32;
    //}
    //answer.pop_back();
    return answer;
}
