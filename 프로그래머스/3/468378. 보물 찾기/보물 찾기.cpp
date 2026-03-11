#include <vector>
#include <climits>

using namespace std;

extern int excavate(int);

int solution(vector<int> depth, int money) {
    int n = (int)depth.size();

    vector<int> cost(n + 1);
    for (int i = 1; i <= n; i++) 
        cost[i] = depth[i - 1];

    const long long INF = LLONG_MAX;

    // dp[l][r] = [l, r] 구간에 보물이 있다고 할 때
    //            무조건 찾기 위한 최소 "최악 비용"
    vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));

    // choice[l][r] = [l, r]에서 처음 파야 하는 최적 열
    vector<vector<int>> choice(n + 2, vector<int>(n + 2, 0));

    // 길이 1부터 증가시키며 DP
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            dp[l][r] = INF;

            for (int k = l; k <= r; k++) {
                long long left = (k > l) ? dp[l][k - 1] : 0;
                long long right = (k < r) ? dp[k + 1][r] : 0;
                long long cur = cost[k] + max(left, right);

                if (cur < dp[l][r]) {
                    dp[l][r] = cur;
                    choice[l][r] = k;
                }
            }
        }
    }

    // 문제에서 "100% 확률로 찾는 최소 비용 <= money" 가 보장되므로
    // 최적 전략(choice)을 따르면 money를 넘지 않는다. :contentReference[oaicite:1]{index=1}
    int l = 1, r = n;

    while (l <= r) {
        int k = choice[l][r];
        int res = excavate(k);

        if (res == 0) return k;       // 찾음
        else if (res == -1) r = k - 1; // 왼쪽에 있음
        else l = k + 1;               // 오른쪽에 있음
    }

    return 0; // 여기까지 오면 비정상
}