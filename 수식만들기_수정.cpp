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

void DFS(vector<int> operat, const vector<int>& saver, int index, int result)
{
	if (index == n)
	{
		if (result < min_) min_ = result;
		if (result > max_) max_ = result;

		return;
	}
	else
	{
		if (operat[0] > 0)
		{
			operat[0]--;
			DFS(operat, saver, index + 1, result + saver[index]);
			operat[0]++;
		}
		if (operat[1] > 0)
		{
			operat[1]--;
			DFS(operat, saver, index + 1, result - saver[index]);
			operat[1]++;
		}
		if (operat[2] > 0)
		{
			operat[2]--;
			DFS(operat, saver, index + 1, result * saver[index]);
			operat[2]++;
		}
		if (operat[3] > 0)
		{
			operat[3]--;
			DFS(operat, saver, index + 1, result / saver[index]);
			operat[3]++;
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
	vector<int> operat(4);
	
	for (int i = 0; i < 4; i++)
	{
		cin >> operat[i];
	}

	DFS(operat, saver, 1, saver[0]);

	cout << max_ << endl << min_;
}