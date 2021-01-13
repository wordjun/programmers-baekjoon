#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX_V 20001
#define INIT 999999

int V, E, start;
vector<pair<int, int>> adj[MAX_V];//adj[a][0].first = b  (a->b), second = c (weight)
int dist[MAX_V] = { 0, };


void dijkstra() {
	/*priority_queue에서는 기본적으로 가장 큰 원소가 pop의 우선순위를 가지기 때문에

		가중치가 3, 2, 1이라는 값이 들어왔다면 우선순위는 3, 2, 1이아닌 1, 2, 3이어야 하기에

		음의 가중치로 바꾸어 우선순위 큐에 넣는다.(-1, -2, -3으로)*/
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		//cout << pq.top().first <<" " << pq.top().second<<'\n';
		int cur = pq.top().second;
		int cost = -1 * pq.top().first;
		pq.pop();

		//현재노드에서부터 주변값들 갱신
		for (int i = 0; i < adj[cur].size(); i++) {
			int new_dist = dist[cur] + adj[cur][i].second;
			int old_dist = dist[adj[cur][i].first];

			//현재노드부터 연결된 간선의 목적지까지 가는거리와 기존거리 비교
			if (new_dist < old_dist) {
				dist[adj[cur][i].first] = new_dist;//목적지까지의 거리 갱신
				pq.push({ -1 * new_dist, adj[cur][i].first });
			}
		}
	}
}

int main() {
	int  u, v, w;
	
	cin >> V >> E;
	//DAG는 adjacency list사용
	
	cin >> start;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}
	/*for (int i = 1; i <= V;i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			cout <<i<<"->"<< adj[i][j].first << ", weight: " << adj[i][j].second << '\n';
		}
		cout << "size: " << adj[i].size() << '\n';
	}*/
	//최단경로 계산: 다익스트라
	for (int i = 1; i <= V; i++)
		dist[i] = INIT;
	dist[start] = 0;
	dijkstra();
	//for (int i = 1; i <= V; i++) {
	//	DFS(i);
	//	//cout << "shortest dist: " << DFS(i) << '\n';
	//	total = 0;
	//}
	for (int i = 1; i <= V; i++) {
		if (dist[i] != INIT)
			cout << dist[i] << '\n';
		else
			cout << "INF\n";
	}
}