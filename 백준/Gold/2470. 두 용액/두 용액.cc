#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<int> res(2, 0);

	sort(arr.begin(), arr.end());

	int left = 0; int right = n - 1;
	int minSum = 2000000001;
	while (left < right)
	{
		int sum = arr[left] + arr[right];
		if (sum == 0)
		{
			res[0] = arr[left];
			res[1] = arr[right];

			cout << res[0] << " " << res[1];
			return 0;
		}
		if (minSum > abs(sum))
		{
			minSum = abs(sum);
			res[0] = arr[left];
			res[1] = arr[right];
		}
		

		if (sum < 0) left++;
		else right--;

	}

	
	cout << res[0] << " " << res[1];
	return 0;
}