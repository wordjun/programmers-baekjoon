#include <string>
#include <vector>

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
        if (i == 1) {

        }
        else if (i == students.size() - 1) {

        }
        else {

        }
    }

    return answer;
}