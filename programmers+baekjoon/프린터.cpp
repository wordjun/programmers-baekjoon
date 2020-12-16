#include <string>
#include <vector>
#include<queue>

using namespace std;
queue<pair<int, int>>q;
priority_queue<int>pq;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    for (int i = 0; i < priorities.size(); i++) {
        q.push({ priorities[i], i });//{priority, location}
        pq.push(priorities[i]);
    }
    while(!q.empty()) {
        pair<int, int> temp1 = q.front();
        int temp2 = pq.top();
        q.pop();
        if (temp1.first == temp2) {
            pq.pop();
            answer++;
            if (temp1.second == location)
                break;
        }
        else {
            q.push(temp1);
        }
    }
    return answer;
}

int main() {
    vector<int> sample = { 1, 1, 9, 1, 1, 1 };
}