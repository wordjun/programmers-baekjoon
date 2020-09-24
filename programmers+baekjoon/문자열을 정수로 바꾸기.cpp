#include <string>
#include <vector>
#include <cmath>
#include<iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int temp;
    if (s[0] == '-') {
        for (int i = 1; i < s.length(); i++) {
            temp = s[i] - '0';
            answer = answer * 10 +  (int)temp;
        }
        answer *= -1;
    }
    else {
        for (int i = 0; i < s.length(); i++) {
            temp = s[i] - '0';
            answer = answer * 10 + (int)temp;
        }
    }
    return answer;
}