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

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        pq.push(num);
    }

    int ans = 0;
    while (!pq.empty() && pq.size() >= 2)
    {
        int num1 = pq.top(); pq.pop();
        int num2 = pq.top(); pq.pop();

        int sum = num1 + num2;

        ans += sum;
        pq.push(sum);
    }

    cout << ans;
    return 0;
}