#include <iostream>
using namespace std;

long long p[100] = { 0 };
long long Dp(int n) 
{
	p[1] = p[2] = p[3] = 1;
	p[4] = p[5] = 2;
	
	if (n <= 5) {
		return p[n];
	}
	for (int i = 6; i <= n; i++) {
		p[i] = p[i - 5] + p[i - 1];
	}
	return p[n];
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		cout << Dp(n) << endl;
	}
}