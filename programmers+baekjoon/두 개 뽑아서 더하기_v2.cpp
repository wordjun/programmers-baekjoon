#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

//���� �迭 numbers�� �־����ϴ�.
//numbers���� ���� �ٸ� �ε����� �ִ� �� ���� ���� �̾� ���ؼ� 
//���� �� �ִ� ��� ���� �迭�� ������������ ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.
//numbers�� ���̴� 2 �̻� 100 �����Դϴ�.
//numbers�� ��� ���� 0 �̻� 100 �����Դϴ�.
//���� �� ���� �̾� ������ ���� �ִ� ���� 200, �ּ� ���� 1�Դϴ�.
bool num[201];
//�� ���� ���Դ��� �ȳ��Դ����� üũ�ϱ� ���� �迭�� ���
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int sum = 0, size = numbers.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            sum = numbers[i] + numbers[j];
            if (!num[sum]) {
                num[sum] = true;
                answer.push_back(sum);
            }
        }
    }
    sort(answer.begin(), answer.end());
    for (auto& i : answer)
        cout << i << ' ';
    return answer;
}

int main() {
    vector<int> test = { 2,1,3,4,1 };
    solution(test);
    return 0;
}