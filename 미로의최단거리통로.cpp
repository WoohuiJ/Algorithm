#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;

struct node
{
	int x;
	int y;
	int depth;
	node(int a, int b, int c)
	{
		x = a;
		y = b;
		depth = c;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> graph(n, vector<int>(n));
	vector<vector<int>> visited(n, vector<int>(n));
	vector<pair<int, int>> moves{ {-1, 0 }, { 0,1 }, { 1,0 }, { 0,-1 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}
	queue<node> maze;

	maze.push({ 0,0,0 });

	int result = 2147000000;
	while (!maze.empty())
	{
		node current = maze.front();
		maze.pop();
		visited[current.x][current.y] = 1;
		if (current.x == n - 1 && current.y == n - 1)
		{
			result = min(result, current.depth);
			break;
		}
		for (auto move : moves)
		{
			int xx = current.x + move.first;
			int yy = current.y + move.second;
			if (xx >= 0 && xx < n && yy >= 0 && yy < n)
			{
				if (graph[xx][yy] == 0 && visited[xx][yy] == 0)
				{
					maze.push({ xx, yy, current.depth + 1 });
				}
			}
		}
	}

	cout << result;
}