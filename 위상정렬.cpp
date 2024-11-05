#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	int a, b;
	vector<vector<int>> graph(n+1, vector<int>(n+1));
	vector<int> inward(n+1);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		inward[b]++;
		graph[a][b] = 1;
	}

	queue<int> wait;

	for (int i = 1; i <= n; i++)
	{
		if (inward[i] == 0)
		{
			wait.push(i);
		}
	}
	int current;
	while (!wait.empty())
	{
		current = wait.front();
		wait.pop();

		cout << current << " ";

		for (int i = 1; i <= n; i++)
		{
			if (graph[current][i] != 0)
			{
				inward[i]--;
				if (inward[i] == 0)
				{
					wait.push(i);
				}
			}
		}	
	}
}
