#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int _min = 2147000000;
void DFS(int depth, int marker, int pizza_count, int choose_num, vector<int> result, vector<pair<int, int>> & pizza, vector<pair<int,int>> &house)
{
	if (depth == choose_num)
	{
		int sum = 0;

		for (int j = 0; j < house.size(); j++)
		{
			int distance = 2147000000;
			for (int i = 0; i < result.size(); i++)
			{
				int index = result[i];
				distance = min(distance, abs(pizza[index].first - house[j].first) + abs(pizza[index].second - house[j].second));
			}
			sum += distance;
		} 

		if (sum < _min) _min = sum;
		return;
	}
	else
	{
		for (int i = marker; i < pizza_count; i++)
		{
			result[depth] = i;
			DFS(depth + 1, i + 1, pizza_count, choose_num, result, pizza, house);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;


	vector<vector<int>> saver(vector<int>(n));
	vector<pair<int, int>> pizza;
	vector<pair<int, int>> house;

	int a;
	int pizza_count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a;
			if (a == 2)
			{
				pizza.push_back(make_pair(i, j));
				pizza_count++;
			}
			else if (a == 1)
			{
				house.push_back(make_pair(i, j));
			}
		}
	}
	vector<int> result(m);
	DFS(0, pizza_count, m, result, pizza, house);

	cout << _min;
}