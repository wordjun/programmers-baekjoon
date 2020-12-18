#include <string>
#include <vector>

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
        if (i == 1) {

        }
        else if (i == students.size() - 1) {

        }
        else {

        }
    }

    return answer;
}