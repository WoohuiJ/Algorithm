#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;

struct rabbit
{
	int x;
	int y;
	int weight;
	rabbit(int a, int b, int c)
	{
		x = a;
		y = b;
		weight = c;
	}
};

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

	bool operator < (const node& comp)const
	{
		if (depth == comp.depth)
		{
			if (x == comp.x) return y > comp.y;
			else return x > comp.x;
		}
		else return depth > comp.depth;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;

	int size = 2;
	int count = 2;

	int time = 0;

	vector<vector<int>> graph(n, vector<int>(n));
	vector<vector<int>> shortest(n, vector<int>(n));
	pair<int, int> simba;
	vector<rabbit> saver;
	vector<pair<int, int>> moves{ {-1, 0 }, { 0,1 }, { 1,0 }, { 0,-1 } };

	priority_queue<node> route;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 9)
			{
				simba = make_pair(i, j);
				graph[i][j] = 0;
			}
			else if (graph[i][j] != 0)
			{
				saver.push_back(rabbit(i, j, graph[i][j]));
			}
		}
	}

	while (!route.empty())
	{
		node current = route.top();
		route.pop();
		int x = current.x;
		int y = current.y;
		int depth = current.depth;

		if (graph[x][y] != 0 && graph[x][y] < size)
		{
			graph[x][y] = 0;
			simba.first = x;
			simba.second = y;
			count--;
			if (count == 0)
			{
				size++;
				count = size;
			}
			time = depth;
		}

		for (auto move : moves)
		{
			int xx = x + move.first;
			int yy = y + move.second;
			if(xx >= 0 && xx < n && yy >= 0 && yy < n && )
		}
	}




	while (true)
	{
		fill(shortest.begin(), shortest.end(), vector<int>(n, 0));
		for (int i = 0; i < saver.size(); i++)
		{
			int xx = saver[i].x;
			int yy = saver[i].y;
			graph[xx][yy] = saver[i].weight;
		}
		queue<node> pathfind;
		pathfind.push(node(simba.first, simba.second, 0));

		//최단거리 구하기
		while (!pathfind.empty())
		{

			node current = pathfind.front();
			pathfind.pop();
			for (auto move : moves)
			{
				int xx = current.x + move.first;
				int yy = current.y + move.second;
				if (xx >= 0 && xx < n && yy >= 0 && yy < n)
				{
					if (graph[xx][yy] < 8 && graph[xx][yy] <= size)
					{
						pathfind.push(node(xx, yy, current.depth + 1));
						shortest[xx][yy] = current.depth + 1;
						graph[xx][yy] = 8;
					}
				}
			}
			//for (int i = 0; i < n; i++)
			//{
			//	for (int j = 0; j < n; j++)
			//	{
			//		cout << shortest[i][j] << " ";
			//	}
			//	cout << endl;
			//}

			//cout << "--------------------------------" << endl;
		}
		int target_num = 0;
		int checker = 0;
		for (int i = 0; i < saver.size(); i++)
		{
			int xx = saver[i].x;
			int yy = saver[i].y;
			rabbit target(xx, yy, saver[i].weight);

			if (size <= target.weight)
			{
				continue;
			}
			//먹을 수 있는 토끼
			
			//가장 가까운 토끼
			if (shortest[target.x][target.y] < shortest[saver[target_num].x][saver[target_num].y])
			{
				target_num = i;
				int checker = 1;
			}
			//거리가 같으면
			else if(shortest[target.x][target.y] == shortest[saver[target_num].x][saver[target_num].y])
			{
				//가장 위에 있는 토끼
				if (target.x < saver[target_num].x)
				{
					target_num = i;
					int checker = 1;
				}
				//높이가 같으면
				else if (target.x == saver[target_num].x)
				{
					//가장 왼쪽에 있는 토끼
					if (target.y < saver[target_num].y)
					{
						target_num = i;
						int checker = 1;
					}
				}			
			}
		}
		simba.first = saver[target_num].x;
		simba.second = saver[target_num].y;
		time += saver[target_num].weight;
		count--;
		if (count == 0)
		{
			size++;
			count = size;
		}
		saver.erase(saver.begin() + target_num);
		if (saver.empty())
		{
			break;
		}
	}

	cout << time;
}