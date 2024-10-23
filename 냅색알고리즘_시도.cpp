#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

int result = 0;
int n;
int bag;
vector<pair<int, int>> jewel;

void DFS(int digit, int space, vector<int> counter)
{
	int weight = jewel[digit].first;
	int value = jewel[digit].second;

	int max = space / weight;
	if (digit == 0)
	{
		counter[digit] = max;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += jewel[i].second * counter[i];
		}
		if (sum > result) result = sum;
		return;
	}
	int original_space = space;
	for (int i = max; i >= 0; i--)
	{
		counter[digit] = i;
		space = original_space - (weight * i);
		DFS(digit - 1, space, counter);
	}	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> bag;

	int a, b;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		jewel.push_back(make_pair(a, b));
	}
	sort(jewel.begin(), jewel.end());

	vector<int> counter(n);
	DFS(n - 1, bag, counter);

	cout << result;
} 