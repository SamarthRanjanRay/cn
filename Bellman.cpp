#include <bits/stdc++.h>
using namespace std;
#define INF 999

void Bellman(int V, int E, int graph[][3], int src)
{
	int dist[V];
	for (int i = 0; i < V; i++)
		dist[i] = INF;
	dist[src] = 0;
	for (int i = 0; i < V - 1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			if (dist[graph[j][0]] != INF && dist[graph[j][1]] > dist[graph[j][0]] + graph[j][2])
				dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];
		}
	}
	for (int i = 0; i < V; i++)
		cout << dist[i] << " ";
}
int main()
{
	int V, E;
	cin >> V >> E;
	int graph[E][3];
	for (int i = 0; i < E; i++)
	{
		int s, d, w;
		cin >> s >> d >> w;
		graph[i][0] = s;
		graph[i][1] = d;
		graph[i][2] = w;
	}
	Bellman(V, E, graph, 0);
	return 0;
}
// Test Case:
// 5
// 8
// 0 1 -1
// 0 2 4
// 1 2 3
// 1 3 2
// 1 4 2
// 3 2 5
// 3 1 1
// 4 3 -3

// Ans:
// 0 -1 2 -2 1