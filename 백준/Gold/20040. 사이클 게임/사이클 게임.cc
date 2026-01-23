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
vector<int> parent;

int find(int x)
{
    if (parent[x] == x) 
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b) return;

    parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        if (find(a) == find(b)) 
        {
            cout << i << "\n";
            return 0;
        }
        unite(a, b);
    }

    cout << 0 << "\n";


    return 0;
}