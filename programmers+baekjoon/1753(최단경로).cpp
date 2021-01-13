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
	/*priority_queue������ �⺻������ ���� ū ���Ұ� pop�� �켱������ ������ ������

		����ġ�� 3, 2, 1�̶�� ���� ���Դٸ� �켱������ 3, 2, 1�̾ƴ� 1, 2, 3�̾�� �ϱ⿡

		���� ����ġ�� �ٲپ� �켱���� ť�� �ִ´�.(-1, -2, -3����)*/
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		//cout << pq.top().first <<" " << pq.top().second<<'\n';
		int cur = pq.top().second;
		int cost = -1 * pq.top().first;
		pq.pop();

		//�����忡������ �ֺ����� ����
		for (int i = 0; i < adj[cur].size(); i++) {
			int new_dist = dist[cur] + adj[cur][i].second;
			int old_dist = dist[adj[cur][i].first];

			//��������� ����� ������ ���������� ���°Ÿ��� �����Ÿ� ��
			if (new_dist < old_dist) {
				dist[adj[cur][i].first] = new_dist;//������������ �Ÿ� ����
				pq.push({ -1 * new_dist, adj[cur][i].first });
			}
		}
	}
}

int main() {
	int  u, v, w;
	
	cin >> V >> E;
	//DAG�� adjacency list���
	
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
	//�ִܰ�� ���: ���ͽ�Ʈ��
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