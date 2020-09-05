#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>students(n + 1, 1);//��� �л����� ó���� 1���� ��������
    for (auto& i : lost) {
        students[i]--;//ü������ �������� �л���
    }
    for (auto& j : reserve) {
        students[j]++;//������ ������ �л���
    }
    for (int i = 1; i <= n; i++) {
        if (students[i] == 0) {//ü������ �ϳ��� ���� ���
            if (i == 1 && students[i + 1] == 2) {//ù��° �л��� ������ �л��� ���� �ڱ� �ڿ� �� �л��� üũ����
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
        if (students[i])//1���̻� ���� �ڵ��� ������ ���� �� �ִ�
            answer++;
    }
    return answer;
}

int main() {
    vector<int> lost = { 2, 4 };
    vector<int> reserve = { 3 };
    cout << solution(5, lost, reserve);
}