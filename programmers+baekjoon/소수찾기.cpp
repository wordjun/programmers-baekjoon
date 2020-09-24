#include <string>
#include <vector>
#include<iostream>

using namespace std;
int arr[1000001];

int solution(int n) {
    //1���� n ���� �Ҽ������� ã�ƶ�
    //�����佺�׳׽��� ü ���
    int answer = 0;
    for (int i = 2; i <= n; i++) {
        arr[i] = i;
    }
    //2���� ������ Ư�� ���� ����� �ش��ϴ� ��� ���� �����
    for (int i = 2; i <= n; i++) {
        if (arr[i] == 0)//�̹� ������ ���� �ǳʶٰ�,
            continue;
        else {//�������� ���� ���� �� ������� ������ ������ ��� ���� �����
            for (int j = i * i; j <= n; j += i) {
                arr[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (arr[i] != 0)
            answer++;
    }
    return answer;
}

int main() {
    cout << solution(10);
    return 0;
}