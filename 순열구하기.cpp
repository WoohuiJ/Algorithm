#include <iostream>
#include <vector>

using namespace std;

vector<int> saver;
int result = 0;

void DFS(int n, int r, int counter, vector<bool> checker, vector<int> outcome)
{
	if (counter == r)
	{
		for (int i = 0; i < r; i++)
		{
			cout << outcome[i];
		}
		cout << endl;
		result++;
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (checker[i] == 0)
			{
				checker[i] = 1;
				outcome[counter] = saver[i];
				DFS(n, r, counter + 1, checker, outcome);
				checker[i] = 0;
			}
		}
	}
}

int main()
{
	int n, r;
	cin >> n >> r;

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		saver.push_back(num);
	}

	vector<bool> checker(n);
	vector<int> outcome(r);

	DFS(n, r, 0, checker, outcome);

	cout << result;
}