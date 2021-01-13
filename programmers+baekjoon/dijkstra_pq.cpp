#include<iostream>
#include<queue>
using namespace std;

#define MAX_V 20001//�ִ� ���� ��
#define INIT 99999
//adjacency list: pair<destination vertex, weight>
vector<pair<int, int>> adj[MAX_V];

int dist[MAX_V] = { 0, };
int startVertex = 0;
int V, E;


void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, startVertex });//�������� �������� pq�� ����
	while (!pq.empty()) {
		int curW = -pq.top().first;
		int curV = pq.top().second;
		pq.pop();
		
		//���� ���� �ͺ��� �� ª�� ����� ��� ����
		if (dist[curV] < curW)
			continue;

		for (int i = 0; i < adj[curV].size(); i++) {
			int old_dist = dist[adj[curV][i].first];
			int new_dist = dist[curV] + adj[curV][i].second;
			
			//�� ª�� ��� �߽߰� dist����, pq�� ����
			//dist���� ������ -> destV������ �ִܰŸ��� �������
			if (old_dist > new_dist) {
				dist[adj[curV][i].first] = new_dist;
				pq.push({-new_dist, adj[curV][i].first });
				/*
				���⼭ -�� �ִ� ����?
				priority_queue STL�� �⺻������ ���� ū ���Ұ� ���� ������ ť�� ����
				���� �Ÿ��� ��ȣ�� �ٲ㼭 �Ÿ��� ���� �������� ���������� �ϱ� ����
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
		
	dist[startVertex] = 0;//�������� 0���� �ʱ�ȭ
	dijkstra();
	for (int i = 1; i <= V; i++) {
		if (dist[i] != INIT)
			cout << dist[i] << "\n";
		else
			cout << "INF\n";
	}
}