#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

int n, m;
vector<int> result(8);
vector<int> checker(8);

void  DFS(int counter, string& output)
{
	if (counter == m)
	{
		for (int i = 0; i < counter; i++)
		{
			output += to_string(result[i]) + " ";
		}
		output += "\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
	
		result[counter] = i + 1;
		DFS(counter + 1, output);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	result.resize(m);
	string output;

	DFS(0, output);
	cout << output;
}