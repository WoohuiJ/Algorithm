#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int n;
int min_ = 1000000000;
int max_ = -1000000000;

void DFS(vector<int> order,  vector<bool> checker, const vector<int>& operat, const vector<int>& saver, int index)
{
	if (index == n - 1)
	{
		int result = saver[0];
		
		for (int i = 0; i < n - 1; i++)
		{
			switch (order[i])
			{
			case 0:
				result += saver[i + 1];
				break;
			case 1:
				result -= saver[i + 1];
				break;
			case 2:
				result *= saver[i + 1];
				break;
			case 3:
				result /= saver[i + 1];
				break;
			case -1:
				cout << "wrong" << endl;
			}
		}
		if (result < min_) min_ = result;
		if (result > max_) max_ = result;

		return;
	}

	for (int i = index; i < n - 1; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (checker[j] == false)
			{
				order[index] = operat[j];
				checker[j] = true;
				DFS(order, checker, operat, saver, index + 1);
				checker[j] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	vector<int> saver(n);
	for (int i = 0; i < n; i++)
	{
		cin >> saver[i];
	}
	vector<int> operat;
	int a;
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			operat.push_back(i);
		}		
	}

	vector<int> order(n - 1, -1);
	vector<bool> checker(n - 1, false);

	DFS(order, checker, operat, saver, 0);

	cout << max_ << endl << min_;
}