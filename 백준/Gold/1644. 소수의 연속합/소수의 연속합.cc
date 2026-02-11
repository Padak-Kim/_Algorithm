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
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 0;
    int n;
    cin >> n;

    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (!prime[i]) continue;

        for (int j = i * i; j <= n; j += i)
            prime[j] = false;
    }
    vector<int> p;
    p.reserve(n + 1);
    for (int i = 2; i <= n; i++) {
        if (prime[i])
            p.push_back(i);
    }
    int l = 0, r = 0;
    int sum = 0;
    while (true)
    {
        if (sum >= n)
        {
            if (sum == n) 
                cnt++;
            sum -= p[l++];
        }
        else
        {
            if (r == p.size())
                break;
            sum += p[r++];
        }
    }
    cout << cnt << "\n";
    return 0;
}