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
			if (graph[i][j] != 0)
			{
				num_island++;
				island.push(make_pair(i, j));
			
				pair<int, int> node;
				while (!island.empty())
				{
					node = island.front();
					island.pop();
					for (auto i : moves)
					{
						if (node.first + i.first >= 0 && node.first + i.first < n && node.second + i.second >= 0 && node.second + i.second < n)
						{
							if (graph[node.first + i.first][node.second + i.second] == 1)
							{
								graph[node.first + i.first][node.second + i.second] = 0;
								island.push(make_pair(node.first + i.first, node.second + i.second));
							}							
						}
					}
				}
			}

		}
	}
	cout << num_island;
}