#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

struct brick
{
	int length;
	int height;
	int weight;
	brick(int a, int b, int c)
	{
		length = a;
		height = b;
		weight = c;
	}

	bool operator < (const brick& b) const
	{
		return length < b.length;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<brick> saver;

	int a, b, c;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		saver.push_back(brick(a, b, c));
	}

	sort(saver.begin(), saver.end());

	int result = 0;

	vector<int> dy(n);

	dy[0] = saver[0].height;
	for (int i = 1; i < n; i++)
	{
		int max = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (saver[i].weight > saver[j].weight)
			{
				if (dy[j] > max)
				{
					max = dy[j];
				}
			}
			dy[i] = max + saver[i].height;
			if (dy[i] > result) result = dy[i];
		}
	}

	cout << result;
}