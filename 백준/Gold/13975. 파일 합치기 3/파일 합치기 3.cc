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
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int K;
        cin >> K;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int k = 0; k < K; k++)
        {
            int num;
            cin >> num;
            pq.push(num);
        }

        long long ans = 0;

        while (!pq.empty() && pq.size() >= 2)
        {
            long long num1 = pq.top(); pq.pop();
            long long num2 = pq.top(); pq.pop();

            long long sum = num1 + num2;

            pq.push(sum);
            ans += sum;
        }

        cout << ans << "\n";
    }
    return 0;
}