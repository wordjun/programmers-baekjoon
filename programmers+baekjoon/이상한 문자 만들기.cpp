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
    //    if (s[i] == 32) {//������ ��� 
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
    //for (int i = 0; i < words.size(); i++) {//�� �ܾ�� ó��
    //    for (int j = 0; j < words[i].size(); j++) {
    //        c = words[i].at(j);
    //        if (j % 2 == 0) {//���� �ܾ��� �ε����� �������� Ȧ,¦�� �Ǻ�
    //            if (c >= 'A' && c <= 'Z')//�̹� �빮�ڸ� �״�� �ִ´�
    //                answer += c;
    //            else
    //                answer += c - 32;//�빮�ڰ� �ƴ� ��� -32
    //        }
    //        else {
    //            if (c >= 'a' && c <= 'z')//�̹� �ҹ��ڸ� �״�� �ִ´�
    //                answer += c;
    //            else
    //                answer += c + 32;//�ҹ��ڰ� �ƴ� ��� +32
    //        }
    //            
    //    }
    //    answer += 32;
    //}
    //answer.pop_back();
    return answer;
}
