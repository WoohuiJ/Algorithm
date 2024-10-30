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

	int n;
	cin >> n;

	vector<int> coin(n);
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}

	int money;
	cin >> money;

	vector<int> dy(money +1 , 2147000000);

	dy[0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = coin[i]; j < money + 1; j++)
		{
			dy[j] = min(dy[j], dy[j - coin[i]] + 1);
		}
	}

	cout << dy[money];
} 