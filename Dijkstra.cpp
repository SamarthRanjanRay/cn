// Djikstra
#include <bits/stdc++.h>
using namespace std;
#define INF 999

int getMin(int n, int dist[], bool visited[])
{
	int j = -1;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i] && (j == -1 || dist[i] <= dist[j]))
			j = i;
	}
	return j;
}

void dji(int x, int n, int a[10][10], int dist[])
{
	bool visited[n];
	for (int i = 0; i < n; i++)
		dist[i] = a[x][i], visited[i] = false;
	dist[x] = 0;
	for (int count = 0; count < n - 1; count++)
	{
		int v = getMin(n, dist, visited);
		visited[v] = true;
		for (int i = 0; i < n; i++)
		{
			if (!visited[i] && dist[i] > dist[v] + a[v][i])
				dist[i] = dist[v] + a[v][i];
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int a[10][10];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 0)
				a[i][j] = INF;
		}
	}
	int x;
	cin >> x;
	int dist[n];
	dji(x, n, a, dist);
	for (int i = 0; i < n; i++)
		cout << dist[i] << " ";
	return 0;
}
// Test Cases:
// 5
// 0 6 1 0 0
// 0 0 0 10 0
// 0 4 0 0 5
// 0 0 0 0 0
// 0 0 0 2 0
// 0

// Ans:
// 0 5 1 8 6

