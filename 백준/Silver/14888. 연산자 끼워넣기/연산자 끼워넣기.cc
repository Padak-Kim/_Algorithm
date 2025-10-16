#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <sstream>
using namespace std;

int minResult = INT_MAX;
int maxResult = INT_MIN;

void DFS(vector<int>& arr, vector<int>& visited, int idx, int res, int sumCnt, int subCnt, int mulCnt, int divCnt)
{
	int n = arr.size();
	
	if (idx == n)
	{
		minResult = min(minResult, res);
		maxResult = max(maxResult, res);
		return;
	}

	if (sumCnt > 0)
		DFS(arr, visited, idx + 1, res + arr[idx], sumCnt - 1, subCnt, mulCnt, divCnt);
	if (subCnt > 0)
		DFS(arr, visited, idx + 1, res - arr[idx], sumCnt, subCnt - 1, mulCnt, divCnt);
	if (mulCnt > 0)
		DFS(arr, visited, idx + 1, res * arr[idx], sumCnt, subCnt, mulCnt - 1, divCnt);
	if (divCnt > 0)
	{
		if (res < 0)
		{
			res = -res;
			res /= arr[idx];
			res = -res;
			DFS(arr, visited, idx + 1, res, sumCnt, subCnt, mulCnt, divCnt - 1);
		}
		else
			DFS(arr, visited, idx + 1, res / arr[idx], sumCnt, subCnt, mulCnt, divCnt - 1);
	}
}
int main() 
{
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> visited(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int sumCnt, subCnt, mulCnt, divCnt;
	cin >> sumCnt >> subCnt >> mulCnt >> divCnt;

	DFS(arr, visited, 1, arr[0], sumCnt, subCnt, mulCnt, divCnt);

	cout << maxResult << "\n" << minResult;
}