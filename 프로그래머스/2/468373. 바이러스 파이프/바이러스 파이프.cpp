#include <bits/stdc++.h>
using namespace std;

int n, k, infection;
vector<int> graph[3][101];
int answer = 0;

int countInfected(const vector<int>& infected) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += infected[i];
    return cnt;
}

vector<int> applyColor(const vector<int>& infected, int color) {
    vector<int> next = infected;
    queue<int> q;
    vector<int> visited(n + 1, 0);

    // 현재 감염된 노드 전체를 시작점으로
    for (int i = 1; i <= n; i++) {
        if (infected[i]) {
            q.push(i);
            visited[i] = 1;
        }
    }

    // 해당 color 간선만 따라 탐색
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        next[cur] = 1; // 이 턴 끝나면 감염됨

        for (int nxt : graph[color][cur]) {
            if (visited[nxt]) continue;
            visited[nxt] = 1;
            q.push(nxt);
        }
    }

    return next;
}

void dfs(int depth, int lastColor, vector<int> infected) {
    answer = max(answer, countInfected(infected));

    if (depth == k) return;

    for (int color = 0; color < 3; color++) {
        if (color == lastColor) continue; // 같은 색 연속은 무의미
        vector<int> next = applyColor(infected, color);

        // 변화가 없더라도 "최대 k번" 이라 탐색해도 되지만,
        // 가지치기해도 무방
        if (next == infected) continue;

        dfs(depth + 1, color, next);
    }
}

int solution(int N, int Infection, vector<vector<int>> edges, int K) {
    n = N;
    k = K;
    infection = Infection;
    answer = 1;

    for (int c = 0; c < 3; c++) {
        for (int i = 1; i <= n; i++) {
            graph[c][i].clear();
        }
    }

    for (auto &e : edges) {
        int x = e[0], y = e[1], type = e[2] - 1; // 0,1,2로 변환
        graph[type][x].push_back(y);
        graph[type][y].push_back(x);
    }

    vector<int> infected(n + 1, 0);
    infected[infection] = 1;

    dfs(0, -1, infected);
    return answer;
}