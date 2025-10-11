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
using namespace std;


int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> A(N+M);
	for (int i = 0; i < N + M; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	for (int i = 0; i < N + M; i++)
	{
		cout << A[i] << " ";
	}

}