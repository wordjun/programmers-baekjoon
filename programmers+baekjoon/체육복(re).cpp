#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    //�������� �л��� ��ȣ lost
    //������ ü������ ������ �л��� ��ȣ reserve
    //return ü�������� ���� �� �ִ� �л��� �ִ�
    //2��, 4���� �������ߴٸ�, 1���� 2������, 3���̳� 5���� 4������ ������ �� ����
    //���� �� 5���� �������� �� �ִ�

    //ex2.
    //2, 4���� �������߰�, 3���� ������ �����ִٸ� 2, 4�� �յڹ�ȣ�̹Ƿ�
    //�� �� 1���Ը� �� �� �ִ�
    //���� 1��, 2Ȥ�� 4�� 1��, �׸��� 3, 5�� => �� 4���� ��������

    //ex3.
    //3������, 1�� ����. �׷��� 1���� 2�����Ը� �뿩�����ϹǷ�
    //1��, 2���ؼ� �� �θ� ��������

    int total = 0;
    vector<int>students(n + 1, 1);//all students have 1 at first
    students[0] = 0;//0���л��� ����
    //1������ �����ؼ� ������ 
    
    for (auto &i : lost) {
        students[i]--;//�������� �л��͵��� 1�� ����
    }
    for (auto& i : reserve) {
        students[i]++;//���� ���� �л����� 1�� �߰�
    }

    for (int i = 1; i < students.size(); i++) {
        //���� ���� ��ȸ���� �л��� �������� �л��� ���
        if (students[i] == 2) {
            if (i == 1 && !students[i + 1]) {//ù��° �л��� �ڱ� �޹�ȣ �л��� üũ
                //���� �ڽ��� ü������ �������߰�, �ڱ� �޹�ȣ �л��� ������ ���� �ִٸ� �ڽ����� 1�� �� �� ����
                students[i]--;//���� �л� ü���� ����
                students[i + 1]++;//������ �л� 1�� ����
            }
            else if (i == students.size() - 1 && !students[i - 1]) {//������ �л��� �ڱ� �� �л��� üũ
                students[i]--;//���� �л� ü���� ����
                students[i - 1]++;//������ �л� 1�� ����
            }
            else {//ù��°�л��� ������ �л� ������ �л��� Ȯ��
                //�յڷ� ������ ���� �л��� �ִٸ� �����´�
                if (!students[i - 1]) {
                    students[i - 1]++;//������ �л� 1�� ����
                }
                else if (!students[i + 1]) {
                    students[i + 1]++;//������ �л� 1�� ����
                }
                students[i]--;//���� �л� ü���� ����
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