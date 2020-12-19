#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    //도난당한 학생들 번호 lost
    //여벌의 체육복을 가져온 학생들 번호 reserve
    //return 체육수업을 들을 수 있는 학생의 최댓값
    //2번, 4번이 도난당했다면, 1번이 2번에게, 3번이나 5번이 4번에게 빌려줄 수 있음
    //따라서 총 5명이 수업들을 수 있다

    //ex2.
    //2, 4번이 도난당했고, 3번이 여분을 갖고있다면 2, 4가 앞뒤번호이므로
    //둘 중 1명에게만 줄 수 있다
    //따라서 1번, 2혹은 4중 1명, 그리고 3, 5번 => 총 4명이 수업가능

    //ex3.
    //3번도난, 1번 여분. 그러나 1번은 2번에게만 대여가능하므로
    //1번, 2번해서 총 두명만 수업가능

    int total = 0;
    vector<int>students(n + 1, 1);//all students have 1 at first
    students[0] = 0;//0번학생은 없음
    //1번부터 시작해서 마지막 
    
    for (auto &i : lost) {
        students[i]--;//도난당한 학생것들은 1씩 감소
    }
    for (auto& i : reserve) {
        students[i]++;//여분 가진 학생들은 1씩 추가
    }

    for (int i = 1; i < students.size(); i++) {
        //만약 현재 순회중인 학생이 도난당한 학생인 경우
        if (students[i] == 2) {
            if (i == 1 && !students[i + 1]) {//첫번째 학생은 자기 뒷번호 학생만 체크
                //만약 자신이 체육복이 도난당했고, 자기 뒷번호 학생이 여분을 갖고 있다면 자신한테 1개 줄 수 있음
                students[i]--;//현재 학생 체육복 빌림
                students[i + 1]++;//빌려준 학생 1개 감소
            }
            else if (i == students.size() - 1 && !students[i - 1]) {//마지막 학생은 자기 앞 학생만 체크
                students[i]--;//현재 학생 체육복 빌림
                students[i - 1]++;//빌려준 학생 1개 감소
            }
            else {//첫번째학생과 마지막 학생 사이의 학생들 확인
                //앞뒤로 여분을 가진 학생이 있다면 빌려온다
                if (!students[i - 1]) {
                    students[i - 1]++;//빌려준 학생 1개 감소
                }
                else if (!students[i + 1]) {
                    students[i + 1]++;//빌려준 학생 1개 감소
                }
                students[i]--;//현재 학생 체육복 빌림
            }
        }
    }
    for (int i = 1; i < students.size(); i++) {
        if (students[i] >= 1)
            answer++;
    }

    return answer;
}

int main() {
    vector<int> v = { 2, 3, 5, 8, 9, 10 };
    vector<int> v2 = { 1, 4, 6, 7, 11 };
    cout << solution(11, v, v2);
}