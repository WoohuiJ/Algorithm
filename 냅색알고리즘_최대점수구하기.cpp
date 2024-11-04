#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> saver;
	vector<int> dy(m + 1, 0);
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		saver.push_back(make_pair(a, b));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = m; j - saver[i].second >= 0; j--)
		{
			dy[j] = max(dy[j], dy[j - saver[i].second] + saver[i].first);
		}
	}

	cout << dy[m];
} 