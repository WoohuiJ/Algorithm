#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> saver(n);
	vector<int> dy(n);

	for (int i = 0; i < n; i++)
	{
		cin >> saver[i];
	}
	dy[0] = 1;
	if (saver[0] < saver[1])
	{
		dy[1] = 2;
	}
	else
	{
		dy[1] = 1;
	}
	int result = 0;
	for (int i = 2; i < n; i++)
	{
		int max = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (saver[i] > saver[j])
			{
				if (dy[j] > max) max = dy[j];

			}
			dy[i] = max + 1;
			if (dy[i] > result) result = dy[i];
		}
	}

	cout << result;
}