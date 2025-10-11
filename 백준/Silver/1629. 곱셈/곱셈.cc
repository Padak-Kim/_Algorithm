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

long long Pow(long long a, long long b, long long c)
{
	if (b == 0) return 1;
	if (b % 2 == 0)
	{
		long long half = Pow(a, b / 2, c);
		return half * half % c;
	}
	else
	{
		return a % c * Pow(a, b - 1, c) % c;
	}
}

int main()
{
	long long A, B, C;
	cin >> A >> B >> C;

	cout << Pow(A, B, C);
}