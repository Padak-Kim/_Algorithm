#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int N = triangle.size();

    // dp[y][x]: triangle[y][x]까지 내려왔을 때 최대 합
    vector<vector<int>> dp(N, vector<int>(N, 0));
    dp[0][0] = triangle[0][0];  // 시작점 초기화

    for (int y = 1; y < N; ++y) {
        for (int x = 0; x <= y; ++x) {
            if (x > 0)
                dp[y][x] = max(dp[y][x], dp[y - 1][x - 1] + triangle[y][x]);
            if (x < y)
                dp[y][x] = max(dp[y][x], dp[y - 1][x] + triangle[y][x]);
        }
    }

    // 마지막 줄에서 최대값 반환
    return *max_element(dp[N - 1].begin(), dp[N - 1].end());
}
