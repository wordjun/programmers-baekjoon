#include <string>
#include <vector>
#include <queue>//FIFO
#include<iostream>
using namespace std;

queue<int> q;
queue<pair<int, int>> bridge;//차의 무게와 현재 다리에 올라온 후 초과한 시간
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1, count = 0;
    for (auto& i : truck_weights) {
        q.push(i);
    }
    int currentWeight = 0, newCar = 0;
    while (count != truck_weights.size()) {
        if (!q.empty()) {
            newCar = q.front();
            currentWeight += newCar;//예외: 만약 차가 한대만 있는 경우
            if (currentWeight <= weight) {//한도무게 미초과 시 다음차량 가능
                bridge.push({ newCar, 0 });
                q.pop();//대기큐에서 제거
            }
            else {
                currentWeight -= newCar;
            }
        }
        answer++;//1초경과,
        //다리 위 모든 차들에 대해 1초 경과 too
        for (int i = 0; i < bridge.size(); i++) {
            pair<int, int> tempCar = bridge.front();//다리 위 맨 앞차량
            bridge.pop();
            tempCar.second++;
            bridge.push(tempCar);//다시 큐에 집어넣음
        }

        if (bridge.front().second == bridge_length) {//만약 맨 앞차량이 다리를 다 건넛다면
            count++;//다리를 통과한 차량 count증가
            currentWeight -= bridge.front().first;//현재 다리 위 차들의 무게 합에서 방금 통과한 차량 감량
            bridge.pop();
        }
    }
    return answer;
}

int main() {
    vector<int> temp = { 7, 4, 5, 6 };
    cout<<solution(2, 10, temp);
}