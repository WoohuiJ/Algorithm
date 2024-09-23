//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <utility>
//
//using namespace std;
//
//void  DFS(int counter, int m, int max, vector<int> result, vector<int> checker)
//{
//	if (counter == m)
//	{
//		for (int i = 0; i < counter; i++)
//		{
//			cout << result[i] << " ";
//		}
//		cout << endl;
//	}
//	for (int i = 0; i < max; i++)
//	{
//		if (checker[i] == 0)
//		{
//			checker[i] = 1;
//			result[counter] = i + 1;
//			DFS(counter + 1, m, max, result, checker);
//			checker[i] = 0;
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int n, m;
//	cin >> n >> m;
//
//	vector<int> result(m);
//	vector<int> checker(n);
//
//	DFS(0, m, n, result, checker);
//}