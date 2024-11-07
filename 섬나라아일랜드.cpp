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

	int n;
	cin >> n;

	vector<vector<int>> graph(n, vector<int>(n));
	vector<vector<int>> checker(n, vector<int>(n));
	vector<vector<int>> visited(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}
	queue<pair<int, int>> island;
	vector<pair<int, int>> moves{ {-1, -1} , {-1, 0}, {-1, 1},  {0, -1},  {0,1},  {1, -1},  {1, 0},  {1, 1} };

	int num_island = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (checker[i][j] == 0 && graph[i][j] != 0 && visited[i][j] == 0)
			{
				num_island++;
				island.push(make_pair(i, j));

				pair<int, int> node;
				while (!island.empty())
				{
					node = island.front();
					island.pop();
					visited[node.first][node.second] = 1;
					checker[node.first][node.second] = num_island;

					for (auto i : moves)
					{
						if (node.first + i.first >= 0 && node.first + i.first < n && node.second + i.second >= 0 && node.second + i.second < n && visited[node.first + i.first][node.second + i.second] == 0)
						{
							if (graph[node.first + i.first][node.second + i.second] == 1)
							{
								island.push(make_pair(node.first + i.first, node.second + i.second));
							}
						}
					}
				}
			}
			else
			{
				visited[i][j] = 1;
			}
		}
	}
	cout << num_island;
}