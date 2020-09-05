#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>students(n + 1, 1);//모든 학생들은 처음엔 1벌씩 갖고있음
    for (auto& i : lost) {
        students[i]--;//체육복을 도난당한 학생들
    }
    for (auto& j : reserve) {
        students[j]++;//여벌을 가져온 학생들
    }
    for (int i = 1; i <= n; i++) {
        if (students[i] == 0) {//체육복이 하나도 없는 경우
            if (i == 1 && students[i + 1] == 2) {//첫번째 학생과 마지막 학생은 각각 자기 뒤와 앞 학생만 체크가능
                students[i + 1]--;
                students[i]++;
            }
            else if (i == n && students[i - 1] == 2) {
                students[i - 1]--;
                students[i]++;
            }
            else {
                if (students[i - 1] == 2) {
                    students[i - 1]--;
                    students[i]++;
                }
                else if (students[i + 1] == 2) {
                    students[i + 1]--;
                    students[i]++;
                }
            }
        }
    }
    for (int i = 1; i < students.size(); i++) {
        if (students[i])//1벌이상 가진 자들은 수업을 들을 수 있다
            answer++;
    }
    return answer;
}

int main() {
    vector<int> lost = { 2, 4 };
    vector<int> reserve = { 3 };
    cout << solution(5, lost, reserve);
}