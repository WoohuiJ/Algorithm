#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int n;
int result = 0;
vector<pair<int, int>> saver;

void DFS(int current_day, int sum)
{
	if (current_day > n)
	{
		return;
	}

	if (sum > result) result = sum;

	for (int i = current_day; i < n; i++)
	{
		int day = saver[i].first;
		int cost = saver[i].second;
		DFS(i + day, sum + cost);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> n;

	int a, b;
	 
	
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;

		saver.push_back(make_pair(a, b));
	}

	DFS(0,0);

	cout << result;
}