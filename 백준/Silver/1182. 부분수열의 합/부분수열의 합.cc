#include <deque>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> candidate;
vector<int> picked;
int n, r, s, answer = 0;

void dfs(int start, int depth)
{
    if (depth == r)
    {
        int res = 0;
        for (int x : picked)
        {
            res += x;
        }

        if (res == s)
            answer++;
        return;
    }

    for (int i = start; i < n; i++)
    {
        picked.push_back(candidate[i]);
        dfs(i + 1, depth + 1);
        picked.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, S;
    cin >> N >> S;
    candidate.assign(N, 0);
    picked.reserve(N);
    n = N;
    s = S;
    for (int i = 0; i < N; i++)
    {
        cin >> candidate[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        r = i; // nC1 ~ nCn

        dfs(0, 0);
    }
    cout << answer;
    return 0;
}
