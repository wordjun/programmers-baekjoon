#include <string>
#include <vector>
#include <queue>//FIFO
#include<iostream>
using namespace std;

queue<int> q;
queue<pair<int, int>> bridge;//���� ���Կ� ���� �ٸ��� �ö�� �� �ʰ��� �ð�
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1, count = 0;
    for (auto& i : truck_weights) {
        q.push(i);
    }
    int currentWeight = 0, newCar = 0;
    while (count != truck_weights.size()) {
        if (!q.empty()) {
            newCar = q.front();
            currentWeight += newCar;//����: ���� ���� �Ѵ븸 �ִ� ���
            if (currentWeight <= weight) {//�ѵ����� ���ʰ� �� �������� ����
                bridge.push({ newCar, 0 });
                q.pop();//���ť���� ����
            }
            else {
                currentWeight -= newCar;
            }
        }
        answer++;//1�ʰ��,
        //�ٸ� �� ��� ���鿡 ���� 1�� ��� too
        for (int i = 0; i < bridge.size(); i++) {
            pair<int, int> tempCar = bridge.front();//�ٸ� �� �� ������
            bridge.pop();
            tempCar.second++;
            bridge.push(tempCar);//�ٽ� ť�� �������
        }

        if (bridge.front().second == bridge_length) {//���� �� �������� �ٸ��� �� �ǳӴٸ�
            count++;//�ٸ��� ����� ���� count����
            currentWeight -= bridge.front().first;//���� �ٸ� �� ������ ���� �տ��� ��� ����� ���� ����
            bridge.pop();
        }
    }
    return answer;
}

int main() {
    vector<int> temp = { 7, 4, 5, 6 };
    cout<<solution(2, 10, temp);
}