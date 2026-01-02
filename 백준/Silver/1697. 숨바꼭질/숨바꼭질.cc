#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 200000
using namespace std;
int n, k;
int adjacent[MAX] = { 0, };
queue<int> q;
void Bfs(int here) 
{
	q.push(here);

	while (!q.empty()) {
		int num = q.front();
		q.pop();
		if (num == k) {

			cout << adjacent[k];
			break;
		}
		if ((num - 1) >= 0 && (num - 1) < MAX && adjacent[num - 1] == 0) {
			q.push(num - 1);
			adjacent[num - 1] = adjacent[num] + 1;
		}
		if ((num + 1) >= 0 && (num + 1) < MAX && adjacent[num + 1] == 0) {
			q.push(num + 1);
			adjacent[num + 1] = adjacent[num] + 1;
		}

		if ((num * 2) >= 0 && (num * 2) < MAX && adjacent[num * 2] == 0) {
			q.push(num * 2);
			adjacent[num * 2] = adjacent[num] + 1;
		}

	}
}
int main()
{
	cin >> n >> k;

	Bfs(n);

	return 0;
}

