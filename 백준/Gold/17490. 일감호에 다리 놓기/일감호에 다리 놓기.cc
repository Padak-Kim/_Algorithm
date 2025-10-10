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

struct DSU
{
	vector<int> parent, rank, size;

	DSU(int n) : parent(n), rank(n, 0), size(n, 1)
	{
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int a)
	{
		if (parent[a] == a)
			return a;

		return parent[a] = find(parent[a]);
	}

	void merge(int a, int b)
	{
		a = find(a);
		b = find(b);

		if (a == b)
			return;

		if (rank[a] > rank[b])
			swap(a, b);

		parent[a] = b;
		size[b] += size[a];

		if (rank[a] == rank[b])
			rank[b]++;

		return;
	}

	bool same(int a, int b)
	{
		return find(a) == find(b);
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M; long long K; // 강의동의 수 N, 공사구간의 수 M, 건덕이가 가진 돌의 수 K
	cin >> N >> M >> K;
	vector<long long> stone(N + 1); // 각 강의동에서 와우도까지 놓아야하는 돌의 개수

	for (int i = 1; i <= N; i++)
	{
		// 강의동에서 와우도까지 놓아야하는 돌의 개수
		cin >> stone[i];
	}
	
	unordered_map<int, vector<int>> broken;
	broken.reserve(M);

	for (int i = 0; i < M; i++)
	{
		int a, b; // a번 강의동에서 b번 강의동까지 공사중
		cin >> a >> b;
		broken[a].push_back(b);
		broken[b].push_back(a);
	}

	bool ok = true; // K개의 돌로 모든 강의동에서 와우도까지 갈 수 있는지 여부

	// 구현
	// 같은 팀끼리 union-find로 묶기
	DSU dsu(N + 1);
	for (int i = 1; i <= N; i++)
	{
		int next = (i == N) ? 1 : i + 1; // 다음 강의동
		bool isBroken = false; // i번 강의동과 next번 강의동이 공사중인지 여부
		// i번 강의동과 next번 강의동이 공사중이 아니면 union
		if (broken.count(i))
		{
			for (int nb : broken[i])
			{
				if (nb == next)
				{
					isBroken = true;
					break;
				}
			}
		}

		if (!isBroken)
			dsu.merge(i, next);
	}

	// 각 팀별로 필요한 돌의 최소 개수 구하기
	unordered_map<int, long long> team_stone;
	for (int i = 1; i <= N; i++)
	{
		int team = dsu.find(i);

		if (team_stone.find(team) == team_stone.end())
			team_stone[team] = stone[i];
		else
			team_stone[team] = min(team_stone[team], stone[i]);
	}

	if (team_stone.size() == 1)
	{
		// 모든 강의동이 하나의 팀으로 묶인 경우
		cout << "YES\n";
		return 0;
	}

	// 필요한 돌의 개수의 합이 K보다 작거나 같은지 확인
	long long total_stone = 0;
	for (auto& [team, need] : team_stone)
		total_stone += need;

	if (total_stone > K)
		ok = false;

	if (ok) 
		cout << "YES\n";
	else 
		cout << "NO\n";

	return 0;
}