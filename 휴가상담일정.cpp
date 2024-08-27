#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
int result = 0;


void DFS(int counter, vector<pair<int, int>> saver, vector<int> checker)
{
	if (counter == n)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (checker[i] == 1)
			{
				sum += saver[i].second;
			}
		}
		if (sum > result)
		{
			result = sum;
		}
	}
	for (int i = counter; i < n; i++)
	{
		if (counter + saver[i].first <= n)
		{
			checker[i] = 1;
			DFS(i + saver[i].first, saver, checker);
		}
		else
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				if (checker[i] == 1)
				{
					sum += saver[i].second;
				}
			}
			if (sum > result)
			{
				result = sum;
			}
		}
		checker[i] = 0;
	}
}

int main()
{
	cin >> n;

	int t, p;
	vector<pair<int, int>> saver;
	vector<int> checker(n);

	for (int i = 0; i < n; i++)
	{
		cin >> t >> p;
		saver.push_back(make_pair(t, p));
	}

	DFS(0, saver, checker);

	cout << result;
}