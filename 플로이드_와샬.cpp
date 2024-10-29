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
	vector<vector<int> > saver(n + 1, vector<int>(n + 1, 9999));

	for (int i = 1; i <= n; i++) saver[i][i] = 0;

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		saver[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				saver[i][j] = min(saver[i][j], saver[i][k] + saver[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (saver[i][j] == 9999)
			{
				cout << "M ";
			}
			else
			{
				cout << saver[i][j] <<" ";
			}
		}
		cout << endl;
	}

} 