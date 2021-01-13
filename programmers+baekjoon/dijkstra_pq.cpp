#include<iostream>
#include<queue>
using namespace std;

#define MAX_V 20001//최대 정점 수
#define INIT 99999
//adjacency list: pair<destination vertex, weight>
vector<pair<int, int>> adj[MAX_V];

int dist[MAX_V] = { 0, };
int startVertex = 0;
int V, E;


void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, startVertex });//시작점을 시작으로 pq에 삽입
	while (!pq.empty()) {
		int curW = -pq.top().first;
		int curV = pq.top().second;
		pq.pop();
		
		//현재 꺼낸 것보다 더 짧은 경로인 경우 무시
		if (dist[curV] < curW)
			continue;

		for (int i = 0; i < adj[curV].size(); i++) {
			int old_dist = dist[adj[curV][i].first];
			int new_dist = dist[curV] + adj[curV][i].second;
			
			//더 짧은 경로 발견시 dist갱신, pq에 삽입
			//dist에는 시작점 -> destV까지의 최단거리가 담겨있음
			if (old_dist > new_dist) {
				dist[adj[curV][i].first] = new_dist;
				pq.push({-new_dist, adj[curV][i].first });
				/*
				여기서 -로 넣는 이유?
				priority_queue STL은 기본적으로 가장 큰 원소가 위로 가도록 큐를 구성
				따라서 거리의 부호를 바꿔서 거리가 작은 정점부터 꺼내지도록 하기 위함
				*/
			}
		}
	}
}

int main() {
	int u, v, w;
	//cout << "Enter no. of vertex and edge: \n";
	cin >> V >> E;
	cin >> startVertex;
	
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}
	for (int i = 1; i <= V; i++) {
		dist[i] = INIT;
	}
		
	dist[startVertex] = 0;//시작점은 0으로 초기화
	dijkstra();
	for (int i = 1; i <= V; i++) {
		if (dist[i] != INIT)
			cout << dist[i] << "\n";
		else
			cout << "INF\n";
	}
}