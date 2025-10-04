#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

struct DSU
{
private:
    vector<int> parent, size;

public:
    DSU(int n)
    {
		parent.resize(n + 1);
		size.resize(n + 1, 1);
		for (int i = 0; i <= n; i++)
			parent[i] = i;
    }
    int find(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);

        if (u == v)
        {
            cout << size[u] << endl;
            return;
        }
        if (size[u] > size[v])
            swap(u, v);

        parent[u] = v;
        size[v] += size[u];
        cout << size[v] << endl;
    }
};
int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        unordered_map<string, int> um;
        int F;
        cin >> F;
        int idx = 0;
        DSU dsu(F * 2);

        for (int j = 0; j < F; j++)
        {
            string a, b;
            cin >> a >> b;

            if (um.find(a) == um.end())
                um[a] = idx++;
            if (um.find(b) == um.end())
                um[b] = idx++;

            dsu.merge(um[a], um[b]);
        }
    }
    return 0;
}