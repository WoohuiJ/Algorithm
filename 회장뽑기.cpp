#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> graph(n+1, vector<int>(n + 1, 100));
	int a = 0, b = 0;
	while (true)
	{
		cin >> a >> b;
		if (a == -1) break;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) graph[i][j] = 0;
		}
	}


	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);			
			}
		}
	}
	int mini = 1000;
	vector<int> result(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int max = 0;
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] > max) max = graph[i][j];
		}
		result[i] = max;
		if (max < mini) mini = max;
	}
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (result[i] == mini) count++;
	}
	cout << mini << " " << count << endl;
	for (int i = 1; i <= n; i++)
	{
		if (result[i] == mini) cout << i << " ";
	}
} 