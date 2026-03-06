#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int dp[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    dp[0] = 1;
    for (int i = 1; i <= 10000; i++)
        dp[i] += dp[i - 1];
    
    for (int i = 2; i <= 10000; i++)
        dp[i] += dp[i - 2];

    for (int i = 3; i <= 10000; i++)
        dp[i] += dp[i - 3];

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;

        cout << dp[n] << endl;
    }

    return 0;
}