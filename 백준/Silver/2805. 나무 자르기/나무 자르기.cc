#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, m;
vector<int> tree;

bool Check(int d)
{
    long long sum = 0;
    
    for(int i = 0; i < n; i++)
    {
        // d보다 큰거만 자름
        if (tree[i] > d)
        {
            sum += tree[i] - d;
        }

        if (sum >= m) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    tree.resize(n);

    for(int i = 0; i < n; i++)
        cin >> tree[i];

    sort(tree.begin(), tree.end());
    long long lo = 0;
    long long hi = tree.back();

    int ans = 0;
    while(lo <= hi)
    {
        long long mid = lo + (hi - lo) / 2;

        if(Check(mid))
        {
            // 가능
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    
    cout << ans;
    return 0;
}
